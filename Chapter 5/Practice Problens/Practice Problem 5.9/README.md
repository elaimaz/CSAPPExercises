### ***Practice Problem 5.9***:
The traditional implementation of the merge step of mergesort requires three loops: 

```C
1   void merge(int src1[], int src2[], int dest[], int n) {
2       int i1 = 0;
3       int i2 = 0;
4       int id = 0;
5       while (i1 < n && i2 < n) {
6           if (src1[i1] < src2[i2])
7               dest[id++] = src1[i1++];
8           else
9               dest[id++] = src2[i2++];
10          }
11      while (i1 < n)
12          dest[id++] = src1[i1++];
13      while (i2 < n)
14          dest[id++] = src2[i2++];
15  }
```  

&emsp;The branches caused by comparing variables i1 and i2 to n have good prediction performance—the only mispredictions occur when they ﬁrst become false. The comparison between values src1[i1] and src2[i2] (line 6), on the other hand, is highly unpredictable for typical data. This comparison controls a conditional branch, yielding a CPE (where the number of elements is 2n) of around 17.50.  
&emsp;Rewrite the code so that the effect of the conditional statement in the ﬁrst loop (lines 6–9) can be implemented with a conditional move. 

---  

### ***Answear***:  

```C
1   void merge(int src1[], int src2[], int dest[], int n) {
2       int take = 0;
3       while (i1 < n && i2 < n) {
4           take = src[i1] < src[i2];
5           dest[id++] = take ? src1[i1] : src2[i2];
6           i1 = take;
7           i2 = (1 - take);
8       }              
9   }      
``` 
