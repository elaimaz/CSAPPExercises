Exercise 10.9
==============

### ***Dificulty***: :star: :star:  

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following invocation of the fstatcheck program from Problem 10.8:  
```cmd
unix> fstatcheck 3 < foo.txt
```  

You might expect that this invocation of fstatcheck would fetch and display metadata for ﬁle foo.txt. However, when we run it on our system, it fails with a “bad ﬁle descriptor.” Given this behavior, ﬁll in the pseudo-code that the shell must be executing between the fork and execve calls:  
```C
1   int main (int argc, char **argv, char **envp)       
2   {
3       if (Fork() == 0) { /* Child */
4           /* What code is the shell executing right here? */
5           Execve("fstatcheck", argv, envp);
6       }
7   }
```  

---  

### ***Answear***:    
[code](./main.c).  
