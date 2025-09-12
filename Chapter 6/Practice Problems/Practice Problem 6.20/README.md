### ***Practice Problem 6.20***:  
Given the assumptions of Problem 6.19, determine the cache performance of the following code:  

```C
1   for (i = 0; i < 16; i++){
2       for (j = 0; j < 16; j++) {
3           total_x += grid[j][i].x;
4           total_y += grid[j][i].y;
5       }
6   }
```  

1. What is the total number of reads?  

2. What is the total number of reads that miss in the cache?  

3. What is the miss rate?  

4. What would the miss rate be if the cache were twice as big?

### ***Answear***:  

1.  

$$ 16 * 16 * 2 $$

$$ 512\text{ reads.} $$

---

2.  

$$ \frac{512\text{ reads} * 2\text{ (Because we are iterating though lines not columns)}}{4\text{ data chache}}  $$

$$ 256\text{ misses.} $$

---

3.  

$$ \frac{256\text{ misses}}{512\text{ reads}} * 100 $$

$$ 50 $$

---

4. 

$$ \frac{512\text{ reads} * 2\text{ (x and y)}}{8\text{ data chache}}  $$

$$ 128\text{ misses.} $$

$$ \frac{128\text{ misses}}{512\text{ reads}} * 100 $$

$$ 25 $$
