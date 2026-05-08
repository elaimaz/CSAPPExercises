#include "../../../Utils/csapp.h"

#define MAXARGS 128
#define MAXJOBS 16

#define UNDEF 0
#define FG    1
#define BG    2
#define ST    3

typedef struct job {
    pid_t pid;
    int jid;
    int state;
    char cmdline[MAXLINE];
} job_t;

static job_t jobs[MAXJOBS];
static int nextjid = 1;
static sigset_t mask_all;
static volatile sig_atomic_t fg_pid = 0;

static void eval(char *cmdline);
static int parseline(char *buf, char **argv);
static int builtin_command(char **argv);
static void do_bgfg(char **argv);
static void waitfg(pid_t pid);

static void clearjob(job_t *job);
static void initjobs(void);
static int addjob(pid_t pid, int state, const char *cmdline);
static int deletejob(pid_t pid);
static job_t *getjobpid(pid_t pid);
static job_t *getjobjid(int jid);
static int pid2jid(pid_t pid);
static void listjobs(void);

static void sigchld_handler(int sig);
static void sigint_handler(int sig);
static void sigtstp_handler(int sig);

static int all_digits(const char *s);
static const char *state_string(int state);
static const char *signal_name(int sig);
static int command_has_ampersand(const char *cmdline);
static void print_command(const char *cmdline, int state);
static void safe_puts(const char *s);
static void safe_putl(long v);

int main(void)
{
    char cmdline[MAXLINE];

    Sigfillset(&mask_all);
    initjobs();

    Signal(SIGCHLD, sigchld_handler);
    Signal(SIGINT, sigint_handler);
    Signal(SIGTSTP, sigtstp_handler);

    while (1) {
        printf("> ");
        fflush(stdout);

        if (Fgets(cmdline, MAXLINE, stdin) == NULL) {
            if (feof(stdin)) {
                printf("\n");
                exit(0);
            }
            continue;
        }

        eval(cmdline);
        fflush(stdout);
    }
}

static void eval(char *cmdline)
{
    char *argv[MAXARGS];
    char buf[MAXLINE];
    int bg;
    pid_t pid;
    sigset_t mask_chld, prev_mask;

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
        return;

    if (builtin_command(argv))
        return;

    Sigemptyset(&mask_chld);
    Sigaddset(&mask_chld, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask_chld, &prev_mask);

    if ((pid = Fork()) == 0) {
        Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
        Setpgid(0, 0);

        if (execve(argv[0], argv, environ) < 0) {
            printf("%s: Command not found.\n", argv[0]);
            fflush(stdout);
            exit(1);
        }
    }

    if (setpgid(pid, pid) < 0 && errno != EACCES && errno != ESRCH)
        unix_error("setpgid error");

    Sigprocmask(SIG_BLOCK, &mask_all, NULL);
    addjob(pid, bg ? BG : FG, cmdline);
    if (!bg)
        fg_pid = pid;
    Sigprocmask(SIG_SETMASK, &prev_mask, NULL);

    if (!bg) {
        waitfg(pid);
    } else {
        printf("[%d] %d ", pid2jid(pid), pid);
        print_command(cmdline, BG);
        printf("\n");
    }
}

static int parseline(char *buf, char **argv)
{
    char *delim;
    int argc = 0;
    int bg = 0;

    buf[strcspn(buf, "\n")] = ' ';
    while (*buf && *buf == ' ')
        buf++;

    while ((delim = strchr(buf, ' ')) != NULL) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && *buf == ' ')
            buf++;
    }
    argv[argc] = NULL;

    if (argc == 0)
        return 0;

    if (!strcmp(argv[argc - 1], "&")) {
        bg = 1;
        argv[--argc] = NULL;
    }

    return bg;
}

static int builtin_command(char **argv)
{
    sigset_t prev_mask;

    if (!strcmp(argv[0], "quit"))
        exit(0);

    if (!strcmp(argv[0], "&"))
        return 1;

    if (!strcmp(argv[0], "jobs")) {
        Sigprocmask(SIG_BLOCK, &mask_all, &prev_mask);
        listjobs();
        Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
        return 1;
    }

    if (!strcmp(argv[0], "bg") || !strcmp(argv[0], "fg")) {
        do_bgfg(argv);
        return 1;
    }

    return 0;
}

static void do_bgfg(char **argv)
{
    char *command = argv[0];
    char *id = argv[1];
    job_t *job = NULL;
    sigset_t prev_mask;

    if (id == NULL) {
        printf("%s command requires PID or %%jobid argument\n", command);
        return;
    }

    Sigprocmask(SIG_BLOCK, &mask_all, &prev_mask);

    if (id[0] == '%') {
        if (!all_digits(id + 1)) {
            printf("%s: argument must be a PID or %%jobid\n", command);
            Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
            return;
        }
        job = getjobjid(atoi(id + 1));
        if (job == NULL) {
            printf("%s: No such job\n", id);
            Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
            return;
        }
    } else {
        if (!all_digits(id)) {
            printf("%s: argument must be a PID or %%jobid\n", command);
            Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
            return;
        }
        job = getjobpid((pid_t)atoi(id));
        if (job == NULL) {
            printf("%s: No such process\n", id);
            Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
            return;
        }
    }

    if (!strcmp(command, "bg")) {
        job->state = BG;
        Kill(-job->pid, SIGCONT);
        printf("[%d] %d ", job->jid, job->pid);
        print_command(job->cmdline, BG);
        printf("\n");
        Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
        return;
    }

    job->state = FG;
    fg_pid = job->pid;
    Kill(-job->pid, SIGCONT);
    Sigprocmask(SIG_SETMASK, &prev_mask, NULL);
    waitfg(job->pid);
}

static void waitfg(pid_t pid)
{
    sigset_t empty;

    Sigemptyset(&empty);
    while (fg_pid == pid)
        sigsuspend(&empty);
}

static void clearjob(job_t *job)
{
    job->pid = 0;
    job->jid = 0;
    job->state = UNDEF;
    job->cmdline[0] = '\0';
}

static void initjobs(void)
{
    int i;

    for (i = 0; i < MAXJOBS; i++)
        clearjob(&jobs[i]);
}

static int maxjid(void)
{
    int i;
    int max = 0;

    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].jid > max)
            max = jobs[i].jid;

    return max;
}

static int addjob(pid_t pid, int state, const char *cmdline)
{
    int i;

    if (pid < 1)
        return 0;

    for (i = 0; i < MAXJOBS; i++) {
        if (jobs[i].pid == 0) {
            jobs[i].pid = pid;
            jobs[i].jid = nextjid++;
            if (nextjid > MAXJOBS)
                nextjid = 1;
            jobs[i].state = state;
            strncpy(jobs[i].cmdline, cmdline, MAXLINE - 1);
            jobs[i].cmdline[MAXLINE - 1] = '\0';
            jobs[i].cmdline[strcspn(jobs[i].cmdline, "\n")] = '\0';
            return 1;
        }
    }

    printf("Tried to create too many jobs\n");
    return 0;
}

static int deletejob(pid_t pid)
{
    int i;

    if (pid < 1)
        return 0;

    for (i = 0; i < MAXJOBS; i++) {
        if (jobs[i].pid == pid) {
            clearjob(&jobs[i]);
            nextjid = maxjid() + 1;
            return 1;
        }
    }

    return 0;
}

static job_t *getjobpid(pid_t pid)
{
    int i;

    if (pid < 1)
        return NULL;

    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].pid == pid)
            return &jobs[i];

    return NULL;
}

static job_t *getjobjid(int jid)
{
    int i;

    if (jid < 1)
        return NULL;

    for (i = 0; i < MAXJOBS; i++)
        if (jobs[i].jid == jid)
            return &jobs[i];

    return NULL;
}

static int pid2jid(pid_t pid)
{
    job_t *job = getjobpid(pid);

    return job == NULL ? 0 : job->jid;
}

static void listjobs(void)
{
    int i;

    for (i = 0; i < MAXJOBS; i++) {
        if (jobs[i].pid == 0 || jobs[i].state == FG)
            continue;

        printf("[%d] %d %s ", jobs[i].jid, jobs[i].pid,
               state_string(jobs[i].state));
        print_command(jobs[i].cmdline, jobs[i].state);
        printf("\n");
    }
}

static void sigchld_handler(int sig)
{
    int olderrno = errno;
    int status;
    pid_t pid;
    job_t *job;

    (void)sig;

    while ((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0) {
        job = getjobpid(pid);

        if (WIFSTOPPED(status)) {
            if (job != NULL)
                job->state = ST;
            if (fg_pid == pid)
                fg_pid = 0;

            safe_puts("Job [");
            safe_putl(job == NULL ? 0 : job->jid);
            safe_puts("] ");
            safe_putl(pid);
            safe_puts(" stopped by signal: ");
            safe_puts(signal_name(WSTOPSIG(status)));
            safe_puts("\n");
        } else if (WIFSIGNALED(status)) {
            if (fg_pid == pid)
                fg_pid = 0;

            safe_puts("Job ");
            safe_putl(pid);
            safe_puts(" terminated by signal: ");
            safe_puts(signal_name(WTERMSIG(status)));
            safe_puts("\n");
            deletejob(pid);
        } else if (WIFEXITED(status)) {
            if (fg_pid == pid)
                fg_pid = 0;
            deletejob(pid);
        }
    }

    errno = olderrno;
}

static void sigint_handler(int sig)
{
    pid_t pid = (pid_t)fg_pid;

    (void)sig;

    if (pid > 0)
        kill(-pid, SIGINT);
}

static void sigtstp_handler(int sig)
{
    pid_t pid = (pid_t)fg_pid;

    (void)sig;

    if (pid > 0)
        kill(-pid, SIGTSTP);
}

static int all_digits(const char *s)
{
    if (s == NULL || *s == '\0')
        return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s))
            return 0;
        s++;
    }

    return 1;
}

static const char *state_string(int state)
{
    switch (state) {
    case BG:
        return "Running";
    case ST:
        return "Stopped";
    case FG:
        return "Foreground";
    default:
        return "Undefined";
    }
}

static const char *signal_name(int sig)
{
    switch (sig) {
    case SIGINT:
        return "Interrupt";
    case SIGTSTP:
        return "Stopped";
    case SIGTERM:
        return "Terminated";
    case SIGQUIT:
        return "Quit";
    case SIGKILL:
        return "Killed";
    case SIGSEGV:
        return "Segmentation fault";
    case SIGABRT:
        return "Aborted";
    default:
        return "Unknown signal";
    }
}

static int command_has_ampersand(const char *cmdline)
{
    size_t len = strlen(cmdline);

    while (len > 0 && isspace((unsigned char)cmdline[len - 1]))
        len--;

    return len > 0 && cmdline[len - 1] == '&';
}

static void print_command(const char *cmdline, int state)
{
    size_t len = strcspn(cmdline, "\n");

    while (len > 0 && isspace((unsigned char)cmdline[len - 1]))
        len--;

    printf("%.*s", (int)len, cmdline);
    if (state == BG && !command_has_ampersand(cmdline))
        printf(" &");
}

static void safe_puts(const char *s)
{
    size_t len = 0;

    while (s[len] != '\0')
        len++;

    (void)write(STDOUT_FILENO, s, len);
}

static void safe_putl(long v)
{
    char buf[32];
    int i = 0;
    int neg = 0;

    if (v == 0) {
        safe_puts("0");
        return;
    }

    if (v < 0) {
        neg = 1;
        v = -v;
    }

    while (v > 0 && i < (int)sizeof(buf)) {
        buf[i++] = (char)('0' + (v % 10));
        v /= 10;
    }

    if (neg)
        buf[i++] = '-';

    while (i > 0)
        (void)write(STDOUT_FILENO, &buf[--i], 1);
}
