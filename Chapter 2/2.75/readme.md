Exercise 2.75
==============

### ***Dificulty***: :star: :star: :star:

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:

Suppose we want to compute the complete 2w-bit representation of x · y, where both x and y are
unsigned, on a machine for which data type unsigned is w bits. The low-order w bits of the product
can be computed with the expression x*y, so we only require a procedure with prototype

```
unsigned int unsigned_high_prod(unsigned x, unsigned y);
```

That computes the high-order w bits of x · y for unsigned variables.  
&nbsp;We have access to a library function with prototype

```
int signed_high_prod(int x, int y);
```

that computes the high order w bits of x · y for the case where x and y are in two's complement
form. Write code calling this procedure to implement the function for unsigned arguments. Justify
the correctness of your solution.  


&nbsp;**Hint:** Look at the relantionship between the signed product x · y and the unsigned product
x' · y' in the derivation of Equation 2.18