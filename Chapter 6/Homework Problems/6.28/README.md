Exercise 6.28
==============

### ***Dificulty***: :star:

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
This problem concerns the cache in Problem 6.13.  

1. List all of the hex memory addresses that will hit in set 1.  

2. List all of the hex memory addresses that will hit in set 6.  

---  

### ***Answear***:  
1. 

$$ \text{A} = \text{T} * (\text{CO offset} * \text{CI offset}) + (\text{I} * 4) $$

---

$$ \text{A} = \text{0x45} * (2² * 2³) + (1 * 4) $$

$$ \text{A} = 69 * (2⁵) + 4 $$

$$ \text{A} = 69 * 32 + 4 $$

$$ \text{A} = 2208 + 4 $$

$$ \text{A} = 2212 $$

$$ \text{A} = \text{0x8A4} $$

$$ O_0 = \text{0x8A4} $$
$$ O_1 = \text{0x8A5} $$
$$ O_2 = \text{0x8A6} $$
$$ O_3 = \text{0x8A7} $$

---

$$ \text{A} = \text{0x38} * (2² * 2³) + (1 * 4) $$

$$ \text{A} = 56 * 2⁵ + 4 $$

$$ \text{A} = 1792 + 4 $$

$$ \text{A} = 1796 $$

$$ \text{A} = \text{0x704} $$

$$ O_0 = \text{0x704} $$
$$ O_1 = \text{0x705} $$
$$ O_2 = \text{0x706} $$
$$ O_3 = \text{0x707} $$

---

2. 

$$ \text{A} = \text{0x91} * (2² * 2³) + (6 * 4) $$

$$ \text{A} = 145 * (2⁵) + 24 $$

$$ \text{A} = 145 * 32 + 24 $$

$$ \text{A} = 4640 + 24 $$

$$ \text{A} = 4664 $$

$$ \text{A} = \text{0x1238} $$

$$ O_0 = \text{0x1238} $$
$$ O_1 = \text{0x1239} $$
$$ O_2 = \text{0x123A} $$
$$ O_3 = \text{0x123B} $$

---

obs; we use four Os, because in the exercise [Practice Problem 6.13](../../Practice%20Problems/Practice%20Problem%206.13/README.md) block size (B = 4).