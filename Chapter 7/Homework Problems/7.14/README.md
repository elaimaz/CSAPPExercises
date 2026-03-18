Exercise 7.13
==============

### ***Dificulty***: :star: :star: :star:  

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:

Consider the C code and corresponding relocatable object module in Figure 7.21.  

1. Determine which instructions in .text will need to be modiﬁed by the linker when the module is relocated. For each such instruction, list the information in its relocation entry: section offset, relocation type, and symbol name.  

---  

### ***Answear***:  

section offset: 0x4
relocation type: R_386_PC32
symbol name: __x86.get_pc_thunk.ax

section offset: 0x9
relocation type: R_386_GOTPC
symbol name: _GLOBAL_OFFSET_TABLE_