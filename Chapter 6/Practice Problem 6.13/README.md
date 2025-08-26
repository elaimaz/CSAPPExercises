### ***Practice Problem 6.13***:  
The problems that follow will help reinforce your understanding of how caches work. Assume the following:  
1. The memory is byte addressable.
2. Memory accesses are to 1-byte words (not to 4-byte words).
3. Addresses are 13 bits wide.
4. The cache is two-way set associative (E = 2), with a 4-byte block size (B = 4) and eight sets (S = 8).  

The contents of the cache are as follows, with all numbers given in hexadecimal notation.  

| Set index |        |       |        | Line 0 |        |        |        |       |        | Line 1 |        |        |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|           | Tag    | Valid | Byte 0 | Byte 1 | Byte 2 | Byte 3 | Tag    | Valid | Byte 0 | Byte 1 | Byte 2 | Byte 3 |
| 0         | 09     | 1     | 86     | 30     | 3F     | 10     | 00     | 0     | —      | —      | —      | —      |
| 1         | 45     | 1     | 60     | 4F     | E0     | 23     | 38     | 1     | 00     | BC     | 0B     | 37     |
| 2         | EB     | 0     | —      | —      | —      | —      | 0B     | 0     | —      | —      | —      | —      |
| 3         | 06     | 0     | —      | —      | —      | —      | 32     | 1     | 12     | 08     | 7B     | AD     |
| 4         | C7     | 1     | 06     | 78     | 07     | E5     | 05     | 1     | 40     | 67     | C2     | 3B     |
| 5         | 71     | 1     | 0B     | DE     | 18     | 4B     | 6E     | 0     | —      | —      | —      | —      |
| 6         | 91     | 1     | A0     | B7     | 26     | 2D     | F0     | 0     | —      | —      | —      | —      |
| 7         | 46     | 0     | —      | —      | —      | —      | DE     | 1     | 12     | C0     | 88     | 37     |  

&emsp;The following ﬁgure shows the format of an address (one bit per box). Indicate (by labeling the diagram) the ﬁelds that would be used to determine the following:  

- CO The cache block offset
- CI The cache set index
- CT The cache tag  

| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|           |        |       |        |        |        |        |        |       |        |        |        |        |


### ***Answear***:  

| 12        |   11   |   10  |   9    |   8    |   7    |    6   |    5   |    4  |    3   |    2   |    1   |    0   |
| --------- | ------ | ----- | ------ | ------ | ------ | ------ | ------ | ----- | ------ | ------ | ------ | ------ |
|    CT     |   CT   |   CT  |   CT   |   CT   |   CT   |   CT   |    CT  |  CI   |    CI  |   CI   |   CO   |   CO   |
