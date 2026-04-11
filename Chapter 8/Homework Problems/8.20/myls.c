#include "../../../Utils/csapp.h"

int main(int argc, char *argv[], char *envp[])
{
    pid_t pid = fork();
    if (pid == 0) {
        int ret = execve("/bin/ls", argv, envp);
        if (ret == -1) {
            fprintf(stderr, "execve error\n");
        }
        exit(1);
    }
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        exit(WEXITSTATUS(status));
    
    exit(0);
}
