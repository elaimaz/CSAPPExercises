### ***Practice Problem 5.10***:
As another example of code with potential load-store interactions, consider the following function to copy the contents of one array to another:  

```C
1   void copy_array(int *src, int *dest, int n)
2   {
3       int i;
4       for (i = 0; i < n; i++)
5           dest[i] = src[i];
6   }
```  

Suppose a is an array of length 1000 initialized so that each element a[i] equals i.  

1. What would be the effect of the call copy_array(a+1,a,999)?
2. What would be the effect of the call copy_array(a,a+1,999)?
3. Our performance measurements indicate that the call of part A has a CPE of 2.00, while the call of part B has a CPE of 5.00. To what factor do you attribute this performance difference?
4. What performance would you expect for the call copy_array(a,a,999)?

---  

### ***Answear***:  

1. All values in the range n will be moved to the position on it's left.
2. All values in the range n will be equal a[0].
3. Because the load of one iteration depends on the result of the store from the previous iteration in the case B(2).
4. CPE 2.00.
