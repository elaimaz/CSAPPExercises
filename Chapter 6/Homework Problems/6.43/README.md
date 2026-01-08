Exercise 6.43
==============

### ***Dificulty***: :star: :star:    

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Given the assumptions in Problem [6.42](../6.42/README.md), what percentage of writes in the following code will miss in the cache?  

```C
1   char *cptr = (char *) buffer;
2   for (; cptr < (((char *) buffer) + 640 * 480 * 4); cptr++)
3       *cptr = 0;
---  

### ***Answear***:  
Since the cache has a 4-byte lines size, it fit the entirely pixel struct. The loop goes to each char at time, the answear will be the same of the previous question. The first iteration will be a miss, the next three will be a hit. 1 miss at each 4 iterations, so 1/4 or 25% miss rate. [Simulation code](main.c)
