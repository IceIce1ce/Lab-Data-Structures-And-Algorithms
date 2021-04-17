#include<iostream>
using namespace  std;

void insertionSort(int a[], int n)
{
    int key;
    for(int i = 1; i < n; i++)
    {
        key = a[i];
        int j;
        for(j = i - 1; j >= 0 && a[j] > key; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}