Exercise 4.43
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
in section 3.4.2, the IA32 popl instruction was described as copying the result from the top of the stack to the destination register and then incrementing the stack pointer. So if we had an instruction of the form popl *REG*, it would be equivalent to the code sequence:  

```
movl	(%esp), REG		read REG from stack
addl	$4, %esp		increment stack pointer
```  

1. In light of analysis done in Problem 4.7, does this code sequence correctly describe the behavior of the instruction popl %esp? Explain.
2. How could you rewrite the code sequence so that it correctly describes both the cases where REG is %esp as well as any other register? 

---  

### ***Answear***:  

1. Yes, it decrements by 4 and then writes a register value into memory, unless REG is %esp, then it will not work.  
2. [main.c](./main.c).


