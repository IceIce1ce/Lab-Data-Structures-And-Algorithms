#include<iostream>
using namespace std;

void insertionSort1(int a[], int n)
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

void flashSort(int a[], int n)
{
    if(n == 0) return;
    int m = (int)(0.45 * n); //0.45n is better optimal 
    //int m = (int)((0.2 * n) + 2);
    int maxIndex = 0;
    int max, min; 
    min = max = a[0];
	for(int i = 1; i < n - 1; i += 2)
	{
		int small, large, largestIndex;
		if(a[i] < a[i + 1])
		{
			small = a[i];
			large = a[i + 1];
			largestIndex = i + 1;
		}
		else
		{
			large = a[i];
			largestIndex = i;
			small = a[i + 1];
		}

		if(large > max)
		{
			max = large;
			maxIndex = largestIndex;
		}

		if(small < min)
		{
			min = small;
		}
	}
    if(a[n - 1] < min)
	{
		min = a[n - 1];
	}
    else if(a[n - 1] > max)
    { 
        max = a[n - 1];
        maxIndex = n - 1;
    }
    if(max == min) return;
    int* L = new int[m + 1];
    for(int t = 1; t <= m; t++) 
	{
    	L[t] = 0;
	}
    double c = (m - 1.0) / (max - min);
    int k;
    for(int h = 0; h < n; h++)
    {
        k = ((int)((a[h] - min) * c)) + 1;
        L[k]++;
    }
    for(k = 2; k <= m; k++)
    {
        L[k] += L[k - 1];
    }
    int temp = a[maxIndex];
    a[maxIndex] = a[0];
    a[0] = temp;
    int j = 0, move = 0; 
    k = m; 
    while(move < n)
    {
        while(j >= L[k])
        {
            j++;
            k = ((int)((a[j] - min) * c)) + 1;
        }
        int flash = a[j];
        while(j < L[k])
        {
            k = ((int)((flash - min) * c)) + 1;
            int location = L[k] - 1;
            int temp = a[location];
            a[location] = flash;
            flash = temp;
            L[k]--;
            move++;
        }
    }
	int hold = (int)(1.25 * ((n / m) + 1));
    const int minElement = 30;
    for(k = m - 1; k >= 1; k--)
    {
        int num_of_element_in_Kth = L[k + 1] - L[k];
        if(num_of_element_in_Kth > hold && num_of_element_in_Kth > minElement) flashSort(&a[L[k]], num_of_element_in_Kth);
        else
        {
            if(num_of_element_in_Kth > 1) insertionSort(&a[L[k]], num_of_element_in_Kth);
        }
    }
    delete[] L;
}