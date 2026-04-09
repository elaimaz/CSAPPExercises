Exercise 8.15
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
How many “hello” lines does this program print?  

```C
1   #include "csapp.h"
2
3   void doit()
4   {
5       if (Fork() == 0) {
6           Fork();
7           printf("hello\n");
8           return;
9       }
10      return;
11  }
12
13  int main()
14  {
15      doit();
16      printf("hello\n");
17      exit(0);
18  }
```  

---  

### ***Answear***:  
5