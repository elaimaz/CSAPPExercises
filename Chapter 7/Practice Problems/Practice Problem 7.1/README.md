### ***Practice Problem 7.1***:  
This problem concerns the swap.o module from Figure 7.1(b). For each symbol that is deﬁned or referenced in swap.o, indicate whether or not it will have a symbol table entry in the .symtab section in module swap.o. If so, indicate the module that deﬁnes the symbol (swap.o or main.o), the symbol type (local, global, or extern), and the section (.text, .data, or .bss) it occupies in that module.  

| Symbol | swap.o .symtab entry? | Symbol type | Module where defined | Section |
|--------|-----------------------|-------------|----------------------|---------|
| buf    |                       |             |                      |         |
| bufp0  |                       |             |                      |         |
| bufp1  |                       |             |                      |         |
| swap   |                       |             |                      |         |
| temp   |                       |             |                      |         |

---  

### ***Answear***:  

| Symbol | swap.o .symtab entry? | Symbol type | Module where defined | Section |
|--------|-----------------------|-------------|----------------------|---------|
| buf    |         YES           |   EXTERN    |     main.o           | .data   |
| bufp0  |         YES           |   GLOBAL    |     swap.o           | .data   |
| bufp1  |         YES           |   GLOBAL    |     swap.o           | .bss    |
| swap   |         YES           |   GLOBAL    |     swap.o           | .text   |
| temp   |         NO            |     —       |        —             |   —      |
