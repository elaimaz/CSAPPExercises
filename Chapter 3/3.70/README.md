Exercise 3.70
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Using the same tree data structure we saw in [Problem 3.69](../3.69/README.md), and a function with the prototype    

```
long traverse(tree_ptr tp);
```  

GCC generates the following x86-64 code:  

```
1	traverse:
	tp in %rdi
2		movq		%rbx, -24(%rsp)
3		movq		%rbp, -16(%rsp)
4		movq		%r12, -8(%rsp)
5		subq		$24, %rsp
6		movq		%rdi, %rbp
7		movabslq	$-9223372036854775808, %rax
8		testq		%rdi, %rdi
9		je		.L9
10		movq		(%rdi), %rbx
11		movq		8(%rdi), %rdi
12		call		traverse
13		movq		%rax, %r12
14		movq		16(%rbp), %rdi
15		call		traverse
16		cmpq		%rax, %r12
17		cmovge		%r12, %rax
18		cmpq		%rbx, %rax
19		cmovl		%rbx, %rax
20	.L9:
21		movq		(%rsp), %rbx
22		movq		8(%rsp), %rbp
23		movq		16(%rsp), %r12
24		addq		$24, $rsp
25		ret
```  

1. Generate a C version of the function.
2. Explain in English what this function computes.  

---  

### ***Answear***:  

1. [Code](./main.c).
2. It runs throughout the tree and finds the biggest value.

