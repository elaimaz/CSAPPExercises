#include "../../../Utils/csapp.h"

static void handler(int sig)
{
    (void)sig;
}

char *tfgets(char *buf, int n, FILE *fp)
{
    struct sigaction action = {0};

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGALRM, &action, NULL);

    alarm(5);
    char* result = fgets(buf, n, fp);
    alarm(0);

    return result;
}

int main(void)
{
    char buf[64];

    if (tfgets(buf, sizeof(buf), stdin) == NULL) {
        printf("No input received within 5 seconds\n");
        exit(0);
    }

    printf("buffer: %s", buf);
    exit(0);
}
