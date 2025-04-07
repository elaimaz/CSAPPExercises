### ***Practice Problem 5.12***:
Rewrite the code for psum1 (Figure 5.1) so that it does no need to repeatedly retrieve the value of p[i] from memory. You do not need to use loop unrolling. We measured the resulting code to have a CPE of 3.00, limited by the latency of floating-point addition.  

---  

### ***Answear***:  
```C
1   void psum1a(float a[], float p[], long int n)
2   {
3       long int i;
4       /* last_val holds p[i-1]; val holds p[i] */
5       float last_val, val;
6       last_val = p[0] = a[0];
7       for (i = 1; i < n; i++) {
8           val = last_val + a[i];
9           p[i] = val;
10         last_val = val;
11     }
12  }
```
