Exercise 6.33
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Repeat Problem 6.32 for memory address 0x16E8.  

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
| Cache hit? (Y/N)    | ______ |
| Cache byte returned | 0x     |  

---  

### ***Answear***:  

1. 

| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|   1       |    0   |    1  |   1    |   0    |   1    |    1   |    1   |    0  |    1   |    0   |    0   |    0   |  

2.

| Parameter           | Value  |
| ------------------- | ------ |
| Block offset (CO)   | 0x0    |
| Index (CI)          | 0x2    |
| Cache tag (CT)      | 0xB7   |
| Cache hit? (Y/N)    | N      |
| Cache byte returned | ------ |  
