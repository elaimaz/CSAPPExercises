Exercise 5.15
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Suppose we wish to write a procedure that computes the inner product of two vectors u and v. An abstract version of the function has a CPE of 16–17 with x86-64 and 26–29 with IA32 for integer, single-precision, and double-precision data. By doing the same sort of transformations we did to transform the abstract program combine1 into the more efﬁcient combine4, we get the following code:  

```c
1   /* Accumulate in temporary */
2   void inner4(vec_ptr u, vec_ptr v, data_t *dest)
3   {
4       long int i;
5       int length = vec_length(u);
6       data_t *udata = get_vec_start(u);
7       data_t *vdata = get_vec_start(v);
8       data_t sum = (data_t) 0;
9
10      for (i = 0; i < length; i++) {
11          sum = sum + udata[i] * vdata[i];
12      }
13      *dest = sum;
14  }
```  

Our measurements show that this function has a CPE of 3.00 for integer and ﬂoating-point data. For data type float, the x86-64 assembly code for the inner loop is as follows:  

```àsm
    inner4: data_t = float
    udata in %rbx, vdata in %rax, limit in %rcx,
    i in %rdx, sum in %xmm1
1   .L87                               loop:
2       movss   (%rbx,%rdx,4),  %xmm0   Get udata[i]
3       mulss   (%rax,%rdx,4),  %xmm0   Multiply by vdata[i]
4       addss   %xmm0,          %xmm1   Add to sum
5       addq    $1,             %rdx    Increment i
6       cmpq    %rcx,           %rdx    Compare i:limit
7       jl      .L87                    If <, goto loop
```  

&emsp;Assume that functional units have the characteristics listed in Figure 5.12.  
1. Diagram how this instruction sequence would be decoded into operations and show how the data dependencies between then would create a critical path of operations, in the styla of Figures 5.13 and 5.14.  
2. For data type float, what lower bound on the CPE is determined by the critical path?  
3. Assuming similar instruction sequences for the integer code as well, what lower bound on the CPE is determined by the critical path for integer data?  
4. Explain how the two floating-point versions can have CPEs of 3.00, even though the multiplication operation requires either 4 or 5 clock cycles.  

---  

### ***Answear***:  
1. 
  - ![Diagramm](./5.15.drawio.svg)
