Exercise 6.27
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
The following table gives the parameters for a number of different caches. Your task is to ﬁll in the missing ﬁelds in the table. Recall that m is the number of physical address bits, C is the cache size (number of data bytes), B is the block size in bytes, E is the associativity, S is the number of cache sets, t is the number of tag bits, s is the number of set index bits, and b is the number of block offset bits.  

| Cache | m  |  C   |  B  |  E  |  S  |  t  |  s  |  b  |
|-------|----|------|-----|-----|-----|-----|-----|-----|
| 1.    | 32 |      |  8  |  1  |     | 21  | 8   | 3   |
| 2.    | 32 | 2048 |     |     | 128 | 23  | 7   | 2   |
| 3.    | 32 | 1024 |  2  |  8  | 64  |     |     | 1   |
| 4.    | 32 | 1024 |     |  2  | 16  | 23  | 4   |     |  


---  

### ***Answear***:  

| Cache | m  |  C   |  B  |  E  |  S  |  t  |  s  |  b  |
|-------|----|------|-----|-----|-----|-----|-----|-----|
| 1.    | 32 | 2048 |  8  |  1  | 256 | 21  | 8   | 3   |
| 2.    | 32 | 2048 |  4  |  4  | 128 | 23  | 7   | 2   |
| 3.    | 32 | 1024 |  2  |  8  | 64  | 25  | 6   | 1   |
| 4.    | 32 | 1024 |  32 |  2  | 16  | 23  | 4   | 5   |  