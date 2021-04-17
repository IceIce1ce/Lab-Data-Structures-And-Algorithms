#include"Ex12+13.h"

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

void print(int *a, int &n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int BinarySearch(int *a, int n, int x)
{
    int left = 0, right = n - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(x == a[mid]) return mid;
        else if(x < a[mid]) right = mid - 1;
        else if(x > a[mid]) left = mid + 1; 
    }
    return -1;
}

int RecursiveBinarySearch(int *a, int left, int right, int x)
{
    if(left <= right)
    {
        int mid = left + (right - 1) / 2;
        if(a[mid] == x) return mid;
        if(a[mid] > x) return RecursiveBinarySearch(a, left, mid - 1, x);
		return RecursiveBinarySearch(a, mid + 1, right, x);
    }
    return -1;
}