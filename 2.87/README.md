Exercise 2.87
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following two 9-bit floating point representation based on the IEEE floating-point format.

1. Format A
    - There is one sign bit.
    - There are k = 5 exponent bits. The exponent bias is 15.
    - There are n = 3 fraction bits.

2. Format B
    - There is one sign bit.
    - There are k = 4 exponent bits. The exponent bias is 7.
    - There are n = 4 fraction bits.  


&nbsp;&nbsp;&nbsp;&nbsp;Below, you are given some bit patterns in Format A, and your task is to convert then to the closest value in Format B. If rounding is necessary you should round towards +&infin;. In addition, give the values of numbers given by the Format A and Format B bit patterns. Give these as whole numbers (e.g., 17) or as fractions (e.g., <sup>17</sup>&frasl;<sub>64</sub> or <sup>17</sup>&frasl;<sub>2<sup>6</sup></sub>).  

Format A  

| Bits                       |   Value                        |
|----------------------------|:------------------------------:|
| 1 01111 001                |<sup>-9</sup>&frasl;<sub>8</sub>|
| 0 10110 011                |                                |
| 1 00111 010                |                                |
| 0 00000 111                |                                |
| 1 11100 000                |                                |
| 0 10111 100                |                                |  


Format B

| Bits                       |   Value                        |
|----------------------------|:------------------------------:|
| 1 0111 0010                |<sup>-9</sup>&frasl;<sub>8</sub>|
|                            |                                |
|                            |                                |
|                            |                                |
|                            |                                |
|                            |                                |