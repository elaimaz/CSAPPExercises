Exercise 8.20
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Use execve to write a program called myls whose behavior is identical to the /bin/ls program. Your program should accept the same command line arguments, interpret the identical environment variables, and produce the identical output.  
&emsp;The ls program gets the width of the screen from the COLUMNS environment variable. If COLUMNS is unset, then ls assumes that the screen is 80 columns wide. Thus, you can check your handling of the environment variables by setting the COLUMNS environment to something smaller than 80:  

```bash
unix> setenv COLUMNS 40
unix> ./myls
...output is 40 columns wide
unix> unsetenv COLUMNS
unix> ./myls
...output is now 80 columns wide
```  

---  

### ***Answear***:  
[myls](./myls.c)