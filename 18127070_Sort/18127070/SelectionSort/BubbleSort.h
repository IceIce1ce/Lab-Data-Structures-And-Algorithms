#include<iostream>
using namespace std;

void bubleSort(int a[], int n) // optimized time for sorted array
{
    for(int i = 0; i < n - 1; i++)
    {
    	bool flag = false;
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
            	flag = true;
            	int temp = a[j];
            	a[j] = a[j + 1];
            	a[j + 1] = temp;
            }
        }
    	if(!flag) return;
    }
}