Exercise 2.92
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
Following the bit level floating point coding rules, implement the function with the following prototype:  

```
/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f);
```  

For floating-point number f, this function computes |f|. If f is NaN, your functions should simply return f.  
&nbsp;&nbsp;&nbsp;&nbsp;Test your function by evaluating it for all 2<sup>32</sup> values of argument f and comparing the result to what would be obtained using your machine's floating point operations.