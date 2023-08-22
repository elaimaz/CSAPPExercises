Exercise 2.84
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10 min*** :hourglass_flowing_sand:

---

### ***Question***:
Given a floating-point format with a k-bit exponent and n-bit fraction, write formulas for the
exponent *E*, significand *M*, the fraction f, and the value V for the quantities that follow. In
addition, describe the bit representation.

A. The number 7.0  
R: 111.00<sub>2</sub>  
M: 1.11  
f: 0.11  
E: 2  
e: bias + E  
V: 7.0
B. The largest odd integer that can be represented exactly  
R: bias + n 11111...  
M: 1.11111....  
f: 0.11111...(n bits 1)  
E: n  
V: 111111...(n+1 bits 1)

C. The reciprocal of the smallest positive normalized value.  
R: 0 11...101 00000....  
M: 1.00....  
f: 0.000....  
E: 1 - bias  
e: bias + E  

---

[Reference](https://www.mianquan.net/tutorial/CSAPP-3e-Solutions/chapter2-2.85.md)
