Exercise 4.51
==============

### ***Dificulty***: :star: :star: :star:

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
Suppose we wanted to create a lower-cost pipelined processor based on the structure we devised for PIPE– (Figure 4.41), without any bypassing. This design would handle all data dependencies by stalling until the instruction generating a needed value has passed through the write-back stage. The ﬁle pipe-stall.hcl contains a modiﬁed version of the HCL code for PIPE in which the bypassing logic has been disabled. That is, the signals e_valA and e_valB are simply declared as follows:  

```
## DO NOT MODIFY THE FOLLOWING CODE.
## No forwarding. valA is either valP or value from register file
int d_valA = [
    D_icode in { ICALL, IJXX } : D_valP; # Use incremented PC
    1 : d_rvalA; # Use value read from register file
];

## No forwarding. valB is value from register file
int d_valB = d_rvalB;
```  

Modify the pipeline control logic at the end of this ﬁle so that it correctly handles all possible control and data hazards. As part of your design effort, you should analyze the different combinations of control cases, as we did in the design of the pipeline control logic for PIPE. You will ﬁnd that many different combinations can occur, since many more conditions require the pipeline to stall. Make sure your control logic handles each combination correctly. See the lab material for directions on how to generate a simulator for your solution and how to test it.

---  

### ***Answear***:  
Did not find file.