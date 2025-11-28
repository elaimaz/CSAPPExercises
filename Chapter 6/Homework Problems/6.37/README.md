Exercise 6.37
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
This problem tests your ability to predict the cache behavior of C code. You are given the following code to analyze:  

```C
1   int x[2][128];
2   int i;
3   int sum = 0;
4
5   for (i = 0; i < 128; i++) {
6       sum += x[0][i] * x[1][i];
7   }
```  

Assume we execute this under the following conditions:  

- sizeof(int) = 4.  
- Array x begins at memory address 0x0 and is stored in row-major order.  
- In each case below, the cache is initially empty.  
- The only memory accesses are to the entries of the array x. All other variables are stored in registers.  

Given these assumptions, estimate the miss rates for the following cases:  
1. Case 1: Assume the cache is 512 bytes, direct-mapped, with 16-byte cache blocks. What is the miss rate?  
2. Case 2: What is the miss rate if we double the cache size to 1024 bytes?  
3. Case 3: Now assume the cache is 512 bytes, two-way set associative using an LRU replacement policy, with 16-byte cache blocks. What is the cache miss rate?  
4. For Case 3, will a larger cache size help to reduce the miss rate? Why or why not?  


---  

### ***Answear***:  

$$ \text{Integers per block} = \frac{\text{Block size}}{\text{sizeof(int)}} $$
$$ \text{Integers per block} = \frac{16\text{ Bytes}}{4\text{ Bytes}} $$
$$ \text{Integers per block} = 4\text{ Bytes} $$

This means that one cache miss will bring 4 consecutive integers.

$$ \text{Number of Sets (S)} = \frac{\text{Cache Size}}{\text{Block Size}} $$
$$ \text{S} = \frac{512 \text{ Bytes}}{16 \text{ Bytes}} $$
$$ \text{S} = 32 $$

Remember:
$$ \text{Set index} = \frac{\text{Memory Address}}{\text{Block Size}} \text{mod (Number of Sets)} $$

1. In this case we will have 100% os miss rate. ```x[0][i]``` will write in cache but ```x[1][i]``` will ovewrite.  

2. The miss rate will be 25%, at each miss we will add 4 elements into the cache, the first one is the miss, and the rest will be a hit.  

3. 

$$ \text{Number of Sets (S)} = \frac{\frac{\text{Cache Size}}{\text{Block Size}}}{2\text{ two-way set}} $$
$$ \text{Number of Sets (S)} = \frac{\frac{512\text{ Bytes}}{16 \text{ Bytes}}}{2\text{ two-way set}} $$
$$ \text{Number of Sets (S)} = \frac{32}{2\text{ two-way set}} $$
$$ \text{Number of Sets (S)} = 16 $$

The miss rate will be 25%, because we will have 16 sets, and each 12 bytes we will have a miss. so we will have 64 misses in a range of 256 integers.  

4. No, in this particular case we still will have the first miss-rate of the object access. A greater blocks tho would change the miss-rate.  