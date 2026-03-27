### ***Practice Problem 8.3***:  
List all of the possible output sequences for the following program:  

```c
1   int main()
2   {
3       if (Fork() == 0) {
4           printf("a");
5       }
6       else {
7           printf("b");
8           waitpid(-1, NULL, 0);
9       }
10      printf("c");
11      exit(0);
12  }
```  

---  

### ***Answear***:  
1. acbc
2. bacc
3. bcac
4. abcc  

obs: i admit that i had to quest the AI how is bcac is possible. Well apparently we do not consider that in waitpid will print first than father.  