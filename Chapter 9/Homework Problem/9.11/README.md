Exercise 9.11
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
In the following series of problems, you are to show how the example memory system in Section 9.6.4 translates a virtual address into a physical address and accesses the cache. For the given virtual address, indicate the TLB entry accessed, the physical address, and the cache byte value returned. Indicate whether the TLB misses, whether a page fault occurs, and whether a cache miss occurs. If there is a cache miss, enter “–” for “Cache Byte returned.” If there is a page fault, enter “–” for “PPN” and leave parts C and D blank.  

**Virtual address:** 0x027c  

1. Virtual address format  

| 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|    |    |    |    |   |   |   |   |   |   |   |   |   |   |  


2. Address translation  

| Parameter         | Value |
|:-----------------:|:-----:|
| VPN               |       |
| TLB index         |       |
| TLB tag           |       |
| TLB hit? (Y/N)    |       |
| Page fault? (Y/N) |       |
| PPN               |       |  


3. Physical address format  

| 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|    |    |   |   |   |   |   |   |   |   |   |   |  


4. Physical memory reference  

| Parameter           | Value |
|:-------------------:|:-----:|
| Byte offset         |       |
| Cache index         |       |
| Cache tag           |       |
| Cache hit? (Y/N)    |       |
| Cache byte returned |       |    

---  

### ***Answear***:  

1. Virtual address format  

| 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0  | 0  | 0  | 0  | 1 | 0 | 0 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |  


2. Address translation  

| Parameter         | Value |
|:-----------------:|:-----:|
| VPN               | 0x9   |
| TLB index         | 0x1   |
| TLB tag           | 0x2   |
| TLB hit? (Y/N)    | Y     |
| Page fault? (Y/N) | N     |
| PPN               | 0x2D  |  


3. Physical address format  

| 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
|:--:|:--:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 1  | 0  | 1 | 1 | 0 | 1 | 1 | 1 | 1 | 1 | 0 | 0 |  


4. Physical memory reference  

| Parameter           | Value |
|:-------------------:|:-----:|
| Byte offset         | 0x0   |
| Cache index         | 0xF   |
| Cache tag           | 0x2D  |
| Cache hit? (Y/N)    | N     |
| Cache byte returned | –     |    
