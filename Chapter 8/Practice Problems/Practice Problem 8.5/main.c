#include <unistd.h>
#include <stdio.h>

unsigned int snooze(unsigned int secs) {
    unsigned int rc = sleep(secs);
    
    printf("Slept for %u of %u secs\n", secs - rc, secs);

    return rc;
}

int main () {

    snooze(5);

    return 0;
}