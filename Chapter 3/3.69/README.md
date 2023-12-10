Exercise 3.69
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
The following declaration defines a class of structures for use in constructing binary trees:  

```
typedef struct ELE *tree_ptr;

struct ELE {
    long val;
    tree_ptr left;
    tree_ptr right;
};
```  

&nbsp;&nbsp;&nbsp;&nbsp;For a function with the following prototype:  

```
long trace(tree_ptr tp);
```  

GCC generates the following x86-64 code:  

```
1       trace:
    tp in %rdi
2       movl        $0, %eax
3       testq       %rdi, %rdi
4       je      .L3
5   .L5
6       movq        (%rdi), %rax
7       movq        16(%rdi), %rdi
8       testq       %rdi, %rdi
9       jne         .L5
10  .L3:
11      rep
12      ret
```  

1. Generate a C version of the function, using a while loop.
2. Explain in English what this function computes.

---

### ***Answear***:  
1. [Code](./main.c).
2. It goes to the last rightmost node in the tree.
