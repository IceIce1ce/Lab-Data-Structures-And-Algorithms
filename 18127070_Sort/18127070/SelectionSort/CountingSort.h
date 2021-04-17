#include<iostream>
using namespace std;

void countingSort(int a[], int n) //use static to avoid stack overflow
{
    static int output_array[100000], max = a[0];
    for(int i = 1; i < n; i++)
    {
        if(a[i] > max) max = a[i]; 
    }
    static int count_array[100000];
    for(int i = 0; i <= max; i++) count_array[i] = 0;
	for(int j = 0; j < n; j++) count_array[a[j]]++;
    for(int i = 1; i <= max; i++) count_array[i] += count_array[i - 1];
    for(int j = n - 1; j >= 0; j--)
    {
		output_array[count_array[a[j]] - 1] = a[j];
        count_array[a[j]]--;
    }
    for(int i = n - 1; i >= 0; i--) a[i] = output_array[i];
}