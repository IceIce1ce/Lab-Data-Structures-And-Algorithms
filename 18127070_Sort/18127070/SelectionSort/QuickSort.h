#include<iostream>
using namespace std;

int partition(int a[], int left, int right)
{
    int pivot = (left + right) / 2, i = left, j = right;
    while(i < j)
    {
        while(a[i] < a[pivot]) i++;
        while(a[j] > a[pivot]) j--;
        if(i < j) 
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++; j--;
        }
    }
    return pivot;
}

void quickSort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = partition(a, left, right);
        quickSort(a, left, mid);
        quickSort(a, mid + 1, right); 
    }
}