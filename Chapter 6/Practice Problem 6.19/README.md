### ***Practice Problem 6.19***:  
The heart of the recent hit game SimAquarium is a tight loop that calculates the average position of 256 algae. You are evaluating its cache performance on a machine with a 1024-byte direct-mapped data cache with 16-byte blocks (B = 16). You are given the following deﬁnitions:  

```C
1   struct algae_position {
2       int x;
3       int y;
4   };
5
6   struct algae_position grid[16][16];
7   int total_x = 0, total_y = 0;
8   int i, j;
```  

You should also assume the following:  

- sizeof(int) == 4.  

- grid begins at memory address 0.  

- The cache is initially empty.  

- The only memory accesses are to the entries of the array grid. Variables i, j, total_x, and total_y are stored in registers.  

Determine the cache performance for the following code:  

```C
1   for (i = 0; i < 16; ; i++) {
2       for (j = 0; j < 16; j++) {
3           total_x += grid[i][j].x;
4       }
5   }
6
7   for (i = 0; i < 16; i++) {
8       for (j = 0; j < 16; j++) {
9           total_y += grid[i][j].y;
10      }
11  }
```  

1. What is the total number of reads?  

2. What is the total number of reads that miss in the cache?  

3. What is the miss rate?  

### ***Answear***:  

1. 

$$ \text{reads} = 16 * 16 * 2 $$

$$ \text{reads} = 512 $$

---

2.  

$$ \text{misses} = \frac{16\text{ elements}}{4} * 16 * 4 $$

$$ \text{misses} = 256 $$

---

3.  

$$ \frac{256}{512} $$

$$ \text{50\text{\%}} $$