Exercise 8.21
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
What are the possible output sequences from the following program?  

```C
1   int main()
2   {
3       if (fork() == 0) {
4           printf("a");
5           exit(0);
6       }
7       else {
8           printf("b");
9           waitpid(-1, NULL, 0);
10      }
11      printf("c");
12      exit(0);
13  }
```  

---  

### ***Answear***:  
abc
bac