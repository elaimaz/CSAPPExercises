### ***Practice Problem 6.15***:  
Repeat Problem 6.14 for memory address 0x0DD5.  

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
|      0    |    1   |   1   |    0   |    1   |    1   |    1   |    0   |    1  |    0   |   1    |    0   |    1   |  

2. 
| Parameter               | Value  |
| ----------------------- | ------ |
| Cache block offset (CO) | 0x1    |
| Cache set index (CI)    | 0x5    |
| Cache tag (CT)          | 0x6E   |
| Cache hit? (Y/N)        |   N    |
| Cache byte returned     | 0x     |
