Exercise 6.29
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
This problem concerns the cache in [Problem 6.13](../../Practice%20Problems/Practice%20Problem%206.13/README.md).  

1. List all of the hex memory addresses that will hit in set 2.  

2. List all of the hex memory addresses that will hit in set 4.  

3. List all of the hex memory addresses that will hit in set 5.  

4. List all of the hex memory addresses that will hit in set 7.  
---  

### ***Answear***:  
1. None memory will be hit.  

---

2. 

$$ \text{A} = \text{T} * (\text{CO offset} * \text{CI offset}) + (\text{I} * 4) $$

$$ \text{A} = \text{0xC7} * (2² * 2³) + (4 * 4) $$

$$ \text{A} = 199 * (2⁵) + 16 $$

$$ \text{A} = 199 * 32 + 16 $$

$$ \text{A} = 6368 + 16 $$

$$ \text{A} = 6384 $$

$$ \text{A} = \text{0x18F0} $$

$$ O_0 = \text{0x18F0} $$
$$ O_1 = \text{0x18F1} $$
$$ O_2 = \text{0x18F2} $$
$$ O_3 = \text{0x18F3} $$

---

$$ \text{A} = \text{T} * (\text{CO offset} * \text{CI offset}) + (\text{I} * 4) $$

$$ \text{A} = \text{0x05} * (2² * 2³) + (4 * 4) $$

$$ \text{A} = 5 * (2⁵) + 16 $$

$$ \text{A} = 5 * 32 + 16 $$

$$ \text{A} = 160 + 16 $$

$$ \text{A} = 176 $$

$$ \text{A} = \text{0xB0} $$

$$ O_0 = \text{0xB0} $$
$$ O_1 = \text{0xB1} $$
$$ O_2 = \text{0xB2} $$
$$ O_3 = \text{0xB3} $$

---  

3. 

$$ \text{A} = \text{T} * (\text{CO offset} * \text{CI offset}) + (\text{I} * 4) $$

$$ \text{A} = \text{0x71} * (2² * 2³) + (5 * 4) $$

$$ \text{A} = 113 * (2⁵) + 20 $$

$$ \text{A} = 113 * 32 + 20 $$

$$ \text{A} = 3616 + 20 $$

$$ \text{A} = 3636 $$

$$ \text{A} = \text{0xE34} $$

$$ O_0 = \text{0xE34} $$
$$ O_1 = \text{0xE35} $$
$$ O_2 = \text{0xE36} $$
$$ O_3 = \text{0xE37} $$

---  

4. 

$$ \text{A} = \text{T} * (\text{CO offset} * \text{CI offset}) + (\text{I} * 4) $$

$$ \text{A} = \text{0xDE} * (2² * 2³) + (7 * 4) $$

$$ \text{A} = 222 * (2⁵) + 28 $$

$$ \text{A} = 222 * 32 + 28 $$

$$ \text{A} = 7104 + 28 $$

$$ \text{A} = 7132 $$

$$ \text{A} = \text{0x1BDC} $$

$$ O_0 = \text{0x1BDC} $$
$$ O_1 = \text{0x1BDD} $$
$$ O_2 = \text{0x1BDE} $$
$$ O_3 = \text{0x1BDF} $$

---

obs; we use four Os, because in the exercise [Practice Problem 6.13](../../Practice%20Problems/Practice%20Problem%206.13/README.md) block size (B = 4).