### ***Practice Problem 5.3***:
Consider the following functions:  

```
int min(int x, int y) { return x < y ? x : y; }
int max(int x, int y) { return x < y ? y : x; }
void incr(int *xp, int v) { *xp += v; }
int square(int x) { return x*x; }
```  
The following three code fragments call these functions:  

1. ````c
    for (i = min(x, y); i < max(x, y); incr(&i, 1))
        t += square(i);

2. ````c
    for (i = max(x, y) - 1; i >= min(x, y); incr(&i, -1))
        t += square(i);

2. ````c
    int low = min(x, y);
    int high = max(x, y);

    for (i = low; i < high; incr(&i, 1))
        t += square(i);

Assume x equals 10 and y equals 100. Fill in the following table indicating the number of times each of the four functions is called in code fragments A–C:

---  

### ***Answear***: 

| Code | min | max | incr | square |
|------|-----|-----|------|--------|
| A    | 1   |  91 |  90  |   90   |
| B    | 91  |  1  |  90  |   90   |
| C    |  1  |  1  |  90  |   90   |