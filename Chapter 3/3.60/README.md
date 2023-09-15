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