Exercise 6.38
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
This is another problem that tests your ability to analyze the cache behavior of C code. Assume we execute the three summation functions in Figure 6.49 under the following conditions:  

- sizeof(int) = 4.  
- The machine has a 4KB direct-mapped cache with a 16-byte block size.  
- Within the two loops, the code uses memory accesses only for the array data. The loop indices and the value sum are held in registers.  
- Array a is stored starting at memory address 0x08000000.  


Fill in the table for the approximate cache miss rate for the two cases N = 64 and N = 60.  

| Function | N = 64 | N = 60 |
| :------: | :----: | :----: |
| sumA     |        |        |
| sumB     |        |        |
| sumC     |        |        |  


```C
1   typedef int array_t[N][N];
2
3   int sumA(array_t a)
4   {
5       int i, j;
6       int sum = 0;
7       for (i = 0; i < N; i++)
8           for (j = 0; j < N; j++) {
9               sum += a[i][j];
10          }
11      return sum;
12  }
13
14  int sumB(array_t a)
15  {
16      int i, j;
17      int sum = 0;
18      for (j = 0; j < N; j++)
19          for (i = 0; i < N; i++) {
20              sum += a[i][j];
21          }
22      return sum;
23  }
24
25  int sumC(array_t a)
26  {
27      int i, j;
28      int sum = 0;
29      for (j = 0; j < N; j+=2)
30          for (i = 0; i < N; i+=2) {
31              sum += (a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1]);
32          }
33      return sum;
34  }
```
Figure 6.49 **Functions referenced in Problem 6.38.**


---  

### ***Answear***:  


| Function | N = 64 | N = 60 |
| :------: | :----: | :----: |
| sumA     |   25%  |   25%  |
| sumB     |   100% |  25%   |
| sumC     | 43.75% |  25%   |

---

$$ \text{Integers per block} = \frac{\text{Block size}}{\text{sizeof(int)}} $$
$$ \text{Integers per block} = \frac{16\text{ Bytes}}{4\text{ Bytes}} $$
$$ \text{Integers per block} = 4 $$

---

$$ \text{Number of Sets (S)} = \frac{\text{Cache Size}}{\text{Block Size}} $$
$$ \text{S} = \frac{4096 \text{ Bytes}}{16 \text{ Bytes}} $$
$$ \text{S} = 256 $$

---

$$ \text{Number of integers in array N(64)} =  64 * 64 $$
$$ \text{Number of integers in array N(64)} =  4096 $$

---

$$ \text{Number of integers in array N(60)} =  60 * 60 $$
$$ \text{Number of integers in array N(60)} =  3600 $$

---

Remember:
$$ \text{Set index} = \frac{\text{Memory Address}}{\text{Block Size}} \text{mod (Number of Sets)} $$

---

Check [main.c](./main.c)

