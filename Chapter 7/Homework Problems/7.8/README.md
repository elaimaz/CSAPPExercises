Exercise 7.8
==============

### ***Dificulty***: :star:  

---

### ***Expected time***: ***10min*** :hourglass_flowing_sand:

---

### ***Question***:
In this problem, let REF(x.i) --> DEF(x.k) denote that the linker will associate an arbitrary reference to symbol x in module i to the deﬁnition of x in module k. For each example below, use this notation to indicate how the linker would resolve references to the multiply deﬁned symbol in each module. If there is a link-time error (rule 1), write “ERROR.” If the linker arbitrarily chooses one of the deﬁnitions (rule 3), write “UNKNOWN.”  

**1.**  
<table>
  <tr>
    <td valign="top">

```c
/* Module 1 */
int main()
{
}
```

  </td>
    <td valign="top">

```c
/* Module 2 */
static int main=1;
int p2()
{
}
```

  </td>
  </tr>
</table>  

1. REF(main.1) --> DEF(______.\_\_\_)
2. REF(main.2) --> DEF(______.\_\_\_)  

---  

**2.**  
<table>
  <tr>
    <td valign="top">

```c
/* Module 1 */
int x;
void main()
{
}
```

  </td>
    <td valign="top">

```c
/* Module 2 */
double x;
int p2()
{
}
```

  </td>
  </tr>
</table>  

1. REF(x.1) --> DEF(______.\_\_\_)
2. REF(x.2) --> DEF(______.\_\_\_)  

---  

**3.**  
<table>
  <tr>
    <td valign="top">

```c
/* Module 1 */
int x=1;
void main()
{
}
```

  </td>
    <td valign="top">

```c
/* Module 2 */
double x=1.0;
int p2()
{
}
```

  </td>
  </tr>
</table>  

1. REF(x.1) --> DEF(______.\_\_\_)
2. REF(x.2) --> DEF(______.\_\_\_)  

---  

### ***Answear***:  

**1.**  
<table>
  <tr>
    <td valign="top">

```c
/* Module 1 */
int main()
{
}
```

  </td>
    <td valign="top">

```c
/* Module 2 */
static int main=1;
int p2()
{
}
```

  </td>
  </tr>
</table>  

1. REF(main.1) --> DEF(main.1)
2. REF(main.2) --> DEF(main.2)  

---  

**2.**  
<table>
  <tr>
    <td valign="top">

```c
/* Module 1 */
int x;
void main()
{
}
```

  </td>
    <td valign="top">

```c
/* Module 2 */
double x;
int p2()
{
}
```

  </td>
  </tr>
</table>  

1. REF(x.1) --> DEF(UNKNOWN)
2. REF(x.2) --> DEF(UNKNOWN)  

---  

**3.**  
<table>
  <tr>
    <td valign="top">

```c
/* Module 1 */
int x=1;
void main()
{
}
```

  </td>
    <td valign="top">

```c
/* Module 2 */
double x=1.0;
int p2()
{
}
```

  </td>
  </tr>
</table>  

1. REF(x.1) --> DEF(ERROR)
2. REF(x.2) --> DEF(ERROR)  
