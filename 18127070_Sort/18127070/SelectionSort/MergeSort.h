#include<iostream>
using namespace std;

void merge(int a[], int left, int mid, int right)
{
    int d = left, c1 = left, c2 = mid + 1, tempArray[100000];
    while(c1 <= mid && c2 <= right)
    {
        if(a[c1] < a[c2]) tempArray[d++] = a[c1++]; //a[c1] <= a[c2]
        else tempArray[d++] = a[c2++];
    }
    for(; c1 <= mid; c1++) tempArray[d++] = a[c1];
    for(; c2 <= right; c2++) tempArray[d++] = a[c2];
    for(int s = left; s <= right; s++) a[s] = tempArray[s];
}

void mergeSort(int a[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}