Exercise 2.91
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
Following the bit-level floating-point coding rules, implement the function with the following prototype:  

```
/* Compute -f. If f is NaN, then return f. */
float_bits float_negate(float_bits f);
```  

For floating-point number f, this function computes -f. If f is NaN, your function should simply return f.  
&nbsp;&nbsp;&nbsp;&nbsp;Test your function by evaluating it for all 2<sup>32</sup> values of argument f and comparing the result to what would be obtained using your machine's floating-point operations.  

note: this answers were inspired by [this page](https://github.com/agelessman/csapp-3e-solutions/blob/master/%E7%AC%AC%E4%BA%8C%E7%AB%A0%E7%AD%94%E6%A1%88/2.92.c)