#include <stdio.h>

void myecho(char *argv[], char *envp[]) {
    printf("Command line arguments:\n");
    for (int i = 0; argv[i] != NULL; i++) {
        printf("\t\targv[%d]: %s\n", i, argv[i]);
    }

    printf("\nEnvironment variables:\n");
    for (int i = 0; envp[i] != NULL; i++) {
        printf("\t\tenvp[%d]: %s\n", i, envp[i]);
    }

}

int main(int argc, char *argv[], char *envp[]) {
    myecho(argv, envp);

    return 0;
}