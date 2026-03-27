### ***Practice Problem 8.2***:  
Consider the following program:  

```c
1   #include "csapp.h"
2
3   int main()
4   {
5       int x = 1;
6
7       if (Fork() == 0)
8           printf("printf1: x=%d\n", ++x);
9       printf("printf2: x=%d\n", --x);
10      exit(0);
11  }
```  

1. What is the output of the child process?  

2. What is the output of the parent process?

---  

### ***Answear***:  

1. printf1: 2; printf2: 1.  

2. printf2: 0.
