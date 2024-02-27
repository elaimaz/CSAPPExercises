Exercise 4.43
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
in section 3.4.2, the IA32 pushl instruction was described as decrementing the stack pointer and then storing the register at the stack pointer location. So if we had an instruction of the form pushl REG, for some register REG, it would be equivalent to the code sequence:  

```
subl	$4, %esp		Decrement stack pointer
movl	REG, (%esp)		Store REG on stack
```  

1. In light of analysis done in Problem 4.6, does this code sequence correctly describe the behavior of the instruction pushl %esp? Explain.
2. How could you rewrite the code sequence so that it correctly describes both the cases where REG is %esp as well as any other register? 

---  

### ***Answear***:  

1. Yes, it decrements by 4 and then writes a register value into memory.  
2. It does not need to change, if REG is referencing %esp old value.


