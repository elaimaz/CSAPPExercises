Exercise 2.72
==============

### ***Dificulty***: :star: :star:

---

### ***Expected time***: ***20 min*** :hourglass_flowing_sand:

---

### ***Question***:

You are given the task of writting a function that will copy an integer val into a buffer buf, but
it should do so only if enough space is avaliable in the buffer.  
&nbsp;Here is the code you write:

```
/* Copy integer into buffer if space avaliable */
/* WARNING: The following code is buggy */
void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes-sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}
```

This code makes use of the library function memcpy. Although its use is a bit artificial here,
where we simply want to copy an int, it illustrates an approach commonly used to copy larger data
structures.  
&nbsp;You carefully test the code and discover that it _always_ copies the value to the buffer,
even when maxbytes is too small.


1. Explain why the conditional test in the code always succeds. **Hint**: The sizeof operator
returns a value of type size_t.  
&nbsp;**Answer**: Because sizeof(val) will return an unsigned valor, causing the expression to return an unsigned
valor, it always will be 0 or greater.


2. Show how you can rewrite the conditional test to make it work properly.




