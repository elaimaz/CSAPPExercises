### ***Practice Problem 8.6***:  
Write a program called myecho that prints its command line arguments and environment variables. For example:  

```bash
./myecho arg1 arg2 
```  
Command line arguments:  
&emsp;&emsp;argv[ 0]: myecho  
&emsp;&emsp;argv[ 1]: arg1  
&emsp;&emsp;argv[ 2]: arg2  


Environment variables:  
&emsp;&emsp;envp[ 0]: PWD=/usr0/droh/ics/code/ecf  
&emsp;&emsp;envp[ 1]: TERM=emacs  
&emsp;&emsp;...  
&emsp;&emsp;envp[25]: USER=droh  
&emsp;&emsp;envp[26]: SHELL=/usr/local/bin/tcsh  
&emsp;&emsp;envp[27]: HOME=/usr0/droh  

---  

### ***Answear***:    
[main.c](./main.c)