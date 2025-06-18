Exercise 5.16
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
Write a version of the inner product procedure described in Problem 5.15 that uses four-way loop unrolling.  
&emsp;For x86-64, our measurements of the unrolled version give a CPE of 2.00 for integer data but still 3.00 for both single and double precision.  

1. Explain why any version of any inner product procedure cannot achieve a CPE less than 2.00.  
2. Explain why the performance for ﬂoating-point data did not improve with loop unrolling.  

---  

### ***Answear***:  
1. Because each iteration requires at least two memory accesses, so the minimum CPE is 2.00.  
2. Because floating-point addition has a longer latency and creates a dependency chain, preventing parallel execution even with loop unrolling.  

