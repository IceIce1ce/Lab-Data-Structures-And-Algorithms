#include"Ex12+13.h"

int main()
{
    int *a, n, x;
    input(a, n);
    print(a, n);
    cout << "\n" << "Value x: ";
    cin >> x;
    if(BinarySearch(a, n, x) != -1) cout << "Found x";
    else cout << "Not found x";
    cout << endl;
    if(RecursiveBinarySearch(a, 0, n - 1, x) != -1) cout << "Found x";
    else cout << "Not found x";
    return 0; 
}