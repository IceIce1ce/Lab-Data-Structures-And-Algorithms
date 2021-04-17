#include<iostream>
using namespace std;

int BinarySearch(int a[], int left, int right, int key)
{
    if (right <= left)
    {
        if(key > a[left]) return left + 1;
        else return left;
    } 
    int mid = (left + right - 1) / 2;
    if(key == a[mid]) return mid;
    else if(key < a[mid]) return BinarySearch(a, left, mid - 1, key);
    return BinarySearch(a, mid + 1, right, key);
}

void BinaryInsertionSort(int a[], int n)
{
    int key, location, j;
    for(int i = 1; i < n; i++)
    {
        j = i - 1;
        key = a[i];
        location = BinarySearch(a, 0, j, key);
        while(j >= location)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}