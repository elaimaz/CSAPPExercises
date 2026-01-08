Exercise 6.42
==============

### ***Dificulty***: :star: :star:    

---

### ***Expected time***: ***20min*** :hourglass_flowing_sand:

---

### ***Question***:
You are writing a new 3D game that you hope will earn you fame and fortune. You are currently working on a function to blank the screen buffer before drawing the next frame. The screen you are working with is a 640 × 480 array of pixels. The machine you are working on has a 64 KB direct-mapped cache with 4-byte lines. The C structures you are using are as follows:  

```C
1   struct pixel {
2       char r;
3       char g;
4       char b;
5       char a;
6   };
7
8   struct pixel buffer[480][640];
9   int i, j;
10  char *cptr;
11  int *iptr;
```  

Assume the following:  

- sizeof(char) == 1 and sizeof(int) == 4.  
- buffer begins at memory address 0.  
- The cache is initially empty.  
- The only memory accesses are to the entries of the array buffer. Variables i, j, cptr, and iptr are stored in registers.  

What percentage of writes in the following code will miss in the cache?  

```C
1   for (j = 0; j < 640; j++) {
2       for (i = 0; i < 480; i++){
3           buffer[i][j].r = 0;
4           buffer[i][j].g = 0;
5           buffer[i][j].b = 0;
6           buffer[i][j].a = 0;
7       }
8   }
```

---  

### ***Answear***:  
Since the cache has a 4-byte lines size, it fit the entirely pixel struct. The first iteration always will be a miss ```buffer[i][j].r = 0;``` but the other will be a hit. So the miss rate is 1/4, or 25%. [Simulation code](main.c)
