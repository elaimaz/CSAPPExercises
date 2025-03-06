### ***Practice Problem 5.6***:
Let us continue exploring ways to evaluate polynomials, as described in Problem 5.5. We can reduce the number of multiplications in evaluating a polynomial by applying Horner’s method, named after British mathematician William G. Horner (1786–1837). The idea is to repeatedly factor out the powers of x to get the following evaluation:  

a₀ + x(a₁ + x(a₂ + ... + x(aₙ₋₁ + x aₙ)...))  

Using Horner’s method, we can implement polynomial evaluation using the following code:  

```C
1   /* Apply Horner’s method */
2   double polyh(double a[], double x, int degree)
3   {
4       long int i;
5       double result = a[degree];
6       for (i = degree-1; i >= 0; i--)
7           result = a[i] + x*result;
8       return result;
9   } 
```  

1. For degree n, how many additions and how many multiplications does this code perform?
2. On our reference machine, with the arithmetic operations having the latencies shown in Figure 5.12, we measure the CPE for this function to be 8.00. Explain how this CPE arises based on the data dependencies formed between iterations due to the operations implementing line 7 of the function.
3. Explain how the function shown in Problem 5.5 can run faster, even though it requires more operations.

---  

### ***Answear***: 
1. n - 1 additions and n - 1 multiplications.
2. The CPE occur because of the multiplications between doubles (latency 5) x and result, after that we have a double sum (latency 3) between a[i] and x*result.
3. It can run faster with large arrays because of the latency. The variable result is used twice (multiply and then sum), but when we will sum we need to wait the multiplication finish. In 5.5 we do not have this problem. 
