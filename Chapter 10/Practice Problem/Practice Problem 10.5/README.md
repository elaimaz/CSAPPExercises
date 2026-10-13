### ***Practice Problem 10.5***:  
Assuming that the disk ﬁle foobar.txt consists of the six ASCII characters “foobar”, what is the output of the following program?  

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
10      Read(fd2, &c, 1);
11      Dup2(fd2, fd1);
12      Read(fd1, &c, 1);
13      printf("c = %c\n", c);
14      exit(0);
15  }
```  

---  

### ***Answear***:  
"c = o".  
