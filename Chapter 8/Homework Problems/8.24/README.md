Exercise 8.24
==============

### ***Dificulty***: :star: :star: :star:  

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
Modify the program in Figure 8.17 so that the following two conditions are met:  

1. Each child terminates abnormally after attempting to write to a location in the read-only text segment.  

2. The parent prints output that is identical (except for the PIDs) to the following:  

child 12255 terminated by signal 11: Segmentation fault  
child 12254 terminated by signal 11: Segmentation fault  

Hint: Read the man page for psignal(3).

---  

### ***Answear***:  
[main.c](./main.c)  
