#include"Ex02.h"

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    cout << "Sum: " << sumOfSquares(n);
    int a = 10, b = 20;
    cout << "\n" << gcd(a, b);
    cout << "\n" << fib(9);
    return 0;
}