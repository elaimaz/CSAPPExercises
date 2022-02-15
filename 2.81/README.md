Exercise 2.81
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10 min*** :hourglass_flowing_sand:

---

### ***Question***:

We are running programs on a machine where values of type int are 32 bits. they are represented in
two's complement, and they are right shifted arithmetically.  
Values of type unsigned are also 32 bits.  
&nbsp;&nbsp;&nbsp;&nbsp;We generate arbitrary values x and y, and convert then to unsigned values
as follows:

```
/* Create some arbitrary values */
int x = random();
int y = random();
/* Convert into unsigned */
unsigned ux = (unsigned) x;
unsigned uy = (unsigned) y;
```  
  
&nbsp;&nbsp;&nbsp;&nbsp;For each of the following C expressions you are indicate whether or not the
expression always yields 1. If it always yields 1, describe the underlying mathematical principles.
Otherwise, give an example of arguments that make it yield 0.  

A. (x<y) == (-x>-y)
B. ((x+y)<<4) + y-x == 17\*y+15\*x
C. -x+-y+1 == -(x+y)
D. (ux-uy) == -(unsigned)(y-x)
E. ((x >> 2) << 2) <= x    