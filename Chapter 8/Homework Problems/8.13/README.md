Exercise 8.13
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
What is one possible output of the following program?  

```C
1   #include "csapp.h"
2
3   int main()
4   {
5       int x = 3;
6
7       if (Fork() != 0)
8           printf("x=%d\n", ++x);
9
10      printf("x=%d\n", --x);
11      exit(0);
12  }
```  

---  

### ***Answear***:  
Father: 4, 3
Child: 2

