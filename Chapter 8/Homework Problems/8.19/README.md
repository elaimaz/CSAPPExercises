Exercise 8.19
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
How many lines of output does the following function print? Give your answer as a function of n. Assume n ≥ 1.  

```C
1   void foo(int n)
2   {
3       int i;
4
5       for (i = 0; i < n; i++)
6           Fork();
7       printf("hello\n");
8       exit(0);
9   }
```  

---  

### ***Answear***:  
2<sup>n</sup>