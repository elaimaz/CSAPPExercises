### ***Practice Problem 9.6***:  
Determine the block sizes and header values that would result from the following sequence of malloc requests. Assumptions: (1) The allocator maintains double-word alignment, and uses an implicit free list with the block format from Figure 9.35. (2) Block sizes are rounded up to the nearest multiple of 8 bytes.  

| Request    | Block Size (decimal bytes) | Block header (hex) |
|:----------:|:--------------------------:|:------------------:|
| malloc(1)  |                            |                    |
| malloc(5)  |                            |                    |
| malloc(12) |                            |                    |
| malloc(13) |                            |                    |  

---  

### ***Answear***:  
  
| Request    | Block Size (decimal bytes) | Block header (hex) |
|:----------:|:--------------------------:|:------------------:|
| malloc(1)  | 8                          | 0x9                |
| malloc(5)  | 16                         | 0x11               |
| malloc(12) | 16                         | 0x11               |
| malloc(13) | 16                         | 0x19               |  


---  

malloc(1)


$$ \text{Block Size} = 1\text{ malloc(1)} + 4\text{ header size} $$
$$ \text{Block Size} = 5 $$
$$ \text{Rounding up to multiple of 8} = 8 $$

$$ \text{Block header} = \text{0x8 | 0x1} $$
$$ \text{Block header} = \text{0x9} $$


---  

malloc(5)

$$ \text{Block Size} = 5\text{ malloc(5)} + 4\text{ header size} $$
$$ \text{Block Size} = 9 $$
$$ \text{Rounding up to multiple of 8} = 16 $$

$$ \text{Block header} = \text{0x10 | 0x1} $$
$$ \text{Block header} = \text{0x11} $$


---  

malloc(12)

$$ \text{Block Size} = 12\text{ malloc(12)} + 4\text{ header size} $$
$$ \text{Block Size} = 16 $$
$$ \text{Rounding up to multiple of 8} = 16 $$

$$ \text{Block header} = \text{0x10 | 0x1} $$
$$ \text{Block header} = \text{0x11} $$


---  

malloc(13)

$$ \text{Block Size} = 13\text{ malloc(13)} + 4\text{ header size} $$
$$ \text{Block Size} = 17 $$
$$ \text{Rounding up to multiple of 8} = 24 $$

$$ \text{Block header} = \text{0x18 | 0x1} $$
$$ \text{Block header} = \text{0x19} $$