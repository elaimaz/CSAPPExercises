// Compiled with: gcc -m32 main.c -o main

#include <assert.h>

void popl_registers()
{
    int REG, *esp;
    asm(
        "movl $10, %%eax\n\t"
        "pushl %%eax\n\t"
        "movl (%%esp), %0\n\t"
        "addl $4, %%esp\n\t"
        "movl %%esp, %1"
        :"=r" (REG), "=m" (esp)
    );

    assert(REG == 10);
    assert(&REG != esp);
    assert((&REG - esp) * sizeof(int*) == 4);
}

void popl_esp()
{
    int REG, *esp_before, *esp_after;
    
    // Testing REG as %esp
    asm(
        "movl (%%esp), %0\n\t"
        "movl %%esp, %1\n\t"
        "cmpl %%esp, %0\n\t"
        "je 1f\n\t"
        "addl $4, %%esp\n"
        "1: movl %%esp, %2"
        : "=r" (REG), "=m" (esp_before), "=m" (esp_after)
    );

    assert((esp_after - esp_before) * sizeof(int*) == 4);

    // Testing REG as %esp
    asm(
        "pushl $10\n\t"
        "movl (%%esp), %0\n\t"
        "movl %%esp, %1\n\t"
        "cmpl %%esp, %0\n\t"
        "je 1f\n\t"
        "addl $4, %%esp\n"
        "1: movl %%esp, %2"
        : "=r" (REG), "=m" (esp_before), "=m" (esp_after)
    );

    assert(REG == 10);
    assert((esp_after - esp_before) * sizeof(int*) == 4);
}

int main()
{
    popl_registers();

    popl_esp();

    return 0;
}