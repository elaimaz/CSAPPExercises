Exercise 3.55
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10 min*** :hourglass_flowing_sand:

---

### ***Question***:
The following code computes the product of x and y and stores the result in memory. Data type ll_t is defined to be equivalent to long long  _

```
typedef long long ll_t;

void store_prod(ll_t *dest, int z, ll_t y) {
    *dest = x*y;
}
```  

GCC generates the following assembly code implementing the computation:

```
    dest at %ebp+8, x at %ebp+12, y at %ebp+16
1       movl        16(%ebp), %esi
2       movl        12(%ebp), %eax
3       movl        %eax, %edx
4       sarl        $31, %edx
5       movl        20(%ebp), %ecx
6       imull       %eax, %ecx
7       movl        %edx, %ebx
8       imull       %esi, %ebx
9       addl        %ebx, %ecx
10      mull        %esi
11      leal        (%ecx, %edx), %edx
12      movl        8(%ebp), %ecx
13      movl        %eax, (%ecx)
14      movl        %edx, 4(%ecx)      
```

&nbsp;&nbsp;&nbsp;&nbsp;This code uses three multiplications to implement the multiprecision arithmetic required to implement 64-bit arithmetic on a 32 bit machine. Describe the algorithm used to compute the product, and annotate the assembly code to show how it realizes your algorithm. **Hint:** See Problem 3.12 solution.