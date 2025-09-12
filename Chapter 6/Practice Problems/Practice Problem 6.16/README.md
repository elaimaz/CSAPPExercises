### ***Practice Problem 6.16***:  
Repeat Problem 6.14 for memory address 0x1FE4.  

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
|      1    |    1   |   1   |    1   |    1   |    1   |    1   |    1   |    0  |    0   |   1    |    0   |    0   |  

2. 
| Parameter               | Value  |
| ----------------------- | ------ |
| Cache block offset (CO) | 0x0    |
| Cache set index (CI)    | 0x1    |
| Cache tag (CT)          | 0xFF   |
| Cache hit? (Y/N)        |   N    |
| Cache byte returned     | 0x     |
