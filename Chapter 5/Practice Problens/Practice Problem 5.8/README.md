### ***Practice Problem 5.8***:
Consider the following function for computing the product of an array of n integers. We have unrolled the loop by a factor of 3.  

```C
double aprod(double a[], int n)
{
    int i;
    double x, y, z;
    double r = 1;
    for (i = 0; i < n-2; i+= 3) {
        x = a[i]; y = a[i+1]; z = a[i+2];
        r = r * x * y * z; /* Product computation */
    }
    for (; i < n; i++)
        r *= a[i];
    return r;
}
```  

For the line labeled Product computation, we can use parentheses to create ﬁve different associations of the computation, as follows:  

```C
r = ((r * x) * y) * z; /* A1 */
r = (r * (x * y)) * z; /* A2 */
r = r * ((x * y) * z); /* A3 */
r = r * (x * (y * z)); /* A4 */
r = (r * x) * (y * z); /* A5 */
```  

Assume we run these functions on a machine where double-precision multiplication has a latency of 5 clock cycles. Determine the lower bound on the CPE set by the data dependencies of the multiplication. (Hint: It helps to draw a pictorial representation of how r is computed on every iteration.)  

---  

### ***Answear***:  
A1 5 CPE
A2 5 CPE
A3 5 CPE
A4 5 CPE
A5 3.33 CPE 


