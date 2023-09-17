Exercise 3.60
==============

### ***Dificulty***: :star: :star: :star:

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following source code, where R, S, and T are constants declared with #define:  

```
int A[R][S][T];

int store_ele(int i, int j, int k, int *dest)
{
	*dest = A[i][j][k];
	return sizeof(A);
}
```
 
&nbsp;&nbsp;&nbsp;&nbsp;In compiling this program, GCC generates the following assembly code:  

```
	i at %ebp+8, j at ebp+12, k at %ebp+16, dest at %ebp+20
1		movl		12(%ebp), %edx
2		leal		(%edx,%edx,4), %eax
3		leal		(%edx,%eax,2), %eax
4		imull		$99, 8(%ebp), %edx
5		addl		%edx, %eax
6		addl		16(%ebp), %eax
7		movl		A(,%eax,4), %edx
8		movl		20(%ebp), %eax
9		movl		%edx, (%eax)
10		movl		$1980, %eax
```  

1. Extend Equation 3.1 from two dimensions to three to provide a formula for the location of array element A[i][j][k].
2. Use your reverse engineering skills to determine the values of R, S, and T based on the assembly code.  

---

### ***Answer***:  

1. A + 4*(T * S * i + T * j + k)  
2. 

```
	i at %ebp+8, j at ebp+12, k at %ebp+16, dest at %ebp+20
1		movl		12(%ebp), %edx			;Get j
2		leal		(%edx,%edx,4), %eax		;Compute j + j * 4
3		leal		(%edx,%eax,2), %eax		;Compute j + 5j * 2 
4		imull		$99, 8(%ebp), %edx		;Multiply i * 99
5		addl		%edx, %eax				;Add 11j + 99i
6		addl		16(%ebp), %eax			;Add 11j + 99i + k
7		movl		A(,%eax,4), %edx		;A + 44j + 396i + 4k
8		movl		20(%ebp), %eax			;Get dest
9		movl		%edx, (%eax)			;Store A + 44j + 396i + 4k
10		movl		$1980, %eax				;Get 1980 as result
```  

T = 11  
R = 5  
S = 9