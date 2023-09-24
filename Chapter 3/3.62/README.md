Exercise 3.62
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
The following code transposes the elements of an M x M array, where M is a constant defined by #define:  

```
void transpose(Marray_t A) {
    int i, j;
    for (i = 0; i < M; i++)
        for (j = 0; j < i; j++) {
            int t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
}
```  

When compiled with optimization level -O2 GCC generates following code for the inner loop of the function:  

```
1   .L3
2       movl        (%ebp), %eax
3       movl        (%esi, %ecx, 4), %edx
4       movl        %eax, (%esi, %ecx, 4)
5       addl        $1, %ecx
6       movl        %edx, (%ebx)
7       addl        $52, %ebx
8       cmpl        %edi, %ecx
9       j1          .L3
```  

1. What is the value of M?
2. What registers hold program values i and j?
3. Write a C code version of transpose that makes use of the optimization that occur in this loop. Use the parameter M in your code rather than numeric constants.  

---

### ***Answer***:  

1. 13
2. i at edi and j at ecx.  
3. [Code](./main.c)