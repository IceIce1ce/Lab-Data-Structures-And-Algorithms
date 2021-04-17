#include"Ex02.h"

int sumOfSquares(int n)
{
    if(n == 1) return 1;
    return sumOfSquares(n - 1) + n * n;
}

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int fib(int n)
{
    if(n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}