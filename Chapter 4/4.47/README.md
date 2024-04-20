Exercise 4.47
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
in our example Y86 programs, such as the Sum function shown in Figure 4.6, we encounter many cases (e.g., lines 12 and 13 and lines 14 and 15) in which we want to add a constant value to a register. This requires first using an irmovl instruction to set a register to the constant, and then an addl instruction to add this value to the destination register. Suppose we want to add a new instruction iaddl with the following format:  

Byte &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;0&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;1&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2&nbsp;&nbsp;&nbsp;&nbsp;3&nbsp;&nbsp;&nbsp;&nbsp;4&nbsp;&nbsp;&nbsp;&nbsp;5  

iaddl V, rB&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|C|0|F|rB|&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;V&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;|  

This instruction adds the constant value V to register rB. Describe the computations performed to implement this instruction. Use computations for irmovl and OPL(Figure 4.18) as a guide.

---  

### ***Answear***:  
