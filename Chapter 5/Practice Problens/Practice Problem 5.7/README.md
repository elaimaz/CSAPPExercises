### ***Practice Problem 5.7***:
Modify the code for combine5 to unroll the loop by a factor k = 5.

---  

### ***Answear***:  

```C
1   /* Unroll loop by 5 */
2   void combine5(vec_ptr v, data_t *dest)
3   {
4       long int i;
5       long int length = vec_length(v);
6       long int limit = length-1;
7       data_t *data = get_vec_start(v);
8       data_t acc = IDENT;
9
10      /* Combine 5 elements at a time */
11      for (i = 0; i < limit; i+=5) {
12          acc = acc OP data[i] OP data[i+1];
13          acc = acc OP data[i+2] OP data[i+3];
14          acc = acc OP data[i+4];
15      }
16
17      /* Finish any remaining elements */
18      for (; i < length; i++) {
19          acc = acc OP data[i];
20      }
21      *dest = acc;
22  }
```

