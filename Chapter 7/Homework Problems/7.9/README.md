Exercise 7.9
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
Consider the following program, which consists of two object modules:  

<table>
  <tr>
    <td valign="top">

```c
1 /* foo6.c */
2 void p2(void);
3
4 int main()
5 {
6   p2();
7   return 0;
8 }
```

  </td>
    <td valign="top">

```c
1 /* bar6.c */
2 #include <stdio.h>
3
4 char main;
5
6 void p2()
7 {
8   printf("0x%x\n", main);
9 }
```

  </td>
  </tr>
</table>  

---  

### ***Answear***:  
Because main in foo6.c is initialize because it's a function and strong symbol so it will heald an address.
