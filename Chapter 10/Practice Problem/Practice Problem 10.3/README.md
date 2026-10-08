### ***Practice Problem 10.2***:  
As before, suppose the disk ﬁle foobar.txt consists of the six ASCII characters “foobar”. Then what is the output of the following program?  

```C
1   #include "csapp.h"
2
3   int main()
4   {
5       int fd;
6       char c;
7
8       fd = Open("foobar.txt", O_RDONLY, 0);
9       if (Fork() == 0) {
10          Read(fd, &c, 1);
11          exit(0);
12      }
13      Wait(NULL);
14      Read(fd, &c, 1);
15      printf("c = %c\n", c);
16      exit(0);
17  }
```  

---  

### ***Answear***:  
It will be "c = o".  