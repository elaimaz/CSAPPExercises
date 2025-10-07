Exercise 6.32
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Supppose that a program using the cache in Problem 6.31 references the 1-byte word at address 0x071A. Indicate the cache entry accessed and the cache byte value returned in hex. Indicate whether a cache miss occurs. If there is a cache miss, enter “–” for “Cache byte returned”. Hint: Pay attention to those valid bits!  

1. Address format (one bit per box):

| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|           |        |       |        |        |        |        |        |       |        |        |        |        |  


2. 

| Parameter           | Value  |
| ------------------- | ------ |
| Block offset (CO)   | 0x     |
| Index (CI)          | 0x     |
| Cache tag (CT)      | 0x     |
| Cache hit? (Y/N)    | 0x     |
| Cache byte returned | 0x     |  

---  

### ***Answear***:  

1. 

| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|    0      |    0   |    1  |    1   |    1   |    0   |    0   |    0   |    1  |    1   |    0   |    1   |    0   |  

2.

| Parameter           | Value  |
| ------------------- | ------ |
| Block offset (CO)   | 0x2    |
| Index (CI)          | 0x6    |
| Cache tag (CT)      | 0x38   |
| Cache hit? (Y/N)    | Y      |
| Cache byte returned | 0xEB   |  
