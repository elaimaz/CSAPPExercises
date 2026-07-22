### ***Practice Problem 9.8***:  
Implement a place function for the example allocator.  

```C
static void place(void *bp, size_t asize)
```  

Your solution should place the requested block at the beginning of the free block, splitting only if the size of the remainder would equal or exceed the minimum block size.  

---  

### ***Answear***:  
[code](../../utils/mm.c)  
