### ***Practice Problem 6.1***:
In the following, let r be the number of rows in a DRAM array, c the number of columns, b<sub>r</sub> the number of bits needed to address the rows, and b<sub>c</sub> the number of bits needed to address the columns. For each of the following DRAMs, determine the power-of-two array dimensions that minimize max(b<sub>r</sub> , b<sub>c</sub>), the maximum number of bits needed to address the rows or columns of the array.  

| Organization | r | c | b<sub>r</sub> | b<sub>c</sub> | max(b<sub>r</sub>,b<sub>c</sub>) |
|---|---|---|---|---|---|
| 16 x 1 |   |   |   |   | |
| 16 x 4 |   |   |   |   | |
| 128 x 8 |   |   |   |   | |
| 512 x 4 |   |   |   |   | |
| 1024 x 4 |   |   |   |   | |

---  

### ***Answear***: 
| Organization | r | c | b<sub>r</sub> | b<sub>c</sub> | max(b<sub>r</sub>,b<sub>c</sub>) |
|---|---|---|---|---|---|
| 16 x 1 | 4 | 4 | 2 | 2 | 2 |
| 16 x 4 | 4 | 4 | 2 | 2 | 2 |
| 128 x 8 | 16 | 8 | 4 | 3 | 4 |
| 512 x 4 | 32 | 16 | 5 | 4 | 5 |
| 1024 x 4 | 32 | 32 | 5 | 5 | 5 |