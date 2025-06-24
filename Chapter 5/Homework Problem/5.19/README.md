Exercise 5.19
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
The library function memset has the following prototype:  

```c
void *memset(void *s, int c, size_t n);
```  

This function ﬁlls n bytes of the memory area starting at s with copies of the low-order byte of c. For example, it can be used to zero out a region of memory by giving argument 0 for c, but other values are possible.  

```c
1   /* Basic implementation of memset */
2   void *basic_memset(void *s, int c, size_t n)
3   {
4       size_t cnt = 0;
5       unsigned char *schar = s;
6       while (cnt < n) {
7           *schar++ = (unsigned char) c;
8           cnt++;
9       }
10      return s;
11  }
```  

&emsp;Implement a more efﬁcient version of the function by using a word of data type unsigned long to pack four (for IA32) or eight (for x86-64) copies of c, and then step through the region using word-level writes. You might ﬁnd it helpful to do additional loop unrolling as well. On an Intel Core i7 machine, we were able to reduce the CPE from 2.00 for the straightforward implementation to 0.25 for IA32 and 0.125 for x86-64, i.e., writing either 4 or 8 bytes on every clock cycle.  
&emsp;Here are some additional guidelines. In this discussion, let K denote the value of sizeof(unsigned long) for the machine on which you run your program.  

- You may not call any library functions.  
- our code should work for arbitrary values of n, including when it is not a multiple of K. You can do this in a manner similar to the way we ﬁnish the last few iterations with loop unrolling.  
- You should write your code so that it will compile and run correctly regardless of the value of K. Make use of the operation sizeof to do this.  
- On some machines, unaligned writes can be much slower than aligned ones. (On some non-x86 machines, they can even cause segmentation faults.) Write your code so that it starts with byte-level writes until the destination address is a multiple of K, then do word-level writes, and then (if necessary) ﬁnish with byte-level writes.  
- Beware of the case where cnt is small enough that the upper bounds on some of the loops become negative. With expressions involving the sizeof operator, the testing may be performed with unsigned arithmetic. (See Section 2.2.8 and Problem 2.72.)

---  

### ***Answear***:   
[main.c](./main.c).  

| Method           |      Buffer size      |  Time       |
|------------------|:---------------------:|------------:|
| basic_memset     |  10                   | 0.000002s   |
| cenhanced_memset |    10                 |   0.000001s |
| basic_memset     |  100                  | 0.000001s   |
| cenhanced_memset |    100                |   0.000001s |
| basic_memset     |  1000                 | 0.000004s   |
| cenhanced_memset |    1000               |   0.000002s |
| basic_memset     |  10000                | 0.000025s   |
| cenhanced_memset |    10000              |   0.000006s |
| basic_memset     |  100000               | 0.000243s   |
| cenhanced_memset |    100000             |   0.000060s |
| basic_memset     |  1000000              | 0.002346s   |
| cenhanced_memset |    1000000            |   0.000685s |
