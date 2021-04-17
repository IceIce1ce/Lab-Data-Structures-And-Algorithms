#include<iostream>
using namespace std;

int findMax(int a[], int n)
{
    int max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max) max = a[i];
    }
    return max;
}

void countingSort(int a[], int n, int digit_number)
{
    static int output_array[100000], count[100000];
    for(int i = 0; i < 100000; i++) count[i] = 0;
    for(int j = 0; j < n; j++) count[(a[j] / digit_number) % 10]++;
    for(int i = 1; i < 100000; i++) count[i] += count[i - 1];
    for(int j = n - 1; j >= 0; j--)
    {
        output_array[count[(a[j] / digit_number) % 10] - 1] = a[j]; 
        count[(a[j] / digit_number) % 10]--; 
    }
    for(int i = n - 1; i >= 0; i--) a[i] = output_array[i];
}

void radixSort(int a[], int n)
{
    int max = findMax(a, n);
    for(int digit_number = 1; (max / digit_number) > 0; digit_number *= 10) countingSort(a, n, digit_number);
}