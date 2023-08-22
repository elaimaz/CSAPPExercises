Exercise 2.89
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10 min*** :hourglass_flowing_sand:

---

### ***Question***:
You have been assigned the task of writting a C function to compute a floating-point representation of 2<sup>x</sup>. You decide that the best way to do this is to directly construct the IEEE single-precision representation of the result. When x is too small, your routine will return 0.0. When x is too large, it will return +&infin;. Fill in the blank portions of the code that follows to compute the correct result. Assume the function u2f returns a floating point value having an identical bit representation as its unsigned argument.  


```
float fpwr2(int x)
{
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;

	if (x < -149) {
		/* Too small, Return 0.0 */
		exp = 0;
		frac = 0;
	} else if (x < -126) {
		/* Denormalized result */
		exp = 0;
		frac = 1 << (unsigned) (x + 149);
	} else if (x < 128) {
		/* Normalized result */
		exp = x + 127;
		frac = 0;
	} else {
		/* Too big. Return +oo */
		exp = 0xFF;
		frac = 0;
	}

	/* Pack exp and frac into 32 bits */
	u = exp << 23 | frac;
	/* Return as float */
	return u2f(u);
}
```

note: this answers were inspired by [this page](https://valineliu.gitbook.io/deuterium-wiki/reading/cs-jing-dian-shu-ji/csapp-3e-homework-solution/2.-representing-and-manipulating-information/2.90-fpwr2)

