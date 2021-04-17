#include"Ex01.h"

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

int findMin(int *a, int n)
{
    int min = a[0];
    for(int i = 0; i < n; i++)
    {
        if(a[i] < min)
        {
            min = a[i];
        }
    }
    return min;
}

int findMaxModulus(int* a, int n)
{
    int max = abs(a[0]);
    for(int i = 0; i < n; i++)
    {
        if(abs(a[i]) > max)
        {
            max = abs(a[i]);
        }
    }
    return max;
}

bool isAscendingOrder(int* a, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] < a[i + 1]) return true;
        else return false;
    }
}

int sumofArray(int* a, int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

bool isPrime(int num)
{
    if(num < 3) return num == 2;
    for(int i = 2; i < num; i++)
    {
        if(num % i == 0) return false;
        return true;
    }
}

int numberOfPrime(int* a, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(isPrime(a[i]) == true)
        {
            count++;
        }
    }
    return count;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void revertArray(int* a, int n)
{
    for(int i = 0; i < n/2; i++)
    {
        swap(a[i], a[n - 1 - i]);
    }
}