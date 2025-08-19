### ***Practice Problem 6.12***:  
In general, if the high-order s bits of an address are used as the set index, contiguous chunks of memory blocks are mapped to the same cache set.  

1. How many blocks are in each of these contiguous array chunks?  
2. Consider the following code that runs on a system with a cache of the form (S, E, B, m) = (512, 1, 32, 32):  
```c
int array[4096];

for (i = 0; i < 4096; i++)
    sum += array[i];
```  
What is the maximum number of array blocks that are stored in the cache at any point in time?

---  

### ***Answear***:  
1. With high-order bit indexing, each contiguous array chunk consists of 2<sup>t</sup> blocks, where t is the number of tag bits. Thus, the ﬁrst 2<sup>t</sup> contiguous blocks of the array would map to set 0, the next 2t blocks would map to set 1 and so on.  
2. 
$$ 4096 * 4 = 16384\text{ bytes} $$

---

$$ \frac{16384}{32} = 512\text{ blocks} $$

---

$$ \log_{2}(512) = 9\text{ bits} $$

---

$$ \text{Block offset bit b} = \log_{2}(32) $$

$$ \text{Block offset bit b} = 5\text{ bits} $$

---

$$ t = m - s - b $$
$$ t = 32 - 9 - 5 $$
$$ t = 18\text{ bits} $$

---

$$ \text{Each chunk} = 2^{18} $$
$$ \text{Each chunk} = 262144\text{ blocks} $$

---

The entire array lies within one contiguous chunk 


