### ***Practice Problem 8.7***:  
What is the output of the following program?  

```C
1   pid_t pid;
2   int counter = 2;
3
4   void handler1(int sig) {
5       counter = counter - 1;
6       printf("%d", counter);
7       fflush(stdout);
8       exit(0);
9   }
10
11  int main() {
12      signal(SIGUSR1, handler1);
13
14      printf("%d", counter);
15      fflush(stdout);
16
17      if ((pid = fork()) == 0) {
18          while(1) {};
19      }
20      kill(pid, SIGUSR1);
21      waitpid(-1, NULL, 0);
22      counter = counter + 1;
23      printf("%d", counter);
24      exit(0);
25  }
```  


---  

### ***Answear***:    
2;1;3  
