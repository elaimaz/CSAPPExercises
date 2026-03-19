Exercise 7.15
==============

### ***Dificulty***: :star: :star: :star:  

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:

Performing the following tasks will help you become more familiar with the various tools for manipulating object ﬁles.

1. How many object ﬁles are contained in the versions of libc.a and libm.a on your system?  

2. Does gcc -O2 produce different executable code than gcc -O2 -g?  

3. What shared libraries does the gcc driver on your system use?  

---  

### ***Answear***:  

1. 
libc.a have 2211 files.
```bash
ar t /usr/lib/x86_64-linux-gnu/libc.a | wc -l
```
libm.a is not an static file on my system. so the linked file libm-2.39.a have 801 files.
```bash
at /usr/lib/x86_64-linux-gnu/libm.a
ar t /usr/lib/x86_64-linux-gnu/libm-2.39.a | wc -l
```  

2. No, the executable code will be the same, -g will add debug symbols, but the executable code will not be diferent. 

3. 
-lgcc
-lgcc_s
-lc  

```bash
gcc -v relo3.c 2>&1 | grep collect2
```  