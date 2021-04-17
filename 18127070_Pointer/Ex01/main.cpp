#include"Ex01.h"

int main()
{
    int *a, n;
    input(a, n);
    print(a, n);
    cout << "\nMin value is: " << findMin(a, n);
    cout << "\nMax modulus is: " << findMaxModulus(a, n);
    cout << "\nCheck ascending order: " << isAscendingOrder(a, n);
    cout << "\nSum of array: " << sumofArray(a, n);
    cout << "\nNumber of prime: " << numberOfPrime(a, n);
    cout << "\nRevert array: ";
    revertArray(a, n);
    print(a, n);
    return 0;
}