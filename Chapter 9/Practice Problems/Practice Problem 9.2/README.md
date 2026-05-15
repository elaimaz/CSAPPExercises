### ***Practice Problem 9.2***:  
Determine the number of page table entries (PTEs) that are needed for the following combinations of virtual address size (n) and page size (P):  

| n  | P = 2<sup>p</sup> | No. PTEs |
|:--:|:-----------------:|:--------:|
| 16 | 4K                |          |
| 16 | 8K                |          |
| 32 | 4K                |          |
| 32 | 8K                |          |  

---  

### ***Answear***:  

Since each virtual page is P = 2<sup>p</sup> bytes, there are a total of 2<sup>n</sup>/2<sup>p</sup> = 2<sup>n−p</sup> possible pages in the system, each of which needs a page table entry (PTE).

| n  | P = 2<sup>p</sup> | No. PTEs |
|:--:|:-----------------:|:--------:|
| 16 | 4K                | 16       |
| 16 | 8K                | 8        |
| 32 | 4K                | 1M       |
| 32 | 8K                | 512K     |  