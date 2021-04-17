#include"Ex10+11.h"

int main()
{
    int *a, n, x;
    input(a, n);
    output(a, n);
    cout << "\n" << "Value x: ";
    cin >> x;
    if(LinearSearch(a, n, x) >= 0) cout << "Found x";
    else cout << "Not found x";
    cout << endl;
    if(SentinelLinearSearch(a, n, x) >= 0) cout << "Found x";
    else cout << "Not found x";
    return 0;
}