Exercise 6.30
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Suppose we have a system with the following properties:  

- The memory is byte addressable.  

- Memory accesses are to 1-byte words (not to 4-byte words).  

- Addresses are 12 bits wide.  

- The cache is two-way set associative (E = 2), with a 4-byte block size (B = 4) and four sets (S = 4).  

The contents of the cache are as follows, with all addresses, tags, and values given in hexadecimal notation:  

Thanks! I’ll recreate the cache table exactly as shown in the image using markdown formatting, preserving the layout with multi-row entries under each Set index.  

| Set index | Tag | Valid | Byte 0 | Byte 1 | Byte 2 | Byte 3 |
| :-------: | :-: | :---: | :----: | :----: | :----: | :----: |
| 0         | 00  | 1     | 40     | 41     | 42     | 43     |
|           | 83  | 1     | FE     | 97     | CC     | D0     |
| 1         | 00  | 1     | 44     | 45     | 46     | 47     |
|           | 83  | 0     | —      | —      | —      | —      |
| 2         | 00  | 1     | 48     | 49     | 4A     | 4B     |
|           | 40  | 0     | —      | —      | —      | —      |
| 3         | FF  | 1     | 9A     | C0     | 03     | FF     |
|           | 00  | 0     | —      | —      | —      | —      |  

1. The following diagram shows the format of an address (one bit per box). Indicate (by labeling the diagram) the ﬁelds that would be used to determine the following:  
    - CO The cache block offset
    - CI The cache set index
    - CT The cache tag  

| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|           |        |       |        |        |        |        |        |       |        |        |        |        |  

2. For each of the following memory accesses indicate if it will be a cache hit or miss when carried out in sequence as listed. Also give the value of a read if it can be inferred from the information in the cache.  

| Operation | Address | Hit? | Read value (or unknown) |
| :-------: | :-----: | :--: | :---------------------: |
| Read      | 0x834   |      |                         |
| Write     | 0x836   |      |                         |
| Read      | 0xFFD   |      |                         |



---  

### ***Answear***:  

1. 
| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|    CT     |   CT   |   CT  |   CT   |   CT   |   CT   |   CT   |   CT   |   CT  |   CI   |   CI   |   CO   |  CO    |  


2. 
| Operation | Address | Hit? | Read value (or unknown) |
| :-------: | :-----: | :--: | :---------------------: |
| Read      | 0x834   |   N  |         unknown         |
| Write     | 0x836   |   N  |         unknown         |
| Read      | 0xFFD   |   Y  |         C0              |  

---

0x834  
| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|    0      |   1    |   0   |   0    |   0    |   0    |   0    |   1    |   1   |   0    |   1    |   0    |  0     |  


CO = 0x0  
CI = 0x1  
CT = 0x83  

---  

0x836  
| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|    0      |   1    |   0   |   0    |   0    |   0    |   0    |   1    |   1   |   0    |   1    |   1    |  0     |  


CO = 0x1  
CI = 0x1  
CT = 0x83  

---  

0xFFD  
| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|    0      |   1    |   1   |   1    |   1    |   1    |   1    |   1    |   1   |   1    |   1    |   0    |   1    |  


CO = 0x1  
CI = 0x3  
CT = 0xFF  