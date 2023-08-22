Exercise 2.73
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:

Write code for a function with the following prototype:

```
/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y);
```

&nbsp;Instead of overflowing the way normal two's complement addition does, saturating addition
returns TMax when there would be positive overflow, and TMin when there would ve negative overflow.
Saturating arithmetic is commonly used in programs that perform digital signal processing.  
&nbsp;Your function should follow the bit level integer
[coding rules (page 120)](../Utils/CH2Rules.txt).
