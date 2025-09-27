Exercise 6.26
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
The following table gives the parameters for a number of different caches. For each cache, ﬁll in the missing ﬁelds in the table. Recall that m is the number of physical address bits, C is the cache size (number of data bytes), B is the block size in bytes, E is the associativity, S is the number of cache sets, t is the number of tag bits, s is the number of set index bits, and b is the number of block offset bits.  

| Cache | m  |  C   |  B  |  E  |  S  |  t  |  s  |  b  |
|-------|----|------|-----|-----|-----|-----|-----|-----|
| 1.    | 32 | 1024 |  4  |  4  |     |     |     |     |
| 2.    | 32 | 1024 |  4  | 256 |     |     |     |     |
| 3.    | 32 | 1024 |  8  |  1  |     |     |     |     |
| 4.    | 32 | 1024 |  8  | 128 |     |     |     |     |
| 5.    | 32 | 1024 | 32  |  1  |     |     |     |     |
| 6.    | 32 | 1024 | 32  |  4  |     |     |     |     |  


---  

### ***Answear***:  

| Cache | m  |  C   |  B  |  E  |  S  |  t  |  s  |  b  |
|-------|----|------|-----|-----|-----|-----|-----|-----|
| 1.    | 32 | 1024 |  4  |  4  | 64  | 24  |  6  |  2  |
| 2.    | 32 | 1024 |  4  | 256 |  1  | 30  |  0  |  2  |
| 3.    | 32 | 1024 |  8  |  1  | 128 | 22  |  7  |  3  |
| 4.    | 32 | 1024 |  8  | 128 |  1  | 29  |  0  |  3  |
| 5.    | 32 | 1024 | 32  |  1  | 32  | 22  |  5  |  5  |
| 6.    | 32 | 1024 | 32  |  4  |  8  | 24  |  3  |  5  |
