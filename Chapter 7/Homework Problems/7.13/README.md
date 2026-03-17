Exercise 7.13
==============

### ***Dificulty***: :star: :star: :star:  

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:

Consider the C code and corresponding relocatable object module in Figure 7.20.  

1. Determine which instructions in .text will need to be modiﬁed by the linker when the module is relocated. For each such instruction, list the information in its relocation entry: section offset, relocation type, and symbol name.  

2. Determine which data objects in .data will need to be modiﬁed by the linker when the module is relocated. For each such instruction, list the information in its relocation entry: section offset, relocation type, and symbol name.  

Feel free to use tools such as objdump to help you solve this problem.

---  

### ***Answear***:  

1. 
1b:   48 8b 05 00 00 00 00    mov    rax,QWORD PTR [rip+0x0]        # 22 <p1+0x14>  
relocation entry: 1e: R_X86_64_PC32       xp-0x4
section offset: 1e
relocation type: R_X86_64_PC32
symbol name: xp  

24:   e8 00 00 00 00          call   29 <p1+0x1b>
relocation entry: 25: R_X86_64_PLT32      p3-0x4
section offset: 25
relocation type: R_X86_64_PLT32
symbol name: p3

2d:   e8 00 00 00 00          call   32 <p1+0x24>
relocation entry: 2e: R_X86_64_PLT32      p2-0x4
section offset: 2e
relocation type: R_X86_64_PLT32
symbol name: p2  

2. 
section offset: 00
relocation type: R_X86_64_64
symbol: x


obs: you can ge the information by runing: 
```bash
readelf -r p1.o
```