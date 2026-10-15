// #include "csapp.h"
#include "../../../Utils/csapp.c"

int main (int argc, char **argv, char **envp)       
{
    if (Fork() == 0) { /* Child */
        /* What code is the shell executing right here? */
        int fd = Open("foo.txt", O_RDONLY, 0);
        printf("Child: Executing fstatcheck with fd %d\n", fd);
        Execve("fstatcheck", argv, envp);
        Close(fd);
    }
}
