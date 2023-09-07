Exercise 3.58
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
The code that follows shows an example of branching on an enumareted type value in a switch statement. Recall that enumerated types in C are simply a way to introduce a set of names having associated integer values. By default, the values assigned to the names go from zero upward. In our code, the actions associated with the different case labels have been omitted.

```
/* Enumerated type creates set of constants numbered 0 and upward */
typedef enum (MODE_A, MODE_B, MODE_C, MODE_D, MODE_E) mode_t;

int switch3(int *pi, int *p2, mode_t action)
{
	int result = 0;
	switch (action) {
	case MODE_A:

	case MODE_B:

	case MODE_C:

	case MODE_D:

	case MODE_E:

	default:

	}
	return result;
}
```
 
&nbsp;&nbsp;&nbsp;&nbsp;The part generated assembly code implementing the different actions is shown in Figure 3.43. The annotations indicate the argument locations, the register values, and the case labels for the different jump destinations. Register %edx corresponds to program variable result and is initialized to -1.  
&nbsp;&nbsp;&nbsp;&nbsp;Fill in the missing parts of the C code. Watch out for cases that fall through.  

```
    Arguments: p1 at %ebp+8, p2 at %ebp+12, action at %ebp+16
    Registers: result in %edx (initialized to -1)
    The jump targets:
1   .L17							MODE_E
2       movl        $17, %edx
3       jmp         .L19
4   .L13:							MODE_A
5       movl        8(%ebp), %eax
6       movl        (%eax), %edx
7       movl        12(%ebp), %ecx
8       movl        (%ecx), %eax
9       movl        8(%ebp), %ecx
10      movl        %eax, (%ecx)
11      jmp         .L19
12  .L14:							MODE_B
13      movl        12(%ebp), %edx
14      movl        (%edx), %eax
15      movl        %eax, %edx
16      movl        8(%ebp), %ecx
17      addl        (%ecx), %edx
18      movl        12(%ebp), %eax
19      movl        %edx, (%eax)
20      jmp         .L19
21  .L15:							MODE_C
22      movl        12(%ebp), %edx
23      movl        $15, (%edx)
24      movl        8(%ebp), %ecx
25      movl        (%ecx), %edx
26      jmp         .L19
27  .L16							MODE_D
28      movl        8(%ebp), %edx
29      movl        (%edx), %eax
30      movl        12(%ebp), %ecx
31      movl        %eax, (%ecx)
32      movl        $17, %edx
33  .L19							default
34      movl        %edx, %eax					set return value
```
Figure 3.43 **Assembly code for problem 3.58.** This code implements the different braches of a switch statement.