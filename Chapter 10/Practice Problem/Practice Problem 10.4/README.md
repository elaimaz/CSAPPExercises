### ***Practice Problem 10.4***:  
How would you use dup2 to redirect standard input to descriptor 5?  

---  

### ***Answear***:  
```C
dup2(5, STDIN_FILENO);
```  