Exercise 2.85
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10 min*** :hourglass_flowing_sand:

---

### ***Question***:
intel-compatible processors also support an "extended precision" floating point format with an
80-bit word divided into a sign bit, k = 15 exponent bits, a single integer bit, and n = 63
fraction bits. The integer bit is an explicit copy of the implied bit in the IEEE floating point
representation. That is, it equals 1 for normalized values and 0 for denormalized values. Fill
in the following table giving the approximate values of some "interesting" number in this format:  
  
                     Extended Precision  
  

| Description                    |          Value          |       Decimal      |
|--------------------------------|:-----------------------:|:------------------:|
| Smallest positive denormalized | 0 0000…(15) 0 000…(62)1 | 2^(1-bias-63)      |
| Smallest positive normalized   | 0 000…(14)1 1 000….(63) | 2^(1-bias)         |
| Largest normalized             | 0 111…(14)0 1 111…(63)  | 2^bias * (2-2^-63) |


--- 

### ***Reference***:
[Copied from](https://dreamanddead.github.io/CSAPP-3e-Solutions/chapter2/2.86/)