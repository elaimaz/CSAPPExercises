Exercise 8.16
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
What is the output of the following program?  

```C
1   #include "csapp.h"
2   int counter = 1;
3
4   int main()
5   {
6       if (fork() == 0) {
7           counter--;
8           exit(0);
9       }
10      else {
11          Wait(NULL);
12          printf("counter = %d\n", ++counter);
13      }
14      exit(0);
15  }
```  

---  

### ***Answear***:  
2