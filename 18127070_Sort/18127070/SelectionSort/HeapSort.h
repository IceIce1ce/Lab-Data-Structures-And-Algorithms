#include<iostream>
using namespace  std;

void max_heapify(int a[], int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;
    if(largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, n, largest);
    }
}

void build_max_heap(int a[], int n)
{
	for(int i = (n + 1) / 2; i >= 0; i--)
    max_heapify(a, n - 1, i);
    for(int i = n - 1; i >= 0; i--)
    {
        int tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
    	max_heapify(a, i, 0);
    }
}