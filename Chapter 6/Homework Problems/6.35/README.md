Exercise 6.35
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following matrix transpose routine:  

```C
1   typedef int array[4][4];
2
3   void transpose2(array dst, array src)
4   {
5       int i, j;
6
7       for (i = 0; i < 4; i++) {
8           for (j = 0; j < 4; j++) {
9               dst[j][i] = src[i][j];
10          }
11      }
12  }
```  

Assume this code runs on a machine with the following properties:  

- sizeof(int) == 4.  
- The src array starts at address 0 and the dst array starts at address 64 (decimal).  
- There is a single L1 data cache that is direct-mapped, write-through, write-allocate, with a block size of 16 bytes.  
- The cache has a total size of 32 data bytes and the cache is initially empty.  
- Accesses to the src and dst arrays are the only sources of read and write misses, respectively.  

1. For each row and col, indicate whether the access to src[row][col] and dst[row][col] is a hit (h) or a miss (m). For example, reading src[0][0] is a miss and writing dst[0][0] is also a miss.  


| **dst array** |           |           |           |           |   | **src array** |           |           |           |           |
| :------------ | :-------: | :-------: | :-------: | :-------: |---| :------------ | :-------: | :-------: | :-------: | :-------: |
| **Row 0**     | m         |           |           |           |   | **Row 0**     | m         |           |           |           |
| **Row 1**     |           |           |           |           |   | **Row 1**     |           |           |           |           |
| **Row 2**     |           |           |           |           |   | **Row 2**     |           |           |           |           |
| **Row 3**     |           |           |           |           |   | **Row 3**     |           |           |           |           |
|               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |   |               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |


---  

### ***Answear***:  

1. 

| **dst array** |           |           |           |           |   | **src array** |           |           |           |           |
| :------------ | :-------: | :-------: | :-------: | :-------: |---| :------------ | :-------: | :-------: | :-------: | :-------: |
| **Row 0**     | m         |    m      |    m      |     m     |   | **Row 0**     | m         |     m     |     h     |     m     |
| **Row 1**     |   m       |    m      |    m      |     m     |   | **Row 1**     |  m        |     h     |    m      |    h      |
| **Row 2**     |    m      |    m      |    m      |     m     |   | **Row 2**     |    m      |    m      |    h      |    m      |
| **Row 3**     |    m      |    m      |    m      |     m     |   | **Row 3**     |    m      |     h     |    m      |    h      |
|               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |   |               | **Col 0** | **Col 1** | **Col 2** | **Col 3** |  


---  


### ***Notes***: :memo:  

Remember that src and dst array row0/2 goes to cache index 0 and row1/3 goes to cache index 1.
