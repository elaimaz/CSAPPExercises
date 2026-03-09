Exercise 7.11
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:

The segment header in Figure 7.12 indicates that the data segment occupies 0x104 bytes in memory. However, only the ﬁrst 0xe8 bytes of these come from the sections of the executable ﬁle. What causes this discrepancy?  

---  

### ***Answear***:  
The difference is caused by the .bss section. The .bss section contains uninitialized global and static variables. These variables occupy space in memory but do not occupy space in the executable file.  
