#include <unistd.h>
#include <stdio.h>

#include "../../../Utils/csapp.h"

void handler(int sig) {
    return;
}

void snooze(unsigned int secs) {
    unsigned int rc = sleep(secs);
    
    printf("Slept for %u of %u secs\n", secs - rc, secs);

    exit(0);
}

int main (int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: ./snooze <secs>\n");
        return 0;
    }

    if (signal(SIGINT, handler) == SIG_ERR) {
        unix_error("signal error");
    }

    snooze(atoi(argv[1]));

    pause();

    exit(0);
}