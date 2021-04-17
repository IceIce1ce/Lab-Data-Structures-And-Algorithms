#include<iostream>
using namespace std;

void input(int *&a, int &n);
void deallocateArray(int* &a);
void print(int *a, int &n);
int BinarySearch(int *a, int n, int x);
int RecursiveBinarySearch(int *a, int left, int right, int x);