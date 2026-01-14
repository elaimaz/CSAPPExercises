Exercise 6.44
==============

### ***Dificulty***: :star: :star:    

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Given the assumptions in Problem 6.42, what percentage of writes in the following code will miss in the cache?  

```C
1   int *iptr = (int *)buffer;
2   for (; iptr < ((int *)buffer + 640*480); iptr++)
3       *iptr = 0;
```  

---  

### ***Answear***:  
Since the the entirely pixel will be put into the cache, the mis rate will be 100%

