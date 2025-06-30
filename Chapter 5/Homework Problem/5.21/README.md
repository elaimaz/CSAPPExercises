Exercise 5.21
==============

### ***Dificulty***: :star: :star: :star:   

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
In Problem 5.12, we were able to reduce the CPE for the preﬁx-sum computation to 3.00, limited by the latency of ﬂoating-point addition on this machine. Simple loop unrolling does not improve things.  
&emsp;Using a combination of loop unrolling and reassociation, write code for preﬁx sum that achieves a CPE less than the latency of ﬂoating-point addition on your machine. Doing this requires actually increasing the number of additions performed. For example, our version with two-way unrolling requires three additions per iteration, while our version with three-way unrolling requires ﬁve.  

---  

### ***Answear***:   
[main.c](./main.c).  

For N = 10000  
- psum1 cycles: 8
- psum1a cycles: 12
- psum1a_enhanced cycles: 10
