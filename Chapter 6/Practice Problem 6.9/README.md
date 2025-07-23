### ***Practice Problem 6.9***:  
The three functions in Figure 6.22 perform the same operation with varying degrees of spatial locality. Rank-order the functions with respect to the spatial locality enjoyed by each. Explain how you arrived at your ranking.  

<div style="display: flex; gap: 10px;">
  <div style="flex: 1;">
    <p>(a) An array of structs</p>
    <pre>
      1     #define N 1000
      2
      3     typedef struct {
      4         int vel[3];
      5         int acc[3];
      6     } point;
      7
      8     point p[N];
    </pre>  
  </div>
  <div style="flex: 1;">
    <p>(b) The clear1 function</p>
    <pre>
      1     void clear1(point *p, int n)
      2     {
      3         int i, j;
      4
      5         for (i = 0; i < n; i++) {
      6             for (j = 0; j < 3; j++)
      7                 p[i].vel[j] = 0;
      8             for (j = 0; j < 3; j++)
      9                 p[i].acc[j] = 0;
      10        }
      11    }
    </pre>
  </div>
</div>
<br/>
<div style="display: flex; gap: 10px;">
  <div style="flex: 1;">
    <p>(c) The clear2 function</p>
    <pre>
      1     void clear2(point *p, int n)
      2     {
      3         int i, j;
      4
      5         for (i = 0; i < n; i++) {
      6             for (j = 0; j < 3; j++) {
      7                 p[i].vel[j] = 0;
      8                 p[i].acc[j] = 0;
      9             }
      10        }
      11    }
    </pre>  
  </div>
  <div style="flex: 1;">
    <p>(d) The clear3 function</p>
    <pre>
      1     void clear3(point *p, int n)
      2     {
      3         int i, j;
      4
      5         for (j = 0; j < 3; j++) {
      6             for(i = 0; i < n; i++)
      7                 p[i].vel[j] = 0;
      8             for (i = 0; i < n; i++)
      9                 p[i].acc[j] = 0;
      10        }
      11    }
    </pre>
  </div>
</div>


---  

### ***Answear***:  

1. (a)  Best, because there is no jumps in memory.
2. (b)  Mid, every iteration there is 3 positions to jump forward or backwards.
3. (c)  Worst, the jumps in memory will be greater in this version.
