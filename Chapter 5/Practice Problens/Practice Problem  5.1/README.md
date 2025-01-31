### ***Practice Problem 5.1***:
The following problem illustrates the way memory aliasing can cause unexpected program behavior. Consider the following procedure to swap two values:  

```
1   /* Swap value x at xp with value y at yp */
2   void swap(int *xp, int *yp)
3   {
4       *xp = *xp + *yp;    /* x+y */
5       *yp = *xp - *yp;    /* x+y-y = x */
6       *xp = *xp - *yp;    /* x+y-x = y */
7   }
```  
If this procedure is called with xp equal to yp, what effect will it have?  

---  

### ***Answear***: 
If xp is pointing to the same pointer as yp the result will be 0.