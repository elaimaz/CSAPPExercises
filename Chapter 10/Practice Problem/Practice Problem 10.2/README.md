### ***Practice Problem 10.2***:  
Suppose the disk ﬁle foobar.txt consists of the six ASCII characters “foobar”. Then what is the output of the following program?  

```C
1   #include "csapp.h"
2
3   int main()
4   {
5       int fd1, fd2;
6       char c;
7
8       fd1 = Open("foobar.txt", O_RDONLY, 0);
9       fd2 = Open("foobar.txt", O_RDONLY, 0);
10      Read(fd1, &c, 1);
11      Read(fd2, &c, 1);
12      printf("c = %c\n", c);
13      exit(0);
14  }
```  

---  

### ***Answear***:  
It will print "f".  
