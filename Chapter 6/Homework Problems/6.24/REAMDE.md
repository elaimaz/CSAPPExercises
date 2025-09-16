Exercise 6.24
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
Estimate the average time (in ms) to access a sector on the following disk:  

| Parameter               | Value     |
|-------------------------|-----------|
| Rotation rate           | 15000 RPM |
| T<sub>avg seek</sub>    |   4 ms    |
| Average # sectors/track |   800     |

---  

### ***Answear***:  

$$ T_\text{max rotation} = \frac{1}{\text{RPM}} * \frac{60 \text{ secs}}{1 \text{ min}} $$

$$ T_\text{max rotation} = \frac{1}{15000\text{RPM}} * \frac{60 \text{ secs}}{1 \text{ min}} $$

$$ T_\text{max rotation} = \frac{60}{15000} $$

$$ T_\text{max rotation} = 0.004\text{ secs} $$

$$ T_\text{max rotation} = 4\text{ ms} $$

---

$$ T_\text{avg rotation} = \frac{1}{2} * T_\text{max rotation} $$

$$ T_\text{avg rotation} = \frac{1}{2} * 4\text{ ms} $$

$$ T_\text{avg rotation} = 2\text{ ms} $$

---

$$ T_\text{avg transfer} = \frac{60}{15000\text{ RPM}} * \frac{1}{800\text{ sectors/track}} * 1000\text{ ms/sec} $$

$$ T_\text{avg transfer} = \frac{60000}{12000000} $$

$$ T_\text{avg transfer} = \frac{60000}{12000000} $$

$$ 0.005\text{ ms} $$

---

$$ T_\text{access} = T_\text{avg seek} + T_\text{avg rotation} + T_\text{avg transfer} $$

$$ T_\text{access} = 4\text{ ms} + 2\text{ ms} + 0.005\text{ ms} $$

$$ T_\text{access} = 6.005\text{ ms} $$