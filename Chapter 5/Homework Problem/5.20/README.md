Exercise 5.20
==============

### ***Dificulty***: :star: :star: :star:   

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
We considered the task of polynomial evaluation in Problems 5.5 and 5.6, with both a direct evaluation and an evaluation by Horner’s method. Try to write faster versions of the function using the optimization techniques we have explored, including loop unrolling, parallel accumulation, and reassociation. You will ﬁnd many different ways of mixing together Horner’s scheme and direct evaluation with these optimization techniques.  
&emsp;Ideally, you should be able to reach a CPE close to the number of cycles between successive ﬂoating-point additions and multiplications with your machine (typically 1). At the very least, you should be able to achieve a CPE less than the latency of ﬂoating-point addition for your machine.

---  

### ***Answear***:   
[main.c](./main.c).  

| Method           | unsigned int | float | double |
|------------------|:---------------------:|:---------------------:|:---------------------:|
| polyh | 0.000002 | 0.000003 | 0.000002 |
| polyh_enhanced loop unroling x2 | 0.000001 | 0.000001 | 0.000001 |
| polyh_enhanced loop unroling x2 accumulators x2 | 0.000001 | 0.000001 | 0.000001 |  

observation: Could not find any way to use reassociation.

