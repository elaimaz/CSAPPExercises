### ***Practice Problem 7.4***:  
This problem concerns the relocated program in Figure 7.10.   

1. What is the hex address of the relocated reference to swap in line 5?  
2. What is the hex value of the relocated reference to swap in line 5?  
3. Suppose the linker had decided for some reason to locate the .text section at 0x80483b8 instead of 0x80483b4. What would the hex value of the relocated reference in line 5 be in this case?  

---  

### ***Answear***:  

1.  0x80483bb  

2. 9  

3. The dstance between the reference and the swap function is always the same. Thus, because the reference is a PC-relative address, its value will be 0x9, regardless of where the linker locates the .text section.  
