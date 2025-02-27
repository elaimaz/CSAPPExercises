### ***Practice Problem 5.5***:
Suppose we wish to write a function to evaluate a polynomial, where a polynomial of degree n is deﬁned to have a set of coefﬁcients a0, a1, a2 , . . . , an. For a value x, we evaluate the polynomial by computing  

a₀ + a₁x + a₂x² + ... + aₙxⁿ  

This evaluation can be implemented by the following function, having as arguments an array of coefﬁcients a, a value x, and the polynomial degree, degree (the value n in Equation 5.2). In this function, we compute both the successive terms of the equation and the successive powers of x within a single loop:  

```C
1   double poly(double a[], double x, int degree)
2   {
3       long int i;
4       double result = a[0];
5       double xpwr = x; /* Equals x^i at start of loop */
6       for (i = 1; i <= degree; i++) {
7           result += a[i] * xpwr;
8           xpwr = x * xpwr;
9       }
10      return result;
11
12  }  
```  

1. For degree n, how many additions and how many multiplications does this code perform?
2. On our reference machine, with arithmetic operations having the latencies shown in Figure 5.12, we measure the CPE for this function to be 5.00. Explain how this CPE arises based on the data dependencies formed between iterations due to the operations implementing lines 7–8 of the function.

---  

### ***Answear***: 

1. It applies 2n additions, incrementing i and for result. 2n multiplications, a[i] * xpwr and  x * xpwr.
2. It rises because array a, x and xpwr are of type double and all of then are been used to multiply on lines 7 and 8. Multiplication and type double have high latency compared to addition.

