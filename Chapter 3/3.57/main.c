#include "assert.h"
#include "stddef.h"

int cread(int *xp) {
    return (xp ? *xp : 0);
}

int cread_alt(int *xp) {
    int returnValue = 0;

    if (*xp != NULL) returnValue = *xp;

    return returnValue;
}

int main(){
    int test = 5;
    assert(test == cread_alt(&test));

    test = NULL;
    assert(0 == cread_alt(&test));
    

    return 0;
}