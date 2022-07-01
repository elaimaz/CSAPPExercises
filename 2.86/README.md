Exercise 2.86
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10 min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider is a 16-bit floating-point representation based on the IEEE floating-point format, with one sign bit, seven exponent bits (k = 7), and eight fraction bits (n = 8). The exponent bias is 2<sup>7 - 1</sup> - 1 = 63.  
&nbsp;&nbsp;&nbsp;&nbsp;Fill in the table that follows for each of the numbers given, with the following instructions for each column:

&nbsp;&nbsp;&nbsp;&nbsp;Hex: The four hexadecimal digits describing the encoded form.  
&nbsp;&nbsp;&nbsp;&nbsp;M: The value of the significand. This should be a number of the form x or <sup>x</sup>&frasl;<sub>y</sub>, where x is a integer, and y is an integral power of 2. Examples include: 0, <sup>67</sup>&frasl;<sub>64</sub> and <sup>1</sup>&frasl;<sub>256</sub>.  
&nbsp;&nbsp;&nbsp;&nbsp;E: The integer value of the exponent.  
&nbsp;&nbsp;&nbsp;&nbsp;V: The numeric value represented. Use the notation x or x * 2<sup>z</sup>, where x and z are integers.  


&nbsp;&nbsp;&nbsp;&nbsp;As an example, to represent the number <sup>7</sup>&frasl;<sub>8</sub>, we would have s = 0, M = <sup>7</sup>&frasl;<sub>4</sub>, and E = -1. Our number would therefore have an exponent field of 0x3E (decimal value 63 - 1 = 62) and a significand field 0xC0 (binary 11000000<sub>2</sub>), giving a hex representation 3EC0.  
&nbsp;&nbsp;&nbsp;&nbsp;You need not fill in entries marked "&#9472;".  

| Description                       |   Hex    |     M    |     E    |     V    |
|-----------------------------------|:--------:|:--------:|:--------:|:--------:|
| -0                                |8000|<sup>0</sup>&frasl;<sub>256</sub>|-62|&#9472;|
| Smallest valor > 2                |          |          |          |          |
| 512                               |          |          |          |  &#9472; |
| Largest denormalized              |00FF|<sup>255</sup>&frasl;<sub>256</sub>|-62|<sup>0</sup>&frasl;<sub>256</sub> * <sup>1</sup>&frasl;<sub>2<sup>62</sup></sub>|
| -&infin;                          |FF00|  &#9472; |  &#9472; |  &#9472; |
|Number with hex representation 3BB0|&#9472;|<sup>235</sup>&frasl;<sub>256</sub>|-4|<sup>235</sup>&frasl;<sub>3776</sub>|



*I am not sure about this answers. I checked other people results and they all are different from mine.
