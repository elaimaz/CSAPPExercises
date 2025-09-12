### ***Practice Problem 6.21***:  
Given the assumptions of Problem 6.19, determine the cache performance of the following code:  

```C
1   for (i = 0; i < 16; i++) {
2       for (j = 0; j < 16; j++) {
3           total_x += grid[i][j].x;
4           total_y += grid[i][j].y;
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

$$ \frac{512\text{ reads}}{4\text{ data cache}}  $$

$$ 128\text{ misses.} $$

---

3.  

$$ \frac{128\text{ misses}}{512\text{ reads}} * 100 $$

$$ 25 $$

---

4. 

It would be the same, because B still 16 bytes. So we still will have the cold misses.
