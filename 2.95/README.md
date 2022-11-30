Exercise 2.94
==============

### ***Dificulty***: :star: :star: :star: :star:

---

### ***Expected time***: ***10h*** :hourglass_flowing_sand:

---

### ***Question***:
Following the bit level floating point coding rules, implement the function with the following prototype:  

```
/*  
 * Compute (int)
 * if conversion causes overflow or f is NaN, return 0x80000000  
 */
float_bits float_f2i(float_bits f);
```  

For floating-point number f, this function computes (int) f. Your function should round toward zero. If f cannot be represented as an integer (e.g, it is out of range, or it is *NaN*), then the function should return 0x80000000.  
&nbsp;&nbsp;&nbsp;&nbsp;Test your function by evaluating it for all 2<sup>32</sup> values of argument f and comparing the result to what would be obtained using your machine's floating-point operations.