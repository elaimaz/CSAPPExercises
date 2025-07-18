### ***Practice Problem 6.8***:  
Permute the loops in the following function so that it scans the three-dimensional array a with a stride-1 reference pattern.  

```c
1   int sumarray3d(int a[N][N][N])
2   {
3        int i, j, k, sum = 0;
4
5        for (i = 0; i < N; i++) {
6            for (j = 0; j < N; j++) {
7                for (k = 0; k < N; k++) {
8                    sum += a[k][i][j];
9                }
10            }
11        }
12        return sum;
13  }
```

---  

### ***Answear***:  
[code](./main.c).  
