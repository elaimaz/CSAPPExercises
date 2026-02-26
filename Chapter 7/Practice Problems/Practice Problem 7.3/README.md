### ***Practice Problem 7.3***:  
Let a and b denote object modules or static libraries in the current directory, and let a→b denote that a depends on b, in the sense that b deﬁnes a symbol that is referenced by a. For each of the following scenarios, show the minimal command line (i.e., one with the least number of object ﬁle and library arguments) that will allow the static linker to resolve all symbol references.  

1. p.o → libx.a.
2. p.o → libx.a → liby.a.
3. p.o → libx.a → liby.a and liby.a → libx.a →p.o.

---  

### ***Answear***:  

1. gcc p.o libx.a  

2. gcc p.o libx.a liby.a  

3. gcc p.o libx.a liby.a libx.a
