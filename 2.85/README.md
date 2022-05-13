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
representation. That is, it equals 1 for normlized values and 0 for denormalized values. Fill
in the following table giving the approximate values of some "interesting" number in this format:  
  
                     Extended Precision  
  

| Description                    |  Value   |  Decimal  |
|--------------------------------|:--------:| :------:  |
| Smallest positive denormalized |0 000000000000000 000...001|2<sup>1 - bias - 63</sup>           |
| Smallest positive normalized   |0 000000000000001 000...001|2<sup>1 - 63</sup>           |
| Largest normalized             |0 111111111111110 111...111|2<sup>bias * (2 - 2 <sup>-63</sup>)</sup>           |