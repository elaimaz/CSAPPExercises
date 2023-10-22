Exercise 3.64
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
For this exercise, we will examine the code generated by GCC for functions that have structures as arguments and return values, and from this see how these language features are typically implemented.  
&nbsp;&nbsp;&nbsp;&nbsp;The following C code has a function word_sum having structures as argument and return values and a function prod that calls word_sum:  

```
typedef struct {
	int a;
	int *p;
} str1;

typedef struct {
	int sum;
	int diff;
} str2;

str2 word_sum(str1 s1) {
	str2 result;
	result.sum = s1.a + *s1.p;
	result.diff = s1.a - *s1.p;
	return result;
}

int prod(int x, int y)
{
	str1 s1;
	str2 s2;
	s1.a = x;
	s1.p = &y;
	s2 = word_sum(s1);
	return s2.sum * s2.diff;
}
```  

GCC generates the following code for these two functions:  

```
1	word_sum:
2		pushl		%ebp
3		movl		%esp, %ebp
4		pushl		%ebx
5		movl		8(%ebp), %eax
6		movl		12(%ebp), %ebx
7		movl		16(%ebp), %edx
8		movl		(%edx), %edx
9		movl		%ebx, %ecx
10		subl		%edx, %ecx
11		movl		%ecx, 4(%eax)
12		addl		%ebx, %edx
13		movl		%edx, (%eax)
14		popl		%ebx
15		popl		%ebp
16		ret		$4
```  

```
1	prod:
2		pushl		%ebp
3		movl		%esp, %ebp
4		subl		$20, %esp
5		leal		12(%ebp), %edx
6		leal		-8(%ebp), %ecx
7		movl		8(%ebp), %eax
8		movl		%eax, 4(%esp)
9		movl		%edx, 8(%esp)
10		movl		%ecx, (%esp)
11		call		word_sum
12		subl		$4, %esp
13		movl		-4(%ebp), %eax
14		imull		-8(%ebp), %eax
15		leave
16		ret
```
&nbsp;&nbsp;&nbsp;&nbsp;The instruction ret $4 is like a normal return instruction, but it increments the stack pointer by 8 (4 for the return address plus 4 additional), rather than 4.  

1. We can see in lines 5-7 of the code for word_sum that it appears as if three values are being retrieved from the stack, even though the function has only a single argument. Describe what these three values are.
2. We can see in line 4 of the code for prod that 20 bytes are allocated in the stack frame. These get used as five fields of 4 bytes each. Describe how each of these fields gets used.
3. How would you describe the general strategy for passing structures as arguments to a function?
3. How would you describe the general strategy for handling a structure as a return value from a function?