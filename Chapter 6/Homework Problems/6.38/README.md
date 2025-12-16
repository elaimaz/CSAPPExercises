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
$$ \text{Integers per block} = 4\text{ Bytes} $$

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

