Exercise 5.17
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
Write a version of the inner product procedure described in Problem 5.15 that uses four-way loop unrolling with four parallel accumulators. Our measurements for this function with x86-64 give a CPE of 2.00 for all types of data.  

1. What factor limits the performance to a CPE of 2.00?    
2. Explain why the version with integer data on IA32 achieves a CPE of 2.75, worse than the CPE of 2.25 achieved with just four-way loop unrolling.  

---  

### ***Answear***:   
1. The performance is limited by the processor’s ability to perform memory loads. Even though arithmetic operations can be parallelized, the processor can only perform a limited number of loads per cycle (typically two), so the memory subsystem becomes the bottleneck.    
2. On IA32, the processor cannot issue as many loads per cycle as x86-64. Using four accumulators increases the number of loads per iteration, but the processor’s limited load bandwidth causes more stalls, resulting in a higher CPE compared to the version with fewer accumulators.  
