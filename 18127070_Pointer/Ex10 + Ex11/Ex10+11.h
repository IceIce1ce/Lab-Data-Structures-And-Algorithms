#include<iostream>
using namespace std;

void input(int *&a, int &n);
void deallocateArray(int* &a);
void output(int *a, int &n);
int LinearSearch(int *a, int n, int key);
int SentinelLinearSearch(int *a, int n, int key);