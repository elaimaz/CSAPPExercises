Exercise 6.47
==============

### ***Dificulty***: :star: :star: :star: :star:    

---

### ***Expected time***: ***10h*** :hourglass_flowing_sand:

---

### ***Question***:
This assignment is an intriguing variation of Problem [6.46](../6.46/README.md). Consider the problem of converting a directed graph g into its undirected counterpart g'. The graph g' has an edge from vertex u to vertex v if and only if there is an edge from u to v or from v to u in the original graph g. The graph g is represented by its adjacency matrix G as follows. If N is the number of vertices in g, then G is an N × N matrix and its entries are all either 0 or 1. Suppose the vertices of g are named v<sub>0</sub>, v<sub>1</sub>, v<sub>2</sub>, . . . , v<sub>N−1</sub>. Then G[i][j] is 1 if there is an edge from v<sub>i</sub> to v<sub>j</sub> and is 0 otherwise. Observe that the elements on the diagonal of an adjacency matrix are always 1 and that the adjacency matrix of an undirected graph is symmetric. This code can be written with a simple loop:  

```C
1   void col_convert(int *G, int dim) {
2       int i, j;
3       
4       for (i = 0; i < dim; i++)
5           for (j = 0; j < dim; j++)
6               G[j*dim + i] = G[j*dim + i] || G[i*dim + j];
7   }
```

---  

### ***Answear***:  
[main.c](./main.c)

obs: to simplify, to a matrix be symetric we need that G[i][j] == G[j][i].
