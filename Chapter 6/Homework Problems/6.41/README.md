Exercise 6.41
==============

### ***Dificulty***: :star:    

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
Given the assumptions in Problem 6.39, determine the cache performance of the following code:  

```C
1   for (i = 0; i < 16; i++) {
2       for (j = 0; j < 16; j++) {
3           square[i][j].y = 1;
4       }
5   }
6   for (i = 0; i < 16; i++) {
7       for (j = 0; j < 16; j++) {
8           square[i][j].c = 0;
9           square[i][j].m = 0;
10          square[i][j].k = 0;
11      }
12  }
```  

1. What is the total number of writes?  
2. What is the total number of writes that miss in the cache?  
3. What is the miss rate?

---  

### ***Answear***:  

1. 
$$ 16 * 16 * 4 $$
$$ 1024\text{ Writes} $$

2. 
$$ 256\text{ misses} $$

3. 
$$ 25\text{ percent} $$  

---  

obs: check [main.c](main.c), there have a simulated cache.
