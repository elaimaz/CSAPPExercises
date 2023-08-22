Exercise 2.82
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:

Consider numbers having a binary representation consisting of an infinite string of the form 0. y
y y y y y · · ·, where y is a k-bit sequence. For example, the binary representation of 1/3 is
0.01010101 · · · (y = 01), while the representation of 1/5 is 0.001100110011 · · · (y = 0011).  

A. Let Y = B2U<sub>k</sub>(y), that is, the number having binary representation y. Give a formula
in terms of Y and k for the value represented by the infinite string.  
**Hint:** Consider the effect of shifting the binary point k positions to the right.  
Answer:
    1. n = 0. y y y y y y · · ·
    2. n << k = y. y y y y y y · · · = Y + n
    3. n << k - n = Y
    4. n = Y/(2<sup>k</sup> - 1)

B. What is the numeric value of the string for the following values of y?  
    (a). 101  
&nbsp;&nbsp;&nbsp;&nbsp;Answer:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Y = 5  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k = 3  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;n = 5/7  
    (b). 0110  
&nbsp;&nbsp;&nbsp;&nbsp;Answer:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Y = 6  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k = 4  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;n = 2/5  
    (c). 010011  
&nbsp;&nbsp;&nbsp;&nbsp;Answer:  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Y = 19  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;k = 6  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;n = 19/63  


---

Copied from [here](https://www.bookstack.cn/read/CSAPP-3e-Solutions/chapter2-2.83.md)