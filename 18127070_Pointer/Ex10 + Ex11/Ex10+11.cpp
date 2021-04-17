#include"Ex10+11.h"

void input(int *&a, int &n)
{
    cout << "Size of array: ";
    cin >> n;
    a = new int[n];
    for(int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void deallocateArray(int* &a)
{
    delete[] a;
}

void output(int *a, int &n)
{
    for(int i  = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int LinearSearch(int *a, int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(key == a[i]) return i;
    }
    return -1;
}

 int SentinelLinearSearch(int *a, int n, int key)
 {
     int flag = a[n - 1], i = 0;
     a[n - 1] = key;
     while(a[i] != key) i++;
     a[n - 1] = flag;
     if((i < n - 1)|| (key == a[n - 1])) return i;
     return -1;
 }