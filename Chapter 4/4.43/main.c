// Compiled with: gcc -m32 main.c -o main

#include <stdio.h>
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

    printf("esp_before: %d\nesp_after: %d\n", *(esp_before), *(esp_after));
    printf("esp_before: %p\nesp_after: %p\n", esp_before, esp_after);
    printf("Memory difference: %d\n", (esp_before - esp_after) * sizeof(int*));

    assert((esp_before - esp_after) * sizeof(int*) == 4);
    assert(*(esp_after) == REG);
}

void pushl_esp()
{
    asm(
        "subl $4, %esp\n\t"
        "movl %esp, (%esp)"
    );
}

int main()
{
    // pushl_registers();

    pushl_esp();

    return 0;
}