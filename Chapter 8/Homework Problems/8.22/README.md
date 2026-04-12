Exercise 8.22
==============

### ***Dificulty***: :star: :star: :star:  

---

### ***Expected time***: ***2h*** :hourglass_flowing_sand:

---

### ***Question***:
Write your own version of the Unix system function  

```C
int mysystem(char *command);
```  

The mysystem function executes command by calling “/bin/sh -c command”, and then returns after command has completed. If command exits normally (by calling the exit function or executing a return statement), then mysystem returns the command exit status. For example, if command terminates by calling exit(8), then system returns the value 8. Otherwise, if command terminates abnormally, then mysystem returns the status returned by the shell.  

---  

### ***Answear***:  
[mysystem](./mysystem.c)