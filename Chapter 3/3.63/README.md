Exercise 3.63
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following source code, where E1 and E2 are macro expressions declared with #define that compute the dimensions of array A in terms of parameter n. This code computes the sum of the elements of column j of the array.  

```
int sum_col(int n, int A[E1(n)][E2(n)], int j) {
	int i;
	int result = 0;
	for (i = 0; i < E1(n); i++)
		result += A[i][j]
	return result;
}
```  

When compiling this program GCC generates the following assembly code:  

```
	n at %ebp+8, A at %ebp+12, j at %ebp+16
1		movl		8(%ebp), %eax
2		leal		(%eax,%eax), %edx
3		leal		(%edx,%eax), %ecx
4		movl		%edx, %ebx
5		leal		1(%edx), %eax
6		movl		$0, %edx
7		testl		%eax, %eax
8		jle		.L3
9		leal		0(,%ecx,4), %esi
10		movl		16(%ebp), %edx
11		movl		12(%ebp), %ecx
12		leal		(%ecx,%edx,4), %eax
13		movl		$0, %edx
14		movl		$1, %ecx
15		addl		$2, %ebx
16	.L4
17		addl		(%eax), %edx
18		addl		$1, %ecx
19		addl		%esi, %eax
20		cmpl		%ebx, %ecx
21		jne		.L4
22	.L3
23		movl		%edx, %eax
```  

Use your reverse engineering skills to determine the definitions of E1 and E2.  

---  

### ***Draft***:  

```
	n at %ebp+8, A at %ebp+12, j at %ebp+16
1		movl		8(%ebp), %eax		;Get n
2		leal		(%eax,%eax), %edx	;edx = n + n
3		leal		(%edx,%eax), %ecx	;ecx = (n + n) + n
4		movl		%edx, %ebx		;ebx = n + n
5		leal		1(%edx), %eax		;Compute 1 + (n + n)
6		movl		$0, %edx		;Move 0 to edx (result)
7		testl		%eax, %eax		;test eax
8		jle		.L3			;jump if zero
9		leal		0(,%ecx,4), %esi	;Compute 4 * 3n
10		movl		16(%ebp), %edx		;Get j
11		movl		12(%ebp), %ecx		;Get A
12		leal		(%ecx,%edx,4), %eax	;Compute A + 4j
13		movl		$0, %edx		;Get 0
14		movl		$1, %ecx		;Get 1
15		addl		$2, %ebx		;Add 2 + 2n
16	.L4
17		addl		(%eax), %edx	;Add edx += A + 4j
18		addl		$1, %ecx		;Add ecx += 1
19		addl		%esi, %eax		;Add (4 * 3n) + (A + 4j)
20		cmpl		%ebx, %ecx		;Compare ecx and ebx
21		jne		.L4
22	.L3
23		movl		%edx, %eax		;Return result
```