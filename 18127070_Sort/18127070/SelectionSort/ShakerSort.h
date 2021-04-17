#include<iostream>
using namespace std;

void swapShaker(int *a, int *b)
{
    int temp = *a; 
    *a = *b;
    *b = temp;
}

void shakerSort(int a[], int n)
{
    int left = 0, right = n - 1, k = 0, i;
    while(left < right)
    {
        for(i = left; i < right; i++)
        {
            if(a[i] > a[i + 1])
            {
                swapShaker(&a[i], &a[i + 1]);
                k = i;
            }
        }
        right = k;
        for(i = right; i > left; i--)
        {
            if(a[i] < a[i - 1])
            {
                swapShaker(&a[i], &a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}