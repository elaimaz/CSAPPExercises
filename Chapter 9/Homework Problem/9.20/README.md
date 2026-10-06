Exercise 9.20
==============

### ***Dificulty***: :star: :star: :star: :star:  

---

### ***Expected time***: ***10h*** :hourglass_flowing_sand:  

---

### ***Question***:
Write your own version of malloc and free, and compare its running time and space utilization to the version of malloc provided in the standard C library.  

---  

### ***Answear***:  
[My code](./main.c) is a simple version where malloc is O(n) using a simple first fit and free O(1) since we pass the memory location to free. In [this malloc inplementation](https://elixir.bootlin.com/glibc/glibc-2.39/source/malloc/malloc.c#L3845) the time is O(1) in the best situation and O(n) in worst case scenario.
