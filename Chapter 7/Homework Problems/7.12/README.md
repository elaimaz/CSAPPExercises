Exercise 7.12
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:

The swap routine in Figure 7.10 contains ﬁve relocated references. For each relocated reference, give its line number in Figure 7.10, its run-time memory address, and its value. The original code and relocation entries in the swap.o module are shown in Figure 7.19.  

```asm
00000000 <swap>:
0:   55                      push   %ebp
1:   8b 15 00 00 00 00       mov    0x0,%edx              # Get *bufp0 = &buf[0]
3:                           R_386_32 bufp0               # Relocation entry

7:   a1 04 00 00 00          mov    0x4,%eax              # Get buf[1]
8:                           R_386_32 buf                 # Relocation entry

c:   89 e5                   mov    %esp,%ebp

e:   c7 05 00 00 00 00 04    movl   $0x4,0x0              # bufp1 = &buf[1]
15:  00 00 00
10:                          R_386_32 bufp1               # Relocation entry
14:                          R_386_32 buf                 # Relocation entry

18:  89 ec                   mov    %ebp,%esp

1a:  8b 0a                   mov    (%edx),%ecx           # temp = buf[0]
1c:  89 02                   mov    %eax,(%edx)           # buf[0] = buf[1]

1e:  a1 00 00 00 00          mov    0x0,%eax              # Get *bufp1 = &buf[1]
1f:                          R_386_32 bufp1               # Relocation entry

23:  89 08                   mov    %ecx,(%eax)           # buf[1] = temp
25:  5d                      pop    %ebp
26:  c3                      ret
```  
**Figure 7.19** Code and relocation entries for Problem 7.12  

| Line # in Fig 7.10 | Address | Value |
|--------------------|---------|-------|
|                    |         |       |
|                    |         |       |
|                    |         |       |
|                    |         |       |  


---  

### ***Answear***:  

| Line # in Fig 7.10 | Address | Value       |
|--------------------|---------|-------------|
| 15                 | 080483cb| 5C 94 04 08 |
| 16                 | 080483d0| 58 94 04 08 |
| 18                 | 080483d8| 48 95 04 08 |
| 18                 | 080483dc| 58 94 04 08 |
| 23                 | 080483e7| 48 95 04 08 |  
