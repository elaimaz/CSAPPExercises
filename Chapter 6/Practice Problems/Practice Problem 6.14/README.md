### ***Practice Problem 6.14***:  
Suppose a program running on the machine in Problem 6.13 references the 1-byte word at address 0x0E34. Indicate the cache entry accessed and the cache byte value returned in hex. Indicate whether a cache miss occurs. If there is a cache miss, enter “–” for “Cache byte returned.”  

1. Address format (one bit per box):  


| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|           |        |       |        |        |        |        |        |       |        |        |        |        |  

2. Memory reference:  

| Parameter               | Value  |
| ----------------------- | ------ |
| Cache block offset (CO) | 0x     |
| Cache set index (CI)    | 0x     |
| Cache tag (CT)          | 0x     |
| Cache hit? (Y/N)        |        |
| Cache byte returned     | 0x     |


### ***Answear***:  

1. 
| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|      0    |    1   |   1   |    1   |    0   |    0   |    0   |    1   |    1  |    0   |   1    |    0   |    0   |  

2. 
| Parameter               | Value  |
| ----------------------- | ------ |
| Cache block offset (CO) | 0x0    |
| Cache set index (CI)    | 0x5    |
| Cache tag (CT)          | 0x71   |
| Cache hit? (Y/N)        |   Y    |
| Cache byte returned     | 0x0B   |
