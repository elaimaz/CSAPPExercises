Exercise 3.66
==============

### ***Dificulty***: :star: :star: :star:

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
You are charged with maintaning a large C program, and you come across the following code:    

```
typedef struct {
	int left;
	a_struct a[CNT];
	int right;
} b_struct;

void test(int i, b_struct *bp)
{
	int n = bp->left + bp->right;
	a_struct *ap = &bp->a[i];
	ap->x[ap->idx] = n;
}
```  

```
1	00000000	<test>
2		0:		55			push		%ebp
3		1:		89 e5			mov		%esp,%ebp
4		3:		8b 45 08		mov		0x8(%ebp),%eax
5		6:		8b 4d 0c		mov		0xc(%ebp),%ecx
6		9:		8d 04 80		lea		(%eax,%eax,4),%eax
7		c:		03 44 81 04		add		0x4(%ecx,%eax,4),%eax
8		10:		8b 91 b8 00 00 00	mov		0xb8(%ecx),%edx
9		16:		03 11			add		(%ecx),%edx
10		18:		89 54 81 08		mov		%edx,0x8(%ecx,%eax,4)
11		1c:		5d			pop		%ebp
12		1d:		c3			ret
```  
**Disassembled code for problem 3.66**

&nbsp;&nbsp;&nbsp;&nbsp;The declarations of the compile-time constant CNT and the structure a_struct are in a file for which you do not have the necessary access privilege. Fortunately, you have a copy of the '.o' version of code, which you are able to disassemble with the OBJDUMP program, yielding the disassemble shown in the code above.  
&nbsp;&nbsp;&nbsp;&nbsp;Using your reverse engineering skills deduce the following.  

1. The value of CNT
2. A complete declaration of structure a_struct. Assume that the only fields in this structure as idx and x. 

---

### ***Answear***:  
1. 9
2. 
```
	typedef struct {
		int idx;
		int x[4];
	}
``` 

---

### ***Notes***:  

Based on [edwinfj solution](https://github.com/edwinfj/csapp-2e-solution/blob/master/practice/c3/p3.66)



