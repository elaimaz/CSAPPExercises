Exercise 7.6
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following version of the swap.c function that counts the number of times it has been called:  

```c
1   extern int buf[];
2
3   int *bufp0 = &buf[0];
4   static int *bufp1;
5
6   static void incr()
7   {
8       static int count=0;
9
10      count++;
11  }
12
13  void swap()
14  {
15      int temp;
16
17      incr();
18      bufp1 = &buf[1];
19      temp = *bufp0;
20      *bufp0 = *bufp1;
21      *bufp1 = temp;
22  }
```  

For each symbol that is deﬁned and referenced in swap.o, indicate if it will have a symbol table entry in the .symtab section in module swap.o. If so, indicate the module that deﬁnes the symbol (swap.o or main.o), the symbol type (local, global, or extern), and the section (.text, .data, or .bss) it occupies in that module.  

| Symbol | swap.o .symtab entry? | Symbol type | Module where defined | Section |
|--------|-----------------------|-------------|----------------------|---------|
| buf    |                       |             |                      |         |
| bufp0  |                       |             |                      |         |
| bufp1  |                       |             |                      |         |
| swap   |                       |             |                      |         |
| temp   |                       |             |                      |         |
| incr   |                       |             |                      |         |
| count  |                       |             |                      |         |

---  

### ***Answear***:  

| Symbol | swap.o .symtab entry? | Symbol type | Module where defined | Section |
|--------|-----------------------|-------------|----------------------|---------|
| buf    |         YES           | extern      | main.o               | UND     |
| bufp0  |         YES           | global      | swap.o               | .data   |
| bufp1  |         YES           | global      | swap.o               | .bss    |
| swap   |         YES           | global      | swap.o               | .text   |
| temp   |         NO            |             |                      |         |
| incr   |         YES           | local       | swap.o               | .text   |
| count  |         YES           | local       | swap.o               | .bss    |
