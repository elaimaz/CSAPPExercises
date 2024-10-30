Exercise 4.48
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
As described in Section 3.7.2, the IA32 instruction leave can be used to prepare the stack for returning. It is equivalent to the following Y86 code sequence:  
```
1   rrmovl  %ebp, %esp  # Set stack pointer to beginning of frame
2   popl    %ebp        # Restore saved %ebp and set stack ptr to end of caller’s frame
```  
Suppose we add this instruction to the Y86 instruction set, using the following encoding:  
Byte &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;3&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;4&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;5  

leave &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|D|0|  

Describe the computations performed to implement this instruction. Use the computations for popl (Figure 4.20) as a guide.

---  

### ***Answear***:  
| Stage | leave D, 0 |
| :---: | :---: |
| Fetch | icode:ifun <-- M1[PC]|
| Fetch | rA:rB <-- M1[PC + 1]|
| Fetch | valP <-- PC + 2|  
| Decode | valA <-- R[%ebp]|
| Decode | valB <-- R[%esp]|
| Execute | valE <-- valB + 4|
| Memory | valM <-- M4[valB] |
| Write back | R[%esp] <-- valA |
| Write back | R[rB] <-- valM |
| PC update | PC <-- valP |
