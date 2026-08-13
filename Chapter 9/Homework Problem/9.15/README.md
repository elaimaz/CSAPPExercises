Exercise 9.15
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:  

---

### ***Question***:
Determine the block sizes and header values that would result from the following sequence of malloc requests. Assumptions: (1) The allocator maintains double-word alignment, and uses an implicit free list with the block format from Figure 9.35. (2) Block sizes are rounded up to the nearest multiple of 8 bytes.  

| Request    | Block size (decimal bytes) | Block header (hex) |
|:----------:|:--------------------------:|:------------------:|
| malloc(3)  |                            |                    |
| malloc(11) |                            |                    |
| malloc(20) |                            |                    |
| malloc(21) |                            |                    |  

---  

### ***Answear***:  

| Request    | Block size (decimal bytes) | Block header (hex) |
|:----------:|:--------------------------:|:------------------:|
| malloc(3)  | 8                          | 0x9                |
| malloc(11) | 16                         | 0x17               |
| malloc(20) | 24                         | 0x25               |
| malloc(21) | 32                         | 0x33               |  

---

malloc(3)


$$ \text{Block Size} = 3\text{ malloc(3)} + 4\text{ header size} $$
$$ \text{Block Size} = 7 $$
$$ \text{Rounding up to multiple of 8} = 8 $$

$$ \text{Block header in hex} = \text{8} $$
$$ \text{Block header in hex} = \text{0x8} $$

$$ \text{Block header} = \text{0x8 | 0x1} $$
$$ \text{Block header} = \text{0x9} $$


---  

malloc (11)

$$ \text{Block Size} = 11\text{ malloc(11)} + 4\text{ header size} $$
$$ \text{Block Size} = 15 $$
$$ \text{Rounding up to multiple of 8} = 16 $$

$$ \text{Block header in hex} = \text{16} $$
$$ \text{Block header in hex} = \text{0x10} $$

$$ \text{Block header} = \text{0x10 | 0x1} $$
$$ \text{Block header} = \text{0x11} $$

---  

malloc (20)

$$ \text{Block Size} = 20\text{ malloc(20)} + 4\text{ header size} $$
$$ \text{Block Size} = 24 $$
$$ \text{Rounding up to multiple of 8} = 24 $$

$$ \text{Block header in hex} = \text{24} $$
$$ \text{Block header in hex} = \text{0x18} $$

$$ \text{Block header} = \text{0x18 | 0x1} $$
$$ \text{Block header} = \text{0x19} $$

---  

malloc (21)

$$ \text{Block Size} = 21\text{ malloc(20)} + 4\text{ header size} $$
$$ \text{Block Size} = 25 $$
$$ \text{Rounding up to multiple of 8} = 32 $$

$$ \text{Block header in hex} = \text{32} $$
$$ \text{Block header in hex} = \text{0x20} $$

$$ \text{Block header} = \text{0x20 | 0x1} $$
$$ \text{Block header} = \text{0x21} $$