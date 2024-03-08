// Compiled with: gcc -m32 main.c -o main

#include <assert.h>

void pushl_registers()
{
    int *esp_before, *esp_after;
    int REG = 10;
    asm(
        "movl %%esp, %0\n\t"
        "subl $4, %%esp\n\t"
        "movl %2, (%%esp)\n\t"
        "movl %%esp, %1"
        :"=m" (esp_before), "=m" (esp_after)
        :"r" (REG)
    );

    assert((esp_before - esp_after) * sizeof(int*) == 4);
    assert(*(esp_after) == REG);
}

void pushl_esp()
{
    int REG, *esp_before, *esp_after;

    // Testing REG as %esp
    asm(
        "movl %%esp, %0\n\t"
        "movl %%esp, %1\n\t"
        "cmpl %%esp, %0\n\t"
        "je 1f\n\t"
        "subl $4, %%esp\n"
        "1: movl %0, (%%esp)\n\t"
        "movl %%esp, %2"
        :"=r" (REG), "=m" (esp_before), "=m" (esp_after)
    );

    assert(esp_after - esp_before == 0);

    // Testing REG as another register
    asm(
        "movl $10, %%eax\n\t"
        "movl %%eax, %0\n\t"
        "movl %%esp, %1\n\t"
        "cmpl %%esp, %0\n\t"
        "je 1f\n\t"
        "subl $4, %%esp\n"
        "1: movl %0, (%%esp)\n\t"
        "movl %%esp, %2"
        :"=r" (REG), "=m" (esp_before), "=m" (esp_after)
    );

    assert((esp_before - esp_after) * sizeof(int*) == 4);
    assert(10 == REG);
    assert(*(esp_after) == REG);

}

int main()
{
    pushl_registers();

    pushl_esp();

    return 0;
}