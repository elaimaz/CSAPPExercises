### ***Practice Problem 10.1***:  
What is the output of the following program?  

```C
1   #include "csapp.h"
2
3   int main()
4   {
5       int fd1, fd2;
6
7       fd1 = Open("foo.txt", O_RDONLY, 0);
8       Close(fd1);
9       fd2 = Open("baz.txt", O_RDONLY, 0);
10      printf("fd2 = %d\n", fd2);
11      exit(0);
12  }
```  

---  

### ***Answear***:  
If the file exists it will be a non-negative number, otherwise will be a error message "Open error: No such file or directory".  
