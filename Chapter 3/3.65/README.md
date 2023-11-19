Exercise 3.64
==============

### ***Dificulty***: :star: :star: :star:

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
In the following code. A and B are constants defined with #define:  

```
typedef struct {
	short x[A][B]; /* Unknown constants A and B */
	int y;
} str1;

typedef struct {
	char array [B];
	int t;
	short s[B];
	int u;
} str2;

void setVal(str1 *p, str2 *q) {
	int v1 = q->t;
	int v2 = q->u;
	p->y = v1+v2;
}
```  

GCC generates the following code for the body of setVal:  

```
1		movl		12(%ebp), %eax
2		movl		36(%eax), %edx
3		addl		12(%eax), %edx
4		movl		8(%ebp), %eax
5		movl		%edx, 92(%eax)
```  

&nbsp;&nbsp;&nbsp;&nbsp;What are the values of A and B? (The solution is unique)

---

### ***Answear***:  
B = 12  
A = 14


