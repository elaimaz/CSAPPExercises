Exercise 6.39
==============

### ***Dificulty***: :star:    

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
3M™ decides to make Post-It® notes by printing yellow squares on white pieces of paper. As part of the printing process, they need to set the CMYK (cyan, magenta, yellow, black) value for every point in the square. 3M hires you to determine the efﬁciency of the following algorithms on a machine with a 2048-byte direct-mapped data cache with 32-byte blocks. You are given the following deﬁnitions:  

```C
1   struct point_color {
2       int c;
3       int m;
4       int y;
5       int k;
6   };
7
8   struct point_color square[16][16];
9   int i, j;
```  

Assume the following:  

- sizeof(int) = 4.  
- square begins at memory address 0.  
- The cache is initially empty.  
- The only memory accesses are to the entries of the array square. Variables i and j are stored in registers.  

Determine the cache performance of the following code:  

```C
1   for (i = 0; i < 16; i++){
2       for (j = 0; j < 16; j++) {
3           square[i][j].c = 0;
4           square[i][j].m = 0;
5           square[i][j].y = 1;
6           square[i][j].k = 0;
7       }
8   }
```  

1. What is the total number of writes?  
2. What is the total number of writes that miss in the cache?  
3. What is the miss rate?

---  

### ***Answear***:  

1. 
$$ 16 * 16 * 4 $$
$$ 1024\text{ Writes} $$

$$ \text{Integers per block} = \frac{\text{Block size}}{\text{sizeof(int)}} $$
$$ \text{Integers per block} = \frac{32\text{ Bytes}}{4\text{ Bytes}} $$
$$ \text{Integers per block} = 8 $$

---

$$ \text{Number of Sets (S)} = \frac{\text{Cache Size}}{\text{Block Size}} $$
$$ \text{S} = \frac{2048 \text{ Bytes}}{32 \text{ Bytes}} $$
$$ \text{S} = 64 $$

---

2. 
each index of square will have 16 bytes. So at each iteration we will write 2 index of square in the cache.  
So we can take that we will have a miss in 50% of iterations

$$ 16 * 16 / 2 $$
$$ 256 / 2 $$
$$ 128\text{ Misses} $$

---  

3. 
$$ \text{Miss rate} = \frac{128\text{ Misses}}{1024\text{ Misses}} * 100 $$
$$ \text{Miss rate} = 0.125 * 100 $$
$$ \text{Miss rate} = 12.5 $$
