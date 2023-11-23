Exercise 3.67
==============

### ***Dificulty***: :star: :star: :star:

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following union declaration:    

```
union ele {
	struct {
		int *p;
		int y;
	} e1;
	struct {
		int x;
		union ele *next;
	} e2;
};
```  

This declaration illustrates that structures can be embedded within unions.  
&nbsp;&nbsp;&nbsp;&nbsp;The following procedure (with some expressions omitted) operates on a linked list having these unions as list elements:

```
void proc (union ele *up)
{
	up->_____________ = *(up->_____________) - up->_____________;
}
```  

1. What would be the offsets (in bytes) of the following fields:  

```
	e1.p:
	e1.y:
	e2.x;
	e2.next:
```  
2. How many total bytes would the structure require?
3. The compiler generates the following assembly code for the body of proc:  

```
	up at %ebp+8
1		movl		8(%ebp), %edx
2		movl		4(%edx), %ecx
3		movl		(%ecx), %eax
4		movl		(%eax), %eax
5		subl		(%edx), %eax
6		movl		%eax, 4(%ecx)
```  
On the basis of this information, fill in the missing expressions in the code for proc **Hint:** Some union references can have ambiguous interpretations. These ambiguities get resolved as you see where the references lead. There is only one answear that does not perform any casting and does not violate any type constraints.



