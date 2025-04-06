### ***Practice Problem 5.11***:
We saw that our measurements of the preﬁx-sum function psum1 (Figure 5.1) yield a CPE of 10.00 on a machine where the basic operation to be performed, ﬂoating point addition, has a latency of just 3 clock cycles. Let us try to understand why our function performs so poorly.  
&emsp;The following is the assembly code for the inner loop of the function:

```asm
    psum1.  a in %rdi, p in %rsi, i in %rax, cnt in %rdx
1   .L5:                                loop:
2       movss   -4(%rsi,%rax,4), %xmm0      Get p[i-1]
3       addss   (%rdi,%rax,4), %xmm0        Add a[i]
4       movss   %xmm0, (%rsi,%rax,4)        Store at p[i]
5       addq    $1, %rax                    Increment i
6       cmpq    %rax, %rdx                  Compare cnt:i
7       jg      .L5                         If >, goto loop
```  

&emsp;Perform an analysis similar to those shown for combine3 (Figure 5.14) and for write_read (Figure 5.36) to diagram the data dependencies created by this loop, and hence the critical path that forms as the computation proceeds.  
&emsp;Explain why the CPE is so high. (You may not be able to justify the exact CPE, but you should be able to describe why it runs more slowly than one might expect.)


---  

### ***Answear***:  
Beucause of the write/read dependency. As can be seen on the diagram  


![diagram](./Practice%20Problem%205.11.drawio.png)