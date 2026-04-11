Exercise 8.18
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following program:  

```C
1   #include "csapp.h"
2
3   void end(void)
4   {
5       printf("2");
6   }
7
8   int main()
9   {
10      if (Fork() == 0)
11          atexit(end);
12      if (Fork() == 0)
13          printf("0");
14      else
15          printf("1");
16      exit(0);
17  }
```  

Determine which of the following outputs are possible. Note: The atexit function takes a pointer to a function and adds it to a list of functions (initially empty) that will be called when the exit function is called.  

1. 112002
2. 211020
3. 102120
4. 122001
5. 100212

---  

### ***Answear***:  
1. Valid
2. Invalid
3. Valid
4. Invalid
5. Valid

[Code by AI (GPT-5.4)](./main.c)