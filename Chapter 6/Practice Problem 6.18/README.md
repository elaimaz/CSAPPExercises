### ***Practice Problem 6.18***:  
Transposing the rows and columns of a matrix is an important problem in signal processing and scientiﬁc computing applications. It is also interesting from a locality point of view because its reference pattern is both row-wise and column-wise. For example, consider the following transpose routine:  

```C
1   typedef int array[2][2];
2
3   void transpose1(array dst, array src)
4   {
5       int i, j;
6
7       for (i = 0; i < 2; i++) {
8           for (j = 0; j < 2; j++) {
9               dst[j][i] = src[i][j];
10          }
11      }
12  }
```  

Assume this code runs on a machine with the following properties:  

- sizeof(int) == 4.  

- The src array starts at address 0 and the dst array starts at address 16 (decimal).  

- There is a single L1 data cache that is direct-mapped, write-through, and write-allocate, with a block size of 8 bytes.  

- The cache has a total size of 16 data bytes and the cache is initially empty.  

- Accesses to the src and dst arrays are the only sources of read and write misses, respectively.  


1. For each row and col, indicate whether the access to src[row][col] and dst[row][col] is a hit (h) or a miss (m). For example, reading src[0][0] is a miss and writing dst[0][0] is also a miss.  

<table>
<tr>
<td>

<b>dst array</b>

|       | Col 0 | Col 1 |
|-------|-------|-------|
| Row 0 | m     |   m   |
| Row 1 |   m   |   m   |

</td>
<td>

<b>src array</b>

|       | Col 0 | Col 1 |
|-------|-------|-------|
| Row 0 | m     |   m   |
| Row 1 |   m   |   m   |

</td>
</tr>
</table>  

2. Repeat the problem for a cache with 32 data bytes.

### ***Answear***:  

1. 
<table>
<tr>
<td>

<b>dst array</b>

|       | Col 0 | Col 1 |
|-------|-------|-------|
| Row 0 | m     |   m   |
| Row 1 |   m   |   m   |

</td>
<td>

<b>src array</b>

|       | Col 0 | Col 1 |
|-------|-------|-------|
| Row 0 | m     |   m   |
| Row 1 |  m    |   m   |

</td>
</tr>
</table>  

2. 
<table>
<tr>
<td>

<b>dst array</b>

|       | Col 0 | Col 1 |
|-------|-------|-------|
| Row 0 | m     |   h   |
| Row 1 |   m   |   h   |

</td>
<td>

<b>src array</b>

|       | Col 0 | Col 1 |
|-------|-------|-------|
| Row 0 | m     |    h  |
| Row 1 |  m    |    h  |

</td>
</tr>
</table>  
