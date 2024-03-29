Exercise 3.56
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following assembly code:

```
    x at %ebp+8, n at %ebp+12
1       movl        8(%ebp), %esi
2       movl        12(%ebp), %ebx
3       movl        $-1, %edi
4       movl        $1, %edx
5   .L2:
6       movl        %edx, %eax
7       andl        %esi, %eax
8       xorl        %eax, %edi
9       movl        %ebx, %ecx
10      sall        %cl, %edx
11      testl       %edx, %edx
12      jne         .L2
13      movl        %edi, %eax   
```

The preceding code was generated by compiling C code that had the following overall form:

```
int loop(int x, int n)
{
    int result = ________;
    int mask;
    for (mask = ________; mask ________; mask = ________) {
        result ^= ________;
    }
    return result;
}
```

&nbsp;&nbsp;&nbsp;&nbsp;Your task is to fill in the missing parts of the C code to get a program equivalent to the generated assembly code. Recall that the result of the function is returned in register %eax. You will find it helpful to examine the assembly code before, during, and after the loop to form a consistent mapping between the registers and the program variables.  

1. Which registers hold program values x, n, result, and mask?
2. What are the initial values of result and mask?
3. What is the test condition for mask?
4. How does mask get updated?
5. How does result get updated?
6. Fill in all the missing parts of the C code.

---

### ***Answer***:

```
    x at %ebp+8, n at %ebp+12
1       movl        8(%ebp), %esi   ;move x to %esi
2       movl        12(%ebp), %ebx  ;move n to %ebx
3       movl        $-1, %edi       ;move -1 to %edi (result)
4       movl        $1, %edx        ;move 1 to %edx(mask)
5   .L2:
6       movl        %edx, %eax      ;move %edx(mask) to %eax
7       andl        %esi, %eax      ;%eax(mask) = %eax(mask) & %esi(x)
8       xorl        %eax, %edi      ;%edi(result) = %edi(result) ^ %eax(mask)
9       movl        %ebx, %ecx      ;move %ebx(n) to %ecx
10      sall        %cl, %edx       ;%edx(mask) = %edx(mask) << %cl(n)
11      testl       %edx, %edx      ;%edx(mask) & %edx(mask)
12      jne         .L2             ;jump if not zero
13      movl        %edi, %eax      ;move %edi(result) to %eax
```  

1. x at esi, n at ebx, result at edi and eax and mask at edx.
2. result = -1. mask = 1.
3. Test if mask is not zero
4. With a left-shift using n
5. result ^= (mask & x)
6. 
```
int loop(int x, int n)
{
    int result = -1;
    int mask;
    for (mask = 1; mask != 0; mask = mask << (char)n) {
        result ^= (mask & x)
    }
    return result;
}
```
