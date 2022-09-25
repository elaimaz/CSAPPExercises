Exercise 2.88
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10 min*** :hourglass_flowing_sand:

---

### ***Question***:
We are running programs on a machine where values of type int have a 32-bit two's-complement representation. Values of type float use the 32-bit IEEE format, and values of type double use the 64-bit IEEE format.  
&nbsp;&nbsp;&nbsp;&nbsp;We generate arbitrary integer values x, y, and z, and convert them to values of type double as follows:  
```
/* Create some arbitrary values */
int x = random();
int y = random();
int z = random();
/* Convert to double */
double dx = (double) x;
double dy = (double) y;
double dz = (double) z;
```  
&nbsp;&nbsp;&nbsp;&nbsp;For each of the following C expressions, you are to indicate whether or not the expression *always* yields 1. If it always yields 1, describe the underlying mathematical principles. Otherwise, give an example of arguments that make it yield 0. Note that you cannot use IA32 machine running GCC to test your answers, since it would use the 80-bit extended precision representation for both float and double.  
1. (float) x == (float) dx  
- Answer: It always will yields 1 because bits will not be lost between the casting
2. dx - dy == (double) (x-y)  
- Answer: 0 and INT_MIN
3. (dx + dy) + dz == dx + (dy + dz)  
- Answer: Will yied 1 because bits will not be lost converting int to double
4. (dx * dy) * dz == dx * (dy * dz)  
- Answer: 0x64e73387, 0xd31cb264, 0xd22f1fcd
5. dx/dx == dz/dz  
- +0.0  


Obs: the fourth item i copied from: https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.89/
