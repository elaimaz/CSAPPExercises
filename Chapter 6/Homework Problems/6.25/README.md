Exercise 6.25
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Suppose that a 2 MB ﬁle consisting of 512-byte logical blocks is stored on a disk drive with the following characteristics:    

| Parameter               | Value     |
|-------------------------|-----------|
| Rotation rate           | 15000 RPM |
| T<sub>avg seek</sub>    |   4 ms    |
| Average # sectors/track |   1000    |
| Surfaces                |   8       |
| Sector size             | 512 bytes |  

For each case below, suppose that a program reads the logical blocks of the ﬁle sequentially, one after the other, and that the time to position the head over the ﬁrst block is T<sub>avg seek</sub> + T<sub>avg rotation</sub>  

1. Best case: Estimate the optimal time (in ms) required to read the ﬁle over all possible mappings of logical blocks to disk sectors.  

2. Random case: Estimate the time (in ms) required to read the ﬁle if blocks are mapped randomly to disk sectors.

---  

### ***Answear***:  

$$ \text{Number of sectors} = \frac{2^{20} * 2}{512\text{ bytes}} $$

$$ \text{Number of sectors} = \frac{2097152}{512\text{ bytes}} $$

$$ \text{Number of sectors} = \frac{2097152}{512\text{ bytes}} $$

$$ \text{Number of sectors} = 4096 $$

$$ \text{Number of sectors} \approx 4000 $$

---

$$ T_\text{max rotation} =  \frac{1}{15000\text{ RPM}} * \frac{60 \text{ secs}}{1 \text{ min}} $$

$$ T_\text{max rotation} =  \frac{60}{15000\text{ RPM}} $$

$$ T_\text{max rotation} =  0.004\text{  secs} $$

$$ T_\text{max rotation} =  0.004\text{  secs} * 1000 $$

$$ T_\text{max rotation} = 4\text{ ms} $$

---

$$ T_\text{avg rotation} = \frac{1}{2} * T_\text{max rotation} $$

$$ T_\text{avg rotation} = \frac{1}{2} * 4\text{ ms} $$

$$ T_\text{avg rotation} = 2\text{ ms} $$

---

$$ T_\text{avg seek} + T_\text{avg rotation} + 4 * T_\text{max rotation} $$

$$ 4\text{ ms} + 2\text{ ms} + 4 * 4\text{ secs} $$

$$ 6\text{ ms} + 16\text{ ms} $$

$$ 22\text{ ms} $$

---


2. 

$$ (T_\text{avg seek} + T_\text{avg rotation}) * 4000 $$

$$ (4\text{ ms} + 2\text{ ms}) * 4000 $$

$$ 6\text{ ms} * 4000 $$

$$ 24000\text{ secs} $$

$$ \frac{24000\text{ secs}}{1000} $$

$$ 24\text{ secs} $$