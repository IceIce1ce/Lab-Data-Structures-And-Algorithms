#include<iostream>
#include<time.h>
#include<fstream>
#include"InsertionSort.h"
#include"BinaryInsertionSort.h"
#include"BubbleSort.h"
#include"ShakerSort.h"
#include"ShellSort.h"
#include"HeapSort.h"
#include"MergeSort.h"
#include"QuickSort.h"
#include"CountingSort.h"
#include"RadixSort.h"
#include"FlashSort.h"
using namespace  std;

void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

void swap1(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void GenerateNearlySortedData(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap1(a[r1], a[r2]);
	}
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int a[], int n)
{
    int min;
    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[min]) min = j; 
        }
    	swap(&a[min], &a[i]);
    }
}

int main()
{
	/////////////////////////Selection Sort////////////////////////////
	/*double time_start, time_end;
	int a[1000];
	int n = sizeof(a) / sizeof(a[0]);
	GenerateRandomData(a, n);
	time_start = clock();
	SelectionSort(a, n);
	time_end = clock();
	cout << "Selection sort with 1000 elements random: " << (time_end - time_start) / CLK_TCK << " sec" << "\n";
	ofstream fout;
	fout.open("SelectionSort_Random_1000.txt");
	if(!fout)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n; i++)
	{
		SelectionSort(a, n);
		fout << a[i] << " ";
	}
	fout.close();
	double time_start1, time_end1;
	int b[3000];
	int n1 = sizeof(b) / sizeof(b[0]);
	GenerateRandomData(b, n1);
	time_start1 = clock();
	SelectionSort(b, n1);
	time_end1 = clock();
	cout << "Selection sort with 3000 elements random: " << (time_end1 - time_start1) / CLK_TCK << " sec" << "\n";
	ofstream fout2;
	fout2.open("SelectionSort_Random_3000.txt");
	if(!fout2)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n1; i++)
	{
		SelectionSort(b, n1);
		fout2 << b[i] << " ";
	}
	fout2.close();
	double time_start2, time_end2;
	int c[10000];
	int n2 = sizeof(c) / sizeof(c[0]);
	GenerateRandomData(c, n2);
	time_start2 = clock();
	SelectionSort(c, n2);
	time_end2 = clock();
	cout << "Selection sort with 10000 elements random: " << (time_end2 - time_start2) / CLK_TCK << " sec" << "\n";
	ofstream fout3;
	fout3.open("SelectionSort_Random_10000.txt");
	if(!fout3)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n2; i++)
	{
		SelectionSort(c, n2);
		fout3 << c[i] << " ";
	}
	fout3.close();
	double time_start3, time_end3;
	static int d[30000];
	static int n3 = sizeof(d) / sizeof(d[0]);
	GenerateRandomData(d, n3);
	time_start3 = clock();
	SelectionSort(d, n3);
	time_end3 = clock();
	cout << "Selection sort with 30000 elements random: " << (time_end3 - time_start3) / CLK_TCK << " sec" << "\n";
	ofstream fout4;
	fout4.open("SelectionSort_Random_30000.txt");
	if(!fout4)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n3; i++)
	{
		SelectionSort(d, n3);
		fout4 << d[i] << " ";
	}
	fout4.close();
	double time_start4, time_end4;
	static int e[100000];
	static int n4 = sizeof(e) / sizeof(e[0]);
	GenerateRandomData(e, n4);
	time_start4 = clock();
	SelectionSort(e, n4);
	time_end4 = clock();
	cout << "Selection sort with 100000 elements random: " << (time_end4 - time_start4) / CLK_TCK << " sec" << "\n";
	ofstream fout5;
	fout5.open("SelectionSort_Random_100000.txt");
	if(!fout5)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n4; i++)
	{
		SelectionSort(e, n4);
		fout5 << e[i] << " ";
	}
	fout5.close();*/

	/*double time_start5, time_end5;
	int f[1000];
	int n5 = sizeof(f) / sizeof(f[0]);
	GenerateSortedData(f, n5);
	time_start5 = clock();
	SelectionSort(f, n5);
	time_end5 = clock();
	cout << "Selection sort with 1000 elements sorted: " << (time_end5 - time_start5) / CLK_TCK << " sec" << "\n";
	ofstream fout6;
	fout6.open("SelectionSort_Sorted_1000.txt");
	if(!fout6)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n5; i++)
	{
		SelectionSort(f, n5);
		fout6 << f[i] << " ";
	}
	fout6.close();
	double time_start6, time_end6;
	int g[3000];
	int n6 = sizeof(g) / sizeof(g[0]);
	GenerateSortedData(g, n6);
	time_start6 = clock();
	SelectionSort(g, n6);
	time_end6 = clock();
	cout << "Selection sort with 3000 elements sorted: " << (time_end6 - time_start6) / CLK_TCK << " sec" << "\n";
	ofstream fout7;
	fout7.open("SelectionSort_Sorted_3000.txt");
	if(!fout7)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n6; i++)
	{
		SelectionSort(g, n6);
		fout7 << g[i] << " ";
	}
	fout7.close();
	double time_start7, time_end7;
	int h[10000];
	int n7 = sizeof(h) / sizeof(h[0]);
	GenerateSortedData(h, n7);
	time_start7 = clock();
	SelectionSort(h, n7);
	time_end7 = clock();
	cout << "Selection sort with 10000 elements sorted: " << (time_end7 - time_start7) / CLK_TCK << " sec" << "\n";
	ofstream fout8;
	fout8.open("SelectionSort_Sorted_10000.txt");
	if(!fout8)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n7; i++)
	{
		SelectionSort(h, n7);
		fout8 << h[i] << " ";
	}
	fout8.close();
	double time_start8, time_end8;
	static int j[30000];
	static int n8 = sizeof(j) / sizeof(j[0]);
	GenerateSortedData(j, n8);
	time_start8 = clock();
	SelectionSort(j, n8);
	time_end8 = clock();
	cout << "Selection sort with 30000 elements sorted: " << (time_end8 - time_start8) / CLK_TCK << " sec" << "\n";
	ofstream fout9;
	fout9.open("SelectionSort_Sorted_30000.txt");
	if(!fout9)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n8; i++)
	{
		SelectionSort(j, n8);
		fout9 << j[i] << " ";
	}
	fout9.close();
	double time_start9, time_end9;
	static int k[100000];
	static int n9 = sizeof(k) / sizeof(k[0]);
	GenerateSortedData(k, n9);
	time_start9 = clock();
	SelectionSort(k, n9);
	time_end9 = clock();
	cout << "Selection sort with 100000 elements sorted: " << (time_end9 - time_start9) / CLK_TCK << " sec" << "\n";
	ofstream fout10;
	fout10.open("SelectionSort_Sorted_100000.txt");
	if(!fout10)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n9; i++)
	{
		SelectionSort(k, n9);
		fout10 << k[i] << " ";
	}
	fout10.close();*/

	/*double time_start10, time_end10;
	int l[1000];
	int n10 = sizeof(l) / sizeof(l[0]);
	GenerateReverseData(l, n10);
	time_start10 = clock();
	SelectionSort(l, n10);
	time_end10 = clock();
	cout << "Selection sort with 1000 elements reversed: " << (time_end10 - time_start10) / CLK_TCK << " sec" << "\n";
	ofstream fout11;
	fout11.open("SelectionSort_Reversed_1000.txt");
	if(!fout11)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n10; i++)
	{
		SelectionSort(l, n10);
		fout11 << l[i] << " ";
	}
	fout11.close();
	double time_start11, time_end11;
	int m[3000];
	int n11 = sizeof(m) / sizeof(m[0]);
	GenerateReverseData(m, n11);
	time_start11 = clock();
	SelectionSort(m, n11);
	time_end11 = clock();
	cout << "Selection sort with 3000 elements reversed: " << (time_end11 - time_start11) / CLK_TCK << " sec" << "\n";
	ofstream fout12;
	fout12.open("SelectionSort_Reversed_3000.txt");
	if(!fout12)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n11; i++)
	{
		SelectionSort(m, n11);
		fout12 << m[i] << " ";
	}
	fout12.close();
	double time_start12, time_end12;
	int o[10000];
	int n12 = sizeof(o) / sizeof(o[0]);
	GenerateReverseData(o, n12);
	time_start12 = clock();
	SelectionSort(o, n12);
	time_end12 = clock();
	cout << "Selection sort with 10000 elements reversed: " << (time_end12 - time_start12) / CLK_TCK << " sec" << "\n";
	ofstream fout13;
	fout13.open("SelectionSort_Reversed_10000.txt");
	if(!fout13)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n12; i++)
	{
		SelectionSort(o, n12);
		fout13 << o[i] << " ";
	}
	fout13.close();
	double time_start13, time_end13;
	static int p[30000];
	static int n13 = sizeof(p) / sizeof(p[0]);
	GenerateReverseData(p, n13);
	time_start13 = clock();
	SelectionSort(p, n13);
	time_end13 = clock();
	cout << "Selection sort with 30000 elements reversed: " << (time_end13 - time_start13) / CLK_TCK << " sec" << "\n";
	ofstream fout14;
	fout14.open("SelectionSort_Reversed_30000.txt");
	if(!fout14)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n13; i++)
	{
		SelectionSort(p, n13);
		fout14 << p[i] << " ";
	}
	fout14.close();
	double time_start14, time_end14;
	static int q[100000];
	static int n14 = sizeof(q) / sizeof(q[0]);
	GenerateReverseData(q, n14);
	time_start14 = clock();
	SelectionSort(q, n14);
	time_end14 = clock();
	cout << "Selection sort with 100000 elements reversed: " << (time_end14 - time_start14) / CLK_TCK << " sec" << "\n";
	ofstream fout15;
	fout15.open("SelectionSort_Reversed_100000.txt");
	if(!fout15)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n14; i++)
	{
		SelectionSort(q, n14);
		fout15 << q[i] << " ";
	}
	fout15.close();*/

	/*double time_start15, time_end15;
	int r[1000];
	int n15 = sizeof(r) / sizeof(r[0]);
	GenerateNearlySortedData(r, n15);
	time_start15 = clock();
	SelectionSort(r, n15);
	time_end15 = clock();
	cout << "Selection sort with 1000 elements nearly sorted: " << (time_end15 - time_start15) / CLK_TCK << " sec" << "\n";
	ofstream fout16;
	fout16.open("SelectionSort_NearlySorted_1000.txt");
	if(!fout16)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n15; i++)
	{
		SelectionSort(r, n15);
		fout16 << r[i] << " ";
	}
	fout16.close();
	double time_start16, time_end16;
	int s[3000];
	int n16 = sizeof(s) / sizeof(s[0]);
	GenerateNearlySortedData(s, n16);
	time_start16 = clock();
	SelectionSort(s, n16);
	time_end16 = clock();
	cout << "Selection sort with 3000 elements nearly sorted: " << (time_end16 - time_start16) / CLK_TCK << " sec" << "\n";
	ofstream fout17;
	fout17.open("SelectionSort_NearlySorted_3000.txt");
	if(!fout17)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n16; i++)
	{
		SelectionSort(s, n16);
		fout17 << s[i] << " ";
	}
	fout17.close();
	double time_start17, time_end17;
	int t[10000];
	int n17 = sizeof(t) / sizeof(t[0]);
	GenerateNearlySortedData(t, n17);
	time_start17 = clock();
	SelectionSort(t, n17);
	time_end17 = clock();
	cout << "Selection sort with 10000 elements nearly sorted: " << (time_end17 - time_start17) / CLK_TCK << " sec" << "\n";
	ofstream fout18;
	fout18.open("SelectionSort_NearlySorted_10000.txt");
	if(!fout18)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n17; i++)
	{
		SelectionSort(t, n17);
		fout18 << t[i] << " ";
	}
	fout18.close();
	double time_start18, time_end18;
	static int u[30000];
	static int n18 = sizeof(u) / sizeof(u[0]);
	GenerateNearlySortedData(u, n18);
	time_start18 = clock();
	SelectionSort(u, n18);
	time_end18 = clock();
	cout << "Selection sort with 30000 elements nearly sorted: " << (time_end18 - time_start18) / CLK_TCK << " sec" << "\n";
	ofstream fout19;
	fout19.open("SelectionSort_NearlySorted_30000.txt");
	if(!fout19)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n18; i++)
	{
		SelectionSort(u, n18);
		fout19 << u[i] << " ";
	}
	fout19.close();
	double time_start19, time_end19;
	static int v[100000];
	static int n19 = sizeof(v) / sizeof(v[0]);
	GenerateNearlySortedData(v, n19);
	time_start19 = clock();
	SelectionSort(v, n19);
	time_end19 = clock();
	cout << "Selection sort with 100000 elements nearly sorted: " << (time_end19 - time_start19) / CLK_TCK << " sec" << "\n";
	ofstream fout20;
	fout20.open("SelectionSort_NearlySorted_100000.txt");
	if(!fout20)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n19; i++)
	{
		SelectionSort(v, n19);
		fout20 << v[i] << " ";
	}
	fout20.close();*/



	////////////////////////Insertion Sort///////////////////////////////
	/*double time_start20, time_end20;
	int w[1000];
	int n20 = sizeof(w) / sizeof(w[0]);
	GenerateRandomData(w, n20);
	time_start20 = clock();
	insertionSort(w, n20);
	time_end20 = clock();
	cout << "Insertion sort with 1000 elements random: " << (time_end20 - time_start20) / CLK_TCK << " sec" << "\n";
	ofstream fout21;
	fout21.open("InsertionSort_Random_1000.txt");
	if(!fout21)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n20; i++)
	{
		insertionSort(w, n20);
		fout21 << w[i] << " ";
	}
	fout21.close();
	double time_start21, time_end21;
	int y[3000];
	int n21 = sizeof(y) / sizeof(y[0]);
	GenerateRandomData(y, n21);
	time_start21 = clock();
	insertionSort(y, n21);
	time_end21 = clock();
	cout << "Insertion sort with 3000 elements random: " << (time_end21 - time_start21) / CLK_TCK << " sec" << "\n";
	ofstream fout22;
	fout22.open("InsertionSort_Random_3000.txt");
	if(!fout22)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n21; i++)
	{
		insertionSort(y, n21);
		fout22 << y[i] << " ";
	}
	fout22.close();
	double time_start22, time_end22;
	int z[10000];
	int n22 = sizeof(z) / sizeof(z[0]);
	GenerateRandomData(z, n22);
	time_start22 = clock();
	insertionSort(z, n22);
	time_end22 = clock();
	cout << "Insertion sort with 10000 elements random: " << (time_end22 - time_start22) / CLK_TCK << " sec" << "\n";
	ofstream fout23;
	fout23.open("InsertionSort_Random_10000.txt");
	if(!fout23)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n22; i++)
	{
		insertionSort(z, n22);
		fout23 << z[i] << " ";
	}
	fout23.close();
	double time_start23, time_end23;
	static int a1[30000];
	static int n23 = sizeof(a1) / sizeof(a1[0]);
	GenerateRandomData(a1, n23);
	time_start23 = clock();
	insertionSort(a1, n23);
	time_end23 = clock();
	cout << "Insertion sort with 30000 elements random: " << (time_end23 - time_start23) / CLK_TCK << " sec" << "\n";
	ofstream fout24;
	fout24.open("InsertionSort_Random_30000.txt");
	if(!fout24)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n23; i++)
	{
		insertionSort(a1, n23);
		fout24 << a1[i] << " ";
	}
	fout24.close();
	double time_start24, time_end24;
	static int b1[100000];
	static int n24 = sizeof(b1) / sizeof(b1[0]);
	GenerateRandomData(b1, n24);
	time_start24 = clock();
	insertionSort(b1, n24);
	time_end24 = clock();
	cout << "Insertion sort with 100000 elements random: " << (time_end24 - time_start24) / CLK_TCK << " sec" << "\n";
	ofstream fout25;
	fout25.open("InsertionSort_Random_100000.txt");
	if(!fout25)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n24; i++)
	{
		insertionSort(b1, n24);
		fout25 << b1[i] << " ";
	}
	fout25.close();*/

	/*double time_start25, time_end25;
	int c1[1000];
	int n25 = sizeof(c1) / sizeof(c1[0]);
	GenerateSortedData(c1, n25);
	time_start25 = clock();
	insertionSort(c1, n25);
	time_end25 = clock();
	cout << "Insertion sort with 1000 elements sorted: " << (time_end25 - time_start25) / CLK_TCK << " sec" << "\n";
	ofstream fout26;
	fout26.open("InsertionSort_Sorted_1000.txt");
	if(!fout26)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n25; i++)
	{
		insertionSort(c1, n25);
		fout26 << c1[i] << " ";
	}
	fout26.close();
	double time_start26, time_end26;
	int d1[3000];
	int n26 = sizeof(d1) / sizeof(d1[0]);
	GenerateSortedData(d1, n26);
	time_start26 = clock();
	insertionSort(d1, n26);
	time_end26 = clock();
	cout << "Insertion sort with 3000 elements sorted: " << (time_end26 - time_start26) / CLK_TCK << " sec" << "\n";
	ofstream fout27;
	fout27.open("InsertionSort_Sorted_3000.txt");
	if(!fout27)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n26; i++)
	{
		insertionSort(d1, n26);
		fout27 << d1[i] << " ";
	}
	fout27.close();
	double time_start27, time_end27;
	int e1[10000];
	int n27 = sizeof(e1) / sizeof(e1[0]);
	GenerateSortedData(e1, n27);
	time_start27 = clock();
	insertionSort(e1, n27);
	time_end27 = clock();
	cout << "Insertion sort with 10000 elements sorted: " << (time_end27 - time_start27) / CLK_TCK << " sec" << "\n";
	ofstream fout28;
	fout28.open("InsertionSort_Sorted_10000.txt");
	if(!fout28)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n27; i++)
	{
		insertionSort(e1, n27);
		fout28 << e1[i] << " ";
	}
	fout28.close();
	double time_start28, time_end28;
	static int f1[30000];
	static int n28 = sizeof(f1) / sizeof(f1[0]);
	GenerateSortedData(f1, n28);
	time_start28 = clock();
	insertionSort(f1, n28);
	time_end28 = clock();
	cout << "Insertion sort with 30000 elements sorted: " << (time_end28 - time_start28) / CLK_TCK << " sec" << "\n";
	ofstream fout29;
	fout29.open("InsertionSort_Sorted_30000.txt");
	if(!fout29)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n28; i++)
	{
		insertionSort(f1, n28);
		fout29 << f1[i] << " ";
	}
	fout29.close();
	double time_start29, time_end29;
	static int g1[100000];
	static int n29 = sizeof(g1) / sizeof(g1[0]);
	GenerateSortedData(g1, n29);
	time_start29 = clock();
	insertionSort(g1, n29);
	time_end29 = clock();
	cout << "Insertion sort with 100000 elements sorted: " << (time_end29 - time_start29) / CLK_TCK << " sec" << "\n";
	ofstream fout30;
	fout30.open("InsertionSort_Sorted_100000.txt");
	if(!fout30)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n29; i++)
	{
		insertionSort(g1, n29);
		fout30 << g1[i] << " ";
	}
	fout30.close();*/

	/*double time_start30, time_end30;
	int h1[1000];
	int n30 = sizeof(h1) / sizeof(h1[0]);
	GenerateReverseData(h1, n30);
	time_start30 = clock();
	insertionSort(h1, n30);
	time_end30 = clock();
	cout << "Insertion sort with 1000 elements reversed: " << (time_end30 - time_start30) / CLK_TCK << " sec" << "\n";
	ofstream fout31;
	fout31.open("InsertionSort_Reversed_1000.txt");
	if(!fout31)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n30; i++)
	{
		insertionSort(h1, n30);
		fout31 << h1[i] << " ";
	}
	fout31.close();
	double time_start31, time_end31;
	int i1[3000];
	int n31 = sizeof(i1) / sizeof(i1[0]);
	GenerateReverseData(i1, n31);
	time_start31 = clock();
	insertionSort(i1, n31);
	time_end31 = clock();
	cout << "Insertion sort with 3000 elements reversed: " << (time_end31 - time_start31) / CLK_TCK << " sec" << "\n";
	ofstream fout32;
	fout32.open("InsertionSort_Reversed_3000.txt");
	if(!fout32)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n31; i++)
	{
		insertionSort(i1, n31);
		fout32 << i1[i] << " ";
	}
	fout32.close();
	double time_start32, time_end32;
	int j1[10000];
	int n32 = sizeof(j1) / sizeof(j1[0]);
	GenerateReverseData(j1, n32);
	time_start32 = clock();
	insertionSort(j1, n32);
	time_end32 = clock();
	cout << "Insertion sort with 10000 elements reversed: " << (time_end32 - time_start32) / CLK_TCK << " sec" << "\n";
	ofstream fout33;
	fout33.open("InsertionSort_Reversed_10000.txt");
	if(!fout33)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n32; i++)
	{
		insertionSort(j1, n32);
		fout33 << j1[i] << " ";
	}
	fout33.close();
	double time_start33, time_end33;
	static int k1[30000];
	static int n33 = sizeof(k1) / sizeof(k1[0]);
	GenerateReverseData(k1, n33);
	time_start33 = clock();
	insertionSort(k1, n33);
	time_end33 = clock();
	cout << "Insertion sort with 30000 elements reversed: " << (time_end33 - time_start33) / CLK_TCK << " sec" << "\n";
	ofstream fout34;
	fout34.open("InsertionSort_Reversed_30000.txt");
	if(!fout34)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n33; i++)
	{
		insertionSort(k1, n33);
		fout34 << k1[i] << " ";
	}
	fout34.close();
	double time_start34, time_end34;
	static int l1[100000];
	static int n34 = sizeof(l1) / sizeof(l1[0]);
	GenerateReverseData(l1, n34);
	time_start34 = clock();
	insertionSort(l1, n34);
	time_end34 = clock();
	cout << "Insertion sort with 100000 elements reversed: " << (time_end34 - time_start34) / CLK_TCK << " sec" << "\n";
	ofstream fout35;
	fout35.open("InsertionSort_Reversed_100000.txt");
	if(!fout35)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n34; i++)
	{
		insertionSort(l1, n34);
		fout35 << l1[i] << " ";
	}
	fout35.close();*/

	/*double time_start35, time_end35;
	int m1[1000];
	int n35 = sizeof(m1) / sizeof(m1[0]);
	GenerateNearlySortedData(m1, n35);
	time_start35 = clock();
	insertionSort(m1, n35);
	time_end35 = clock();
	cout << "Insertion sort with 1000 elements nearly sorted: " << (time_end35 - time_start35) / CLK_TCK << " sec" << "\n";
	ofstream fout36;
	fout36.open("InsertionSort_NearlySorted_1000.txt");
	if(!fout36)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n35; i++)
	{
		insertionSort(m1, n35);
		fout36 << m1[i] << " ";
	}
	fout36.close();
	double time_start36, time_end36;
	int n1[3000];
	int n36 = sizeof(n1) / sizeof(n1[0]);
	GenerateNearlySortedData(n1, n36);
	time_start36 = clock();
	insertionSort(n1, n36);
	time_end36 = clock();
	cout << "Insertion sort with 3000 elements nearly sorted: " << (time_end36 - time_start36) / CLK_TCK << " sec" << "\n";
	ofstream fout37;
	fout37.open("InsertionSort_NearlySorted_3000.txt");
	if(!fout37)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n36; i++)
	{
		insertionSort(n1, n36);
		fout37 << n1[i] << " ";
	}
	fout37.close();
	double time_start37, time_end37;
	int o1[10000];
	int n37 = sizeof(o1) / sizeof(o1[0]);
	GenerateNearlySortedData(o1, n37);
	time_start37 = clock();
	insertionSort(o1, n37);
	time_end37 = clock();
	cout << "Insertion sort with 10000 elements nearly sorted: " << (time_end37 - time_start37) / CLK_TCK << " sec" << "\n";
	ofstream fout38;
	fout38.open("InsertionSort_NearlySorted_10000.txt");
	if(!fout38)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n37; i++)
	{
		insertionSort(o1, n37);
		fout38 << o1[i] << " ";
	}
	fout38.close();
	double time_start38, time_end38;
	static int p1[30000];
	static int n38 = sizeof(p1) / sizeof(p1[0]);
	GenerateNearlySortedData(p1, n38);
	time_start38 = clock();
	insertionSort(p1, n38);
	time_end38 = clock();
	cout << "Insertion sort with 30000 elements nearly sorted: " << (time_end38 - time_start38) / CLK_TCK << " sec" << "\n";
	ofstream fout39;
	fout39.open("InsertionSort_NearlySorted_30000.txt");
	if(!fout39)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n38; i++)
	{
		insertionSort(p1, n38);
		fout39 << p1[i] << " ";
	}
	fout39.close();
	double time_start39, time_end39;
	static int q1[100000];
	static int n39 = sizeof(q1) / sizeof(q1[0]);
	GenerateNearlySortedData(q1, n39);
	time_start39 = clock();
	insertionSort(q1, n39);
	time_end39 = clock();
	cout << "Insertion sort with 100000 elements nearly sorted: " << (time_end39 - time_start39) / CLK_TCK << " sec" << "\n";
	ofstream fout40;
	fout40.open("InsertionSort_NearlySorted_100000.txt");
	if(!fout40)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n39; i++)
	{
		insertionSort(q1, n39);
		fout40 << q1[i] << " ";
	}
	fout40.close();*/




	///////////////////////////Binary Insertion Sort///////////////////////////////
	/*double time_start40, time_end40;
	int r1[1000];
	int n40 = sizeof(r1) / sizeof(r1[0]);
	GenerateRandomData(r1, n40);
	time_start40 = clock();
	BinaryInsertionSort(r1, n40);
	time_end40 = clock();
	cout << "Binary insertion sort with 1000 elements random: " << (time_end40 - time_start40) / CLK_TCK << " sec" << "\n";
	ofstream fout41;
	fout41.open("BinaryInsertionSort_Random_1000.txt");
	if(!fout41)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n40; i++)
	{
		BinaryInsertionSort(r1, n40);
		fout41 << r1[i] << " ";
	}
	fout41.close();
	double time_start41, time_end41;
	int s1[3000];
	int n41 = sizeof(s1) / sizeof(s1[0]);
	GenerateRandomData(s1, n41);
	time_start41 = clock();
	BinaryInsertionSort(s1, n41);
	time_end41 = clock();
	cout << "Binary insertion sort with 3000 elements random: " << (time_end41 - time_start41) / CLK_TCK << " sec" << "\n";
	ofstream fout42;
	fout42.open("BinaryInsertionSort_Random_3000.txt");
	if(!fout42)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n41; i++)
	{
		BinaryInsertionSort(s1, n41);
		fout42 << s1[i] << " ";
	}
	fout42.close();
	double time_start42, time_end42;
	int t1[10000];
	int n42 = sizeof(t1) / sizeof(t1[0]);
	GenerateRandomData(t1, n42);
	time_start42 = clock();
	BinaryInsertionSort(t1, n42);
	time_end42 = clock();
	cout << "Binary insertion sort with 10000 elements random: " << (time_end42 - time_start42) / CLK_TCK << " sec" << "\n";
	ofstream fout43;
	fout43.open("BinaryInsertionSort_Random_10000.txt");
	if(!fout43)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n42; i++)
	{
		BinaryInsertionSort(t1, n42);
		fout43 << t1[i] << " ";
	}
	fout43.close();
	double time_start43, time_end43;
	static int u1[30000];
	static int n43 = sizeof(u1) / sizeof(u1[0]);
	GenerateRandomData(u1, n43);
	time_start43 = clock();
	BinaryInsertionSort(u1, n43);
	time_end43 = clock();
	cout << "Binary insertion sort with 30000 elements random: " << (time_end43 - time_start43) / CLK_TCK << " sec" << "\n";
	ofstream fout44;
	fout44.open("BinaryInsertionSort_Random_30000.txt");
	if(!fout44)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n43; i++)
	{
		BinaryInsertionSort(u1, n43);
		fout44 << u1[i] << " ";
	}
	fout44.close();
	double time_start44, time_end44;
	static int v1[100000];
	static int n44 = sizeof(v1) / sizeof(v1[0]);
	GenerateRandomData(v1, n44);
	time_start44 = clock();
	BinaryInsertionSort(v1, n44);
	time_end44 = clock();
	cout << "Binary insertion sort with 100000 elements random: " << (time_end44 - time_start44) / CLK_TCK << " sec" << "\n";
	ofstream fout45;
	fout45.open("BinaryInsertionSort_Random_100000.txt");
	if(!fout45)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n44; i++)
	{
		BinaryInsertionSort(v1, n44);
		fout45 << v1[i] << " ";
	}
	fout45.close();*/

	/*double time_start45, time_end45;
	int w1[1000];
	int n45 = sizeof(w1) / sizeof(w1[0]);
	GenerateSortedData(w1, n45);
	time_start45 = clock();
	BinaryInsertionSort(w1, n45);
	time_end45 = clock();
	cout << "Binary insertion sort with 1000 elements sorted: " << (time_end45 - time_start45) / CLK_TCK << " sec" << "\n";
	ofstream fout46;
	fout46.open("BinaryInsertionSort_Sorted_1000.txt");
	if(!fout46)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n45; i++)
	{
		BinaryInsertionSort(w1, n45);
		fout46 << w1[i] << " ";
	}
	fout46.close();
	double time_start46, time_end46;
	int x1[3000];
	int n46 = sizeof(x1) / sizeof(x1[0]);
	GenerateSortedData(x1, n46);
	time_start46 = clock();
	BinaryInsertionSort(x1, n46);
	time_end46 = clock();
	cout << "Binary insertion sort with 3000 elements sorted: " << (time_end46 - time_start46) / CLK_TCK << " sec" << "\n";
	ofstream fout47;
	fout47.open("BinaryInsertionSort_Sorted_3000.txt");
	if(!fout47)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n46; i++)
	{
		BinaryInsertionSort(x1, n46);
		fout47 << x1[i] << " ";
	}
	fout47.close();
	double time_start47, time_end47;
	int y1[10000];
	int n47 = sizeof(y1) / sizeof(y1[0]);
	GenerateSortedData(y1, n47);
	time_start47 = clock();
	BinaryInsertionSort(y1, n47);
	time_end47 = clock();
	cout << "Binary insertion sort with 10000 elements sorted: " << (time_end47 - time_start47) / CLK_TCK << " sec" << "\n";
	ofstream fout48;
	fout48.open("BinaryInsertionSort_Sorted_10000.txt");
	if(!fout48)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n47; i++)
	{
		BinaryInsertionSort(y1, n47);
		fout48 << y1[i] << " ";
	}
	fout48.close();
	double time_start48, time_end48;
	static int z1[30000];
	static int n48 = sizeof(z1) / sizeof(z1[0]);
	GenerateSortedData(z1, n48);
	time_start48 = clock();
	BinaryInsertionSort(z1, n48);
	time_end48 = clock();
	cout << "Binary insertion sort with 30000 elements sorted: " << (time_end48 - time_start48) / CLK_TCK << " sec" << "\n";
	ofstream fout49;
	fout49.open("BinaryInsertionSort_Sorted_30000.txt");
	if(!fout49)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n48; i++)
	{
		BinaryInsertionSort(z1, n48);
		fout49 << z1[i] << " ";
	}
	fout49.close();
	double time_start49, time_end49;
	static int a11[100000];
	static int n49 = sizeof(a11) / sizeof(a11[0]);
	GenerateSortedData(a11, n49);
	time_start49 = clock();
	BinaryInsertionSort(a11, n49);
	time_end49 = clock();
	cout << "Binary insertion sort with 100000 elements sorted: " << (time_end49 - time_start49) / CLK_TCK << " sec" << "\n";
	ofstream fout50;
	fout50.open("BinaryInsertionSort_Sorted_100000.txt");
	if(!fout50)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n49; i++)
	{
		BinaryInsertionSort(a11, n49);
		fout50 << a11[i] << " ";
	}
	fout50.close();*/

	/*double time_start50, time_end50;
	int b11[1000];
	int n50 = sizeof(b11) / sizeof(b11[0]);
	GenerateReverseData(b11, n50);
	time_start50 = clock();
	BinaryInsertionSort(b11, n50);
	time_end50 = clock();
	cout << "Binary insertion sort with 1000 elements reversed: " << (time_end50 - time_start50) / CLK_TCK << " sec" << "\n";
	ofstream fout51;
	fout51.open("BinaryInsertionSort_Reversed_1000.txt");
	if(!fout51)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n50; i++)
	{
		BinaryInsertionSort(b11, n50);
		fout51 << b11[i] << " ";
	}
	fout51.close();
	double time_start51, time_end51;
	int c11[3000];
	int n51 = sizeof(c11) / sizeof(c11[0]);
	GenerateReverseData(c11, n51);
	time_start51 = clock();
	BinaryInsertionSort(c11, n51);
	time_end51 = clock();
	cout << "Binary insertion sort with 3000 elements reversed: " << (time_end51 - time_start51) / CLK_TCK << " sec" << "\n";
	ofstream fout52;
	fout52.open("BinaryInsertionSort_Reversed_3000.txt");
	if(!fout52)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n51; i++)
	{
		BinaryInsertionSort(c11, n51);
		fout52 << c11[i] << " ";
	}
	fout52.close();
	double time_start52, time_end52;
	int d11[10000];
	int n52 = sizeof(d11) / sizeof(d11[0]);
	GenerateReverseData(d11, n52);
	time_start52 = clock();
	BinaryInsertionSort(d11, n52);
	time_end52 = clock();
	cout << "Binary insertion sort with 10000 elements reversed: " << (time_end52 - time_start52) / CLK_TCK << " sec" << "\n";
	ofstream fout53;
	fout53.open("BinaryInsertionSort_Reversed_10000.txt");
	if(!fout53)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n52; i++)
	{
		BinaryInsertionSort(d11, n52);
		fout53 << d11[i] << " ";
	}
	fout53.close();
	double time_start53, time_end53;
	static int e11[30000];
	static int n53 = sizeof(e11) / sizeof(e11[0]);
	GenerateReverseData(e11, n53);
	time_start53 = clock();
	BinaryInsertionSort(e11, n53);
	time_end53 = clock();
	cout << "Binary insertion sort with 30000 elements reversed: " << (time_end53 - time_start53) / CLK_TCK << " sec" << "\n";
	ofstream fout54;
	fout54.open("BinaryInsertionSort_Reversed_30000.txt");
	if(!fout54)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n53; i++)
	{
		BinaryInsertionSort(e11, n53);
		fout54 << e11[i] << " ";
	}
	fout54.close();
	double time_start54, time_end54;
	static int f11[100000];
	static int n54 = sizeof(f11) / sizeof(f11[0]);
	GenerateReverseData(f11, n54);
	time_start54 = clock();
	BinaryInsertionSort(f11, n54);
	time_end54 = clock();
	cout << "Binary insertion sort with 100000 elements reversed: " << (time_end54 - time_start54) / CLK_TCK << " sec" << "\n";
	ofstream fout55;
	fout55.open("BinaryInsertionSort_Reversed_100000.txt");
	if(!fout55)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n54; i++)
	{
		BinaryInsertionSort(f11, n54);
		fout55 << f11[i] << " ";
	}
	fout55.close();*/

	/*double time_start55, time_end55;
	int g11[1000];
	int n55 = sizeof(g11) / sizeof(g11[0]);
	GenerateNearlySortedData(g11, n55);
	time_start55 = clock();
	BinaryInsertionSort(g11, n55);
	time_end55 = clock();
	cout << "Binary insertion sort with 1000 elements nearly sorted: " << (time_end55 - time_start55) / CLK_TCK << " sec" << "\n";
	ofstream fout56;
	fout56.open("BinaryInsertionSort_NearlySorted_1000.txt");
	if(!fout56)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n55; i++)
	{
		BinaryInsertionSort(g11, n55);
		fout56 << g11[i] << " ";
	}
	fout56.close();
	double time_start56, time_end56;
	int h11[3000];
	int n56 = sizeof(h11) / sizeof(h11[0]);
	GenerateNearlySortedData(h11, n56);
	time_start56 = clock();
	BinaryInsertionSort(h11, n56);
	time_end56 = clock();
	cout << "Binary insertion sort with 3000 elements nearly sorted: " << (time_end56 - time_start56) / CLK_TCK << " sec" << "\n";
	ofstream fout57;
	fout57.open("BinaryInsertionSort_NearlySorted_3000.txt");
	if(!fout57)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n56; i++)
	{
		BinaryInsertionSort(h11, n56);
		fout57 << h11[i] << " ";
	}
	fout57.close();
	double time_start57, time_end57;
	int i11[10000];
	int n57 = sizeof(i11) / sizeof(i11[0]);
	GenerateNearlySortedData(i11, n57);
	time_start57 = clock();
	BinaryInsertionSort(i11, n57);
	time_end57 = clock();
	cout << "Binary insertion sort with 10000 elements nearly sorted: " << (time_end57 - time_start57) / CLK_TCK << " sec" << "\n";
	ofstream fout58;
	fout58.open("BinaryInsertionSort_NearlySorted_10000.txt");
	if(!fout58)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n57; i++)
	{
		BinaryInsertionSort(i11, n57);
		fout58 << i11[i] << " ";
	}
	fout58.close();
	double time_start58, time_end58;
	static int j11[30000];
	static int n58 = sizeof(j11) / sizeof(j11[0]);
	GenerateNearlySortedData(j11, n58);
	time_start58 = clock();
	BinaryInsertionSort(j11, n58);
	time_end58 = clock();
	cout << "Binary insertion sort with 30000 elements nearly sorted: " << (time_end58 - time_start58) / CLK_TCK << " sec" << "\n";
	ofstream fout59;
	fout59.open("BinaryInsertionSort_NearlySorted_30000.txt");
	if(!fout59)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n58; i++)
	{
		BinaryInsertionSort(j11, n58);
		fout59 << j11[i] << " ";
	}
	fout59.close();
	double time_start59, time_end59;
	static int k11[100000];
	static int n59 = sizeof(k11) / sizeof(k11[0]);
	GenerateNearlySortedData(k11, n59);
	time_start59 = clock();
	BinaryInsertionSort(k11, n59);
	time_end59 = clock();
	cout << "Binary insertion sort with 100000 elements nearly sorted: " << (time_end59 - time_start59) / CLK_TCK << " sec" << "\n";
	ofstream fout60;
	fout60.open("BinaryInsertionSort_NearlySorted_100000.txt");
	if(!fout60)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n59; i++)
	{
		BinaryInsertionSort(k11, n59);
		fout60 << k11[i] << " ";
	}
	fout60.close();*/




	///////////////////////////Bubble Sort//////////////////////////////
	/*double time_start60, time_end60;
	int l11[1000];
	int n60 = sizeof(l11) / sizeof(l11[0]);
	GenerateRandomData(l11, n60);
	time_start60 = clock();
	bubleSort(l11, n60);
	time_end60 = clock();
	cout << "Bubble sort with 1000 elements random: " << (time_end60 - time_start60) / CLK_TCK << " sec" << "\n";
	ofstream fout61;
	fout61.open("BubbleSort_Random_1000.txt");
	if(!fout61)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n60; i++)
	{
		bubleSort(l11, n60);
		fout61 << l11[i] << " ";
	}
	fout61.close();
	double time_start61, time_end61;
	int m11[3000];
	int n61 = sizeof(m11) / sizeof(m11[0]);
	GenerateRandomData(m11, n61);
	time_start61 = clock();
	bubleSort(m11, n61);
	time_end61 = clock();
	cout << "Bubble sort with 3000 elements random: " << (time_end61 - time_start61) / CLK_TCK << " sec" << "\n";
	ofstream fout62;
	fout62.open("BubbleSort_Random_3000.txt");
	if(!fout62)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n61; i++)
	{
		bubleSort(m11, n61);
		fout62 << m11[i] << " ";
	}
	fout62.close();
	double time_start62, time_end62;
	int n11[10000];
	int n62 = sizeof(n11) / sizeof(n11[0]);
	GenerateRandomData(n11, n62);
	time_start62 = clock();
	bubleSort(n11, n62);
	time_end62 = clock();
	cout << "Bubble sort with 10000 elements random: " << (time_end62 - time_start62) / CLK_TCK << " sec" << "\n";
	ofstream fout63;
	fout63.open("BubbleSort_Random_10000.txt");
	if(!fout63)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n62; i++)
	{
		bubleSort(n11, n62);
		fout63 << n11[i] << " ";
	}
	fout63.close();
	double time_start63, time_end63;
	static int o11[30000];
	static int n63 = sizeof(o11) / sizeof(o11[0]);
	GenerateRandomData(o11, n63);
	time_start63 = clock();
	bubleSort(o11, n63);
	time_end63 = clock();
	cout << "Bubble sort with 30000 elements random: " << (time_end63 - time_start63) / CLK_TCK << " sec" << "\n";
	ofstream fout64;
	fout64.open("BubbleSort_Random_30000.txt");
	if(!fout64)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n63; i++)
	{
		bubleSort(o11, n63);
		fout64 << o11[i] << " ";
	}
	fout64.close();
	double time_start64, time_end64;
	static int p11[100000];
	static int n64 = sizeof(p11) / sizeof(p11[0]);
	GenerateRandomData(p11, n64);
	time_start64 = clock();
	bubleSort(p11, n64);
	time_end64 = clock();
	cout << "Bubble sort with 100000 elements random: " << (time_end64 - time_start64) / CLK_TCK << " sec" << "\n";
	ofstream fout65;
	fout65.open("BubbleSort_Random_100000.txt");
	if(!fout65)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n64; i++)
	{
		bubleSort(p11, n64);
		fout65 << p11[i] << " ";
	}
	fout65.close();*/

	/*double time_start65, time_end65;
	int q11[1000];
	int n65 = sizeof(q11) / sizeof(q11[0]);
	GenerateSortedData(q11, n65);
	time_start65 = clock();
	bubleSort(q11, n65);
	time_end65 = clock();
	cout << "Bubble sort with 1000 elements sorted: " << (time_end65 - time_start65) / CLK_TCK << " sec" << "\n";
	ofstream fout66;
	fout66.open("BubbleSort_Sorted_1000.txt");
	if(!fout66)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n65; i++)
	{
		bubleSort(q11, n65);
		fout66 << q11[i] << " ";
	}
	fout66.close();
	double time_start66, time_end66;
	int r11[3000];
	int n66 = sizeof(r11) / sizeof(r11[0]);
	GenerateSortedData(r11, n66);
	time_start66 = clock();
	bubleSort(r11, n66);
	time_end66 = clock();
	cout << "Bubble sort with 3000 elements sorted: " << (time_end66 - time_start66) / CLK_TCK << " sec" << "\n";
	ofstream fout67;
	fout67.open("BubbleSort_Sorted_3000.txt");
	if(!fout67)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n66; i++)
	{
		bubleSort(r11, n66);
		fout67 << r11[i] << " ";
	}
	fout67.close();
	double time_start67, time_end67;
	int s11[10000];
	int n67 = sizeof(s11) / sizeof(s11[0]);
	GenerateSortedData(s11, n67);
	time_start67 = clock();
	bubleSort(s11, n67);
	time_end67 = clock();
	cout << "Bubble sort with 10000 elements sorted: " << (time_end67 - time_start67) / CLK_TCK << " sec" << "\n";
	ofstream fout68;
	fout68.open("BubbleSort_Sorted_10000.txt");
	if(!fout68)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n67; i++)
	{
		bubleSort(s11, n67);
		fout68 << s11[i] << " ";
	}
	fout68.close();
	double time_start68, time_end68;
	static int t11[30000];
	static int n68 = sizeof(t11) / sizeof(t11[0]);
	GenerateSortedData(t11, n68);
	time_start68 = clock();
	bubleSort(t11, n68);
	time_end68 = clock();
	cout << "Bubble sort with 30000 elements sorted: " << (time_end68 - time_start68) / CLK_TCK << " sec" << "\n";
	ofstream fout69;
	fout69.open("BubbleSort_Sorted_30000.txt");
	if(!fout69)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n68; i++)
	{
		bubleSort(t11, n68);
		fout69 << t11[i] << " ";
	}
	fout69.close();
	double time_start69, time_end69;
	static int u11[100000];
	static int n69 = sizeof(u11) / sizeof(u11[0]);
	GenerateSortedData(u11, n69);
	time_start69 = clock();
	bubleSort(u11, n69);
	time_end69 = clock();
	cout << "Bubble sort with 100000 elements sorted: " << (time_end69 - time_start69) / CLK_TCK << " sec" << "\n";
	ofstream fout70;
	fout70.open("BubbleSort_Sorted_100000.txt");
	if(!fout70)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n69; i++)
	{
		bubleSort(u11, n69);
		fout70 << u11[i] << " ";
	}
	fout70.close();*/

	/*double time_start70, time_end70;
	int v11[1000];
	int n70 = sizeof(v11) / sizeof(v11[0]);
	GenerateReverseData(v11, n70);
	time_start70 = clock();
	bubleSort(v11, n70);
	time_end70 = clock();
	cout << "Bubble sort with 1000 elements reversed: " << (time_end70 - time_start70) / CLK_TCK << " sec" << "\n";
	ofstream fout71;
	fout71.open("BubbleSort_Reversed_1000.txt");
	if(!fout71)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n70; i++)
	{
		bubleSort(v11, n70);
		fout71 << v11[i] << " ";
	}
	fout71.close();
	double time_start71, time_end71;
	int w11[3000];
	int n71 = sizeof(w11) / sizeof(w11[0]);
	GenerateReverseData(w11, n71);
	time_start71 = clock();
	bubleSort(w11, n71);
	time_end71 = clock();
	cout << "Bubble sort with 3000 elements reversed: " << (time_end71 - time_start71) / CLK_TCK << " sec" << "\n";
	ofstream fout72;
	fout72.open("BubbleSort_Reversed_3000.txt");
	if(!fout72)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n71; i++)
	{
		bubleSort(w11, n71);
		fout72 << w11[i] << " ";
	}
	fout72.close();
	double time_start72, time_end72;
	int x11[10000];
	int n72 = sizeof(x11) / sizeof(x11[0]);
	GenerateReverseData(x11, n72);
	time_start72 = clock();
	bubleSort(x11, n72);
	time_end72 = clock();
	cout << "Bubble sort with 10000 elements reversed: " << (time_end72 - time_start72) / CLK_TCK << " sec" << "\n";
	ofstream fout73;
	fout73.open("BubbleSort_Reversed_10000.txt");
	if(!fout73)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n72; i++)
	{
		bubleSort(x11, n72);
		fout73 << x11[i] << " ";
	}
	fout73.close();
	double time_start73, time_end73;
	static int y11[30000];
	static int n73 = sizeof(y11) / sizeof(y11[0]);
	GenerateReverseData(y11, n73);
	time_start73 = clock();
	bubleSort(y11, n73);
	time_end73 = clock();
	cout << "Bubble sort with 30000 elements reversed: " << (time_end73 - time_start73) / CLK_TCK << " sec" << "\n";
	ofstream fout74;
	fout74.open("BubbleSort_Reversed_30000.txt");
	if(!fout74)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n73; i++)
	{
		bubleSort(y11, n73);
		fout74 << y11[i] << " ";
	}
	fout74.close();
	double time_start74, time_end74;
	static int z11[100000];
	static int n74 = sizeof(z11) / sizeof(z11[0]);
	GenerateReverseData(z11, n74);
	time_start74 = clock();
	bubleSort(z11, n74);
	time_end74 = clock();
	cout << "Bubble sort with 100000 elements reversed: " << (time_end74 - time_start74) / CLK_TCK << " sec" << "\n";
	ofstream fout75;
	fout75.open("BubbleSort_Reversed_100000.txt");
	if(!fout75)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n74; i++)
	{
		bubleSort(z11, n74);
		fout75 << z11[i] << " ";
	}
	fout75.close();*/

	/*double time_start75, time_end75;
	int a111[1000];
	int n75 = sizeof(a111) / sizeof(a111[0]);
	GenerateNearlySortedData(a111, n75);
	time_start75 = clock();
	bubleSort(a111, n75);
	time_end75 = clock();
	cout << "Bubble sort with 1000 elements nearly sorted: " << (time_end75 - time_start75) / CLK_TCK << " sec" << "\n";
	ofstream fout76;
	fout76.open("BubbleSort_NearlySorted_1000.txt");
	if(!fout76)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n75; i++)
	{
		bubleSort(a111, n75);
		fout76 << a111[i] << " ";
	}
	fout76.close();
	double time_start76, time_end76;
	int b111[3000];
	int n76 = sizeof(b111) / sizeof(b111[0]);
	GenerateNearlySortedData(b111, n76);
	time_start76 = clock();
	bubleSort(b111, n76);
	time_end76 = clock();
	cout << "Bubble sort with 3000 elements nearly sorted: " << (time_end76 - time_start76) / CLK_TCK << " sec" << "\n";
	ofstream fout77;
	fout77.open("BubbleSort_NearlySorted_3000.txt");
	if(!fout77)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n76; i++)
	{
		bubleSort(b111, n76);
		fout77 << b111[i] << " ";
	}
	fout77.close();
	double time_start77, time_end77;
	int c111[10000];
	int n77 = sizeof(c111) / sizeof(c111[0]);
	GenerateNearlySortedData(c111, n77);
	time_start77 = clock();
	bubleSort(c111, n77);
	time_end77 = clock();
	cout << "Bubble sort with 10000 elements nearly sorted: " << (time_end77 - time_start77) / CLK_TCK << " sec" << "\n";
	ofstream fout78;
	fout78.open("BubbleSort_NearlySorted_10000.txt");
	if(!fout78)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n77; i++)
	{
		bubleSort(c111, n77);
		fout78 << c111[i] << " ";
	}
	fout78.close();
	double time_start78, time_end78;
	static int d111[30000];
	static int n78 = sizeof(d111) / sizeof(d111[0]);
	GenerateNearlySortedData(d111, n78);
	time_start78 = clock();
	bubleSort(d111, n78);
	time_end78 = clock();
	cout << "Bubble sort with 30000 elements nearly sorted: " << (time_end78 - time_start78) / CLK_TCK << " sec" << "\n";
	ofstream fout79;
	fout79.open("BubbleSort_NearlySorted_30000.txt");
	if(!fout79)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n78; i++)
	{
		bubleSort(d111, n78);
		fout79 << d111[i] << " ";
	}
	fout79.close();
	double time_start79, time_end79;
	static int e111[100000];
	static int n79 = sizeof(e111) / sizeof(e111[0]);
	GenerateNearlySortedData(e111, n79);
	time_start79 = clock();
	bubleSort(e111, n79);
	time_end79 = clock();
	cout << "Bubble sort with 100000 elements nearly sorted: " << (time_end79 - time_start79) / CLK_TCK << " sec" << "\n";
	ofstream fout80;
	fout80.open("BubbleSort_NearlySorted_100000.txt");
	if(!fout80)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n79; i++)
	{
		bubleSort(e111, n79);
		fout80 << e111[i] << " ";
	}
	fout80.close();*/




	////////////////////////////////Shaker Sort///////////////////////////////////
	/*double time_start80, time_end80;
	int f111[1000];
	int n80 = sizeof(f111) / sizeof(f111[0]);
	GenerateRandomData(f111, n80);
	time_start80 = clock();
	shakerSort(f111, n80);
	time_end80 = clock();
	cout << "Shaker sort with 1000 elements random: " << (time_end80 - time_start80) / CLK_TCK << " sec" << "\n";
	ofstream fout81;
	fout81.open("ShakerSort_Random_1000.txt");
	if(!fout81)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n80; i++)
	{
		shakerSort(f111, n80);
		fout81 << f111[i] << " ";
	}
	fout81.close();
	double time_start81, time_end81;
	int g111[3000];
	int n81 = sizeof(g111) / sizeof(g111[0]);
	GenerateRandomData(g111, n81);
	time_start81 = clock();
	shakerSort(g111, n81);
	time_end81 = clock();
	cout << "Shaker sort with 3000 elements random: " << (time_end81 - time_start81) / CLK_TCK << " sec" << "\n";
	ofstream fout82;
	fout82.open("ShakerSort_Random_3000.txt");
	if(!fout82)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n81; i++)
	{
		shakerSort(g111, n81);
		fout82 << g111[i] << " ";
	}
	fout82.close();
	double time_start82, time_end82;
	int h111[10000];
	int n82 = sizeof(h111) / sizeof(h111[0]);
	GenerateRandomData(h111, n82);
	time_start82 = clock();
	shakerSort(h111, n82);
	time_end82 = clock();
	cout << "Shaker sort with 10000 elements random: " << (time_end82 - time_start82) / CLK_TCK << " sec" << "\n";
	ofstream fout83;
	fout83.open("ShakerSort_Random_10000.txt");
	if(!fout83)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n82; i++)
	{
		shakerSort(h111, n82);
		fout83 << h111[i] << " ";
	}
	fout83.close();
	double time_start83, time_end83;
	static int i111[30000];
	static int n83 = sizeof(i111) / sizeof(i111[0]);
	GenerateRandomData(i111, n83);
	time_start83 = clock();
	shakerSort(i111, n83);
	time_end83 = clock();
	cout << "Shaker sort with 30000 elements random: " << (time_end83 - time_start83) / CLK_TCK << " sec" << "\n";
	ofstream fout84;
	fout84.open("ShakerSort_Random_30000.txt");
	if(!fout84)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n83; i++)
	{
		shakerSort(i111, n83);
		fout84 << i111[i] << " ";
	}
	fout84.close();
	double time_start84, time_end84;
	static int j111[100000];
	static int n84 = sizeof(j111) / sizeof(j111[0]);
	GenerateRandomData(j111, n84);
	time_start84 = clock();
	shakerSort(j111, n84);
	time_end84 = clock();
	cout << "Shaker sort with 100000 elements random: " << (time_end84 - time_start84) / CLK_TCK << " sec" << "\n";
	ofstream fout85;
	fout85.open("ShakerSort_Random_100000.txt");
	if(!fout85)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n84; i++)
	{
		shakerSort(j111, n84);
		fout85 << j111[i] << " ";
	}
	fout85.close();*/

	/*double time_start85, time_end85;
	int k111[1000];
	int n85 = sizeof(k111) / sizeof(k111[0]);
	GenerateSortedData(k111, n85);
	time_start85 = clock();
	shakerSort(k111, n85);
	time_end85 = clock();
	cout << "Shaker sort with 1000 elements sorted: " << (time_end85 - time_start85) / CLK_TCK << " sec" << "\n";
	ofstream fout86;
	fout86.open("ShakerSort_Sorted_1000.txt");
	if(!fout86)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n85; i++)
	{
		shakerSort(k111, n85);
		fout86 << k111[i] << " ";
	}
	fout86.close();
	double time_start86, time_end86;
	int l111[3000];
	int n86 = sizeof(l111) / sizeof(l111[0]);
	GenerateSortedData(l111, n86);
	time_start86 = clock();
	shakerSort(l111, n86);
	time_end86 = clock();
	cout << "Shaker sort with 3000 elements sorted: " << (time_end86 - time_start86) / CLK_TCK << " sec" << "\n";
	ofstream fout87;
	fout87.open("ShakerSort_Sorted_3000.txt");
	if(!fout87)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n86; i++)
	{
		shakerSort(l111, n86);
		fout87 << l111[i] << " ";
	}
	fout87.close();
	double time_start87, time_end87;
	int m111[10000];
	int n87 = sizeof(m111) / sizeof(m111[0]);
	GenerateSortedData(m111, n87);
	time_start87 = clock();
	shakerSort(m111, n87);
	time_end87 = clock();
	cout << "Shaker sort with 10000 elements sorted: " << (time_end87 - time_start87) / CLK_TCK << " sec" << "\n";
	ofstream fout88;
	fout88.open("ShakerSort_Sorted_10000.txt");
	if(!fout88)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n87; i++)
	{
		shakerSort(m111, n87);
		fout88 << m111[i] << " ";
	}
	fout88.close();
	double time_start88, time_end88;
	static int n111[30000];
	static int n88 = sizeof(n111) / sizeof(n111[0]);
	GenerateSortedData(n111, n88);
	time_start88 = clock();
	shakerSort(n111, n88);
	time_end88 = clock();
	cout << "Shaker sort with 30000 elements sorted: " << (time_end88 - time_start88) / CLK_TCK << " sec" << "\n";
	ofstream fout89;
	fout89.open("ShakerSort_Sorted_30000.txt");
	if(!fout89)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n88; i++)
	{
		shakerSort(n111, n88);
		fout89 << n111[i] << " ";
	}
	fout89.close();
	double time_start89, time_end89;
	static int o111[100000];
	static int n89 = sizeof(o111) / sizeof(o111[0]);
	GenerateSortedData(o111, n89);
	time_start89 = clock();
	shakerSort(o111, n89);
	time_end89 = clock();
	cout << "Shaker sort with 100000 elements sorted: " << (time_end89 - time_start89) / CLK_TCK << " sec" << "\n";
	ofstream fout90;
	fout90.open("ShakerSort_Sorted_100000.txt");
	if(!fout90)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n89; i++)
	{
		shakerSort(o111, n89);
		fout90 << o111[i] << " ";
	}
	fout90.close();*/

	/*double time_start90, time_end90;
	int p111[1000];
	int n90 = sizeof(p111) / sizeof(p111[0]);
	GenerateReverseData(p111, n90);
	time_start90 = clock();
	shakerSort(p111, n90);
	time_end90 = clock();
	cout << "Shaker sort with 1000 elements reversed: " << (time_end90 - time_start90) / CLK_TCK << " sec" << "\n";
	ofstream fout91;
	fout91.open("ShakerSort_Reversed_1000.txt");
	if(!fout91)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n90; i++)
	{
		shakerSort(p111, n90);
		fout91 << p111[i] << " ";
	}
	fout91.close();
	double time_start91, time_end91;
	int q111[3000];
	int n91 = sizeof(q111) / sizeof(q111[0]);
	GenerateReverseData(q111, n91);
	time_start91 = clock();
	shakerSort(q111, n91);
	time_end91 = clock();
	cout << "Shaker sort with 3000 elements reversed: " << (time_end91 - time_start91) / CLK_TCK << " sec" << "\n";
	ofstream fout92;
	fout92.open("ShakerSort_Reversed_3000.txt");
	if(!fout92)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n91; i++)
	{
		shakerSort(q111, n91);
		fout92 << q111[i] << " ";
	}
	fout92.close();
	double time_start92, time_end92;
	int r111[10000];
	int n92 = sizeof(r111) / sizeof(r111[0]);
	GenerateReverseData(r111, n92);
	time_start92 = clock();
	shakerSort(r111, n92);
	time_end92 = clock();
	cout << "Shaker sort with 10000 elements reversed: " << (time_end92 - time_start92) / CLK_TCK << " sec" << "\n";
	ofstream fout93;
	fout93.open("ShakerSort_Reversed_10000.txt");
	if(!fout93)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n92; i++)
	{
		shakerSort(r111, n92);
		fout93 << r111[i] << " ";
	}
	fout93.close();
	double time_start93, time_end93;
	static int s111[30000];
	static int n93 = sizeof(s111) / sizeof(s111[0]);
	GenerateReverseData(s111, n93);
	time_start93 = clock();
	shakerSort(s111, n93);
	time_end93 = clock();
	cout << "Shaker sort with 30000 elements reversed: " << (time_end93 - time_start93) / CLK_TCK << " sec" << "\n";
	ofstream fout94;
	fout94.open("ShakerSort_Reversed_30000.txt");
	if(!fout94)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n93; i++)
	{
		shakerSort(s111, n93);
		fout94 << s111[i] << " ";
	}
	fout94.close();
	double time_start94, time_end94;
	static int t111[100000];
	static int n94 = sizeof(t111) / sizeof(t111[0]);
	GenerateReverseData(t111, n94);
	time_start94 = clock();
	shakerSort(t111, n94);
	time_end94 = clock();
	cout << "Shaker sort with 100000 elements reversed: " << (time_end94 - time_start94) / CLK_TCK << " sec" << "\n";
	ofstream fout95;
	fout95.open("ShakerSort_Reversed_100000.txt");
	if(!fout95)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n94; i++)
	{
		shakerSort(t111, n94);
		fout95 << t111[i] << " ";
	}
	fout95.close();*/

	/*double time_start95, time_end95;
	int u111[1000];
	int n95 = sizeof(u111) / sizeof(u111[0]);
	GenerateNearlySortedData(u111, n95);
	time_start95 = clock();
	shakerSort(u111, n95);
	time_end95 = clock();
	cout << "Shaker sort with 1000 elements nearly sorted: " << (time_end95 - time_start95) / CLK_TCK << " sec" << "\n";
	ofstream fout96;
	fout96.open("ShakerSort_NearlySorted_1000.txt");
	if(!fout96)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n95; i++)
	{
		shakerSort(u111, n95);
		fout96 << u111[i] << " ";
	}
	fout96.close();
	double time_start96, time_end96;
	int v111[3000];
	int n96 = sizeof(v111) / sizeof(v111[0]);
	GenerateNearlySortedData(v111, n96);
	time_start96 = clock();
	shakerSort(v111, n96);
	time_end96 = clock();
	cout << "Shaker sort with 3000 elements nearly sorted: " << (time_end96 - time_start96) / CLK_TCK << " sec" << "\n";
	ofstream fout97;
	fout97.open("ShakerSort_NearlySorted_3000.txt");
	if(!fout97)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n96; i++)
	{
		shakerSort(v111, n96);
		fout97 << v111[i] << " ";
	}
	fout97.close();
	double time_start97, time_end97;
	int w111[10000];
	int n97 = sizeof(w111) / sizeof(w111[0]);
	GenerateNearlySortedData(w111, n97);
	time_start97 = clock();
	shakerSort(w111, n97);
	time_end97 = clock();
	cout << "Shaker sort with 10000 elements nearly sorted: " << (time_end97 - time_start97) / CLK_TCK << " sec" << "\n";
	ofstream fout98;
	fout98.open("ShakerSort_NearlySorted_10000.txt");
	if(!fout98)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n97; i++)
	{
		shakerSort(w111, n97);
		fout98 << w111[i] << " ";
	}
	fout98.close();
	double time_start98, time_end98;
	static int x111[30000];
	static int n98 = sizeof(x111) / sizeof(x111[0]);
	GenerateNearlySortedData(x111, n98);
	time_start98 = clock();
	shakerSort(x111, n98);
	time_end98 = clock();
	cout << "Shaker sort with 30000 elements nearly sorted: " << (time_end98 - time_start98) / CLK_TCK << " sec" << "\n";
	ofstream fout99;
	fout99.open("ShakerSort_NearlySorted_30000.txt");
	if(!fout99)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n98; i++)
	{
		shakerSort(x111, n98);
		fout99 << x111[i] << " ";
	}
	fout99.close();
	double time_start99, time_end99;
	static int y111[100000];
	static int n99 = sizeof(y111) / sizeof(y111[0]);
	GenerateNearlySortedData(y111, n99);
	time_start99 = clock();
	shakerSort(y111, n99);
	time_end99 = clock();
	cout << "Shaker sort with 100000 elements nearly sorted: " << (time_end99 - time_start99) / CLK_TCK << " sec" << "\n";
	ofstream fout100;
	fout100.open("ShakerSort_NearlySorted_100000.txt");
	if(!fout100)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n99; i++)
	{
		shakerSort(y111, n99);
		fout100 << y111[i] << " ";
	}
	fout100.close();*/




	////////////////////////////////Shell Sort////////////////////////////////
	/*double time_start100, time_end100;
	int z111[1000];
	int n100 = sizeof(z111) / sizeof(z111[0]);
	GenerateRandomData(z111, n100);
	time_start100 = clock();
	shellSort(z111, n100);
	time_end100 = clock();
	cout << "Shell sort with 1000 elements random: " << (time_end100 - time_start100) / CLK_TCK << " sec" << "\n";
	ofstream fout101;
	fout101.open("ShellSort_Random_1000.txt");
	if(!fout101)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n100; i++)
	{
		shellSort(z111, n100);
		fout101 << z111[i] << " ";
	}
	fout101.close();
	double time_start101, time_end101;
	int a1111[3000];
	int n101 = sizeof(a1111) / sizeof(a1111[0]);
	GenerateRandomData(a1111, n101);
	time_start101 = clock();
	shellSort(a1111, n101);
	time_end101 = clock();
	cout << "Shell sort with 3000 elements random: " << (time_end101 - time_start101) / CLK_TCK << " sec" << "\n";
	ofstream fout102;
	fout102.open("ShellSort_Random_3000.txt");
	if(!fout102)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n101; i++)
	{
		shellSort(a1111, n101);
		fout102 << a1111[i] << " ";
	}
	fout102.close();
	double time_start102, time_end102;
	int b1111[10000];
	int n102 = sizeof(b1111) / sizeof(b1111[0]);
	GenerateRandomData(b1111, n102);
	time_start102 = clock();
	shellSort(b1111, n102);
	time_end102 = clock();
	cout << "Shell sort with 10000 elements random: " << (time_end102 - time_start102) / CLK_TCK << " sec" << "\n";
	ofstream fout103;
	fout103.open("ShellSort_Random_10000.txt");
	if(!fout103)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n102; i++)
	{
		shellSort(b1111, n102);
		fout103 << b1111[i] << " ";
	}
	fout103.close();
	double time_start103, time_end103;
	static int c1111[30000];
	static int n103 = sizeof(c1111) / sizeof(c1111[0]);
	GenerateRandomData(c1111, n103);
	time_start103 = clock();
	shellSort(c1111, n103);
	time_end103 = clock();
	cout << "Shell sort with 30000 elements random: " << (time_end103 - time_start103) / CLK_TCK << " sec" << "\n";
	ofstream fout104;
	fout104.open("ShellSort_Random_30000.txt");
	if(!fout104)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n103; i++)
	{
		shellSort(c1111, n103);
		fout104 << c1111[i] << " ";
	}
	fout104.close();
	double time_start104, time_end104;
	static int d1111[100000];
	static int n104 = sizeof(d1111) / sizeof(d1111[0]);
	GenerateRandomData(d1111, n104);
	time_start104 = clock();
	shellSort(d1111, n104);
	time_end104 = clock();
	cout << "Shell sort with 100000 elements random: " << (time_end104 - time_start104) / CLK_TCK << " sec" << "\n";
	ofstream fout105;
	fout105.open("ShellSort_Random_100000.txt");
	if(!fout105)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n104; i++)
	{
		shellSort(d1111, n104);
		fout105 << d1111[i] << " ";
	}
	fout105.close();*/

	/*double time_start105, time_end105;
	int e1111[1000];
	int n105 = sizeof(e1111) / sizeof(e1111[0]);
	GenerateSortedData(e1111, n105);
	time_start105 = clock();
	shellSort(e1111, n105);
	time_end105 = clock();
	cout << "Shell sort with 1000 elements sorted: " << (time_end105 - time_start105) / CLK_TCK << " sec" << "\n";
	ofstream fout106;
	fout106.open("ShellSort_Sorted_1000.txt");
	if(!fout106)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n105; i++)
	{
		shellSort(e1111, n105);
		fout106 << e1111[i] << " ";
	}
	fout106.close();
	double time_start106, time_end106;
	int f1111[3000];
	int n106 = sizeof(f1111) / sizeof(f1111[0]);
	GenerateSortedData(f1111, n106);
	time_start106 = clock();
	shellSort(f1111, n106);
	time_end106 = clock();
	cout << "Shell sort with 3000 elements sorted: " << (time_end106 - time_start106) / CLK_TCK << " sec" << "\n";
	ofstream fout107;
	fout107.open("ShellSort_Sorted_3000.txt");
	if(!fout107)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n106; i++)
	{
		shellSort(f1111, n106);
		fout107 << f1111[i] << " ";
	}
	fout107.close();
	double time_start107, time_end107;
	int g1111[10000];
	int n107 = sizeof(g1111) / sizeof(g1111[0]);
	GenerateSortedData(g1111, n107);
	time_start107 = clock();
	shellSort(g1111, n107);
	time_end107 = clock();
	cout << "Shell sort with 10000 elements sorted: " << (time_end107 - time_start107) / CLK_TCK << " sec" << "\n";
	ofstream fout108;
	fout108.open("ShellSort_Sorted_10000.txt");
	if(!fout108)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n107; i++)
	{
		shellSort(g1111, n107);
		fout108 << g1111[i] << " ";
	}
	fout108.close();
	double time_start108, time_end108;
	static int h1111[30000];
	static int n108 = sizeof(h1111) / sizeof(h1111[0]);
	GenerateSortedData(h1111, n108);
	time_start108 = clock();
	shellSort(h1111, n108);
	time_end108 = clock();
	cout << "Shell sort with 30000 elements sorted: " << (time_end108 - time_start108) / CLK_TCK << " sec" << "\n";
	ofstream fout109;
	fout109.open("ShellSort_Sorted_30000.txt");
	if(!fout109)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n108; i++)
	{
		shellSort(h1111, n108);
		fout109 << h1111[i] << " ";
	}
	fout109.close();
	double time_start109, time_end109;
	static int i1111[100000];
	static int n109 = sizeof(i1111) / sizeof(i1111[0]);
	GenerateSortedData(i1111, n109);
	time_start109 = clock();
	shellSort(i1111, n109);
	time_end109 = clock();
	cout << "Shell sort with 100000 elements sorted: " << (time_end109 - time_start109) / CLK_TCK << " sec" << "\n";
	ofstream fout110;
	fout110.open("ShellSort_Sorted_100000.txt");
	if(!fout110)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n109; i++)
	{
		shellSort(i1111, n109);
		fout110 << i1111[i] << " ";
	}
	fout110.close();*/

	/*double time_start110, time_end110;
	int j1111[1000];
	int n110 = sizeof(j1111) / sizeof(j1111[0]);
	GenerateReverseData(j1111, n110);
	time_start110 = clock();
	shellSort(j1111, n110);
	time_end110 = clock();
	cout << "Shell sort with 1000 elements reversed: " << (time_end110 - time_start110) / CLK_TCK << " sec" << "\n";
	ofstream fout111;
	fout111.open("ShellSort_Reversed_1000.txt");
	if(!fout111)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n110; i++)
	{
		shellSort(j1111, n110);
		fout111 << j1111[i] << " ";
	}
	fout111.close();
	double time_start111, time_end111;
	int k1111[3000];
	int n111 = sizeof(k1111) / sizeof(k1111[0]);
	GenerateReverseData(k1111, n111);
	time_start111 = clock();
	shellSort(k1111, n111);
	time_end111 = clock();
	cout << "Shell sort with 3000 elements reversed: " << (time_end111 - time_start111) / CLK_TCK << " sec" << "\n";
	ofstream fout112;
	fout112.open("ShellSort_Reversed_3000.txt");
	if(!fout112)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n111; i++)
	{
		shellSort(k1111, n111);
		fout112 << k1111[i] << " ";
	}
	fout112.close();
	double time_start112, time_end112;
	int l1111[10000];
	int n112 = sizeof(l1111) / sizeof(l1111[0]);
	GenerateReverseData(l1111, n112);
	time_start112 = clock();
	shellSort(l1111, n112);
	time_end112 = clock();
	cout << "Shell sort with 10000 elements reversed: " << (time_end112 - time_start112) / CLK_TCK << " sec" << "\n";
	ofstream fout113;
	fout113.open("ShellSort_Reversed_10000.txt");
	if(!fout113)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n112; i++)
	{
		shellSort(l1111, n112);
		fout113 << l1111[i] << " ";
	}
	fout113.close();
	double time_start113, time_end113;
	static int m1111[30000];
	static int n113 = sizeof(m1111) / sizeof(m1111[0]);
	GenerateReverseData(m1111, n113);
	time_start113 = clock();
	shellSort(m1111, n113);
	time_end113 = clock();
	cout << "Shell sort with 30000 elements reversed: " << (time_end113 - time_start113) / CLK_TCK << " sec" << "\n";
	ofstream fout114;
	fout114.open("ShellSort_Reversed_30000.txt");
	if(!fout114)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n113; i++)
	{
		shellSort(m1111, n113);
		fout114 << m1111[i] << " ";
	}
	fout114.close();
	double time_start114, time_end114;
	static int n1111[100000];
	static int n114 = sizeof(n1111) / sizeof(n1111[0]);
	GenerateReverseData(n1111, n114);
	time_start114 = clock();
	shellSort(n1111, n114);
	time_end114 = clock();
	cout << "Shell sort with 100000 elements reversed: " << (time_end114 - time_start114) / CLK_TCK << " sec" << "\n";
	ofstream fout115;
	fout115.open("ShellSort_Reversed_100000.txt");
	if(!fout115)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n114; i++)
	{
		shellSort(n1111, n114);
		fout115 << n1111[i] << " ";
	}
	fout115.close();*/

	/*double time_start115, time_end115;
	int o1111[1000];
	int n115 = sizeof(o1111) / sizeof(o1111[0]);
	GenerateNearlySortedData(o1111, n115);
	time_start115 = clock();
	shellSort(o1111, n115);
	time_end115 = clock();
	cout << "Shell sort with 1000 elements nearly sorted: " << (time_end115 - time_start115) / CLK_TCK << " sec" << "\n";
	ofstream fout116;
	fout116.open("ShellSort_NearlySorted_1000.txt");
	if(!fout116)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n115; i++)
	{
		shellSort(o1111, n115);
		fout116 << o1111[i] << " ";
	}
	fout116.close();
	double time_start116, time_end116;
	int p1111[3000];
	int n116 = sizeof(p1111) / sizeof(p1111[0]);
	GenerateNearlySortedData(p1111, n116);
	time_start116 = clock();
	shellSort(p1111, n116);
	time_end116 = clock();
	cout << "Shell sort with 3000 elements nearly sorted: " << (time_end116 - time_start116) / CLK_TCK << " sec" << "\n";
	ofstream fout117;
	fout117.open("ShellSort_NearlySorted_3000.txt");
	if(!fout117)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n116; i++)
	{
		shellSort(p1111, n116);
		fout117 << p1111[i] << " ";
	}
	fout117.close();
	double time_start117, time_end117;
	int q1111[10000];
	int n117 = sizeof(q1111) / sizeof(q1111[0]);
	GenerateNearlySortedData(q1111, n117);
	time_start117 = clock();
	shellSort(q1111, n117);
	time_end117 = clock();
	cout << "Shell sort with 10000 elements nearly sorted: " << (time_end117 - time_start117) / CLK_TCK << " sec" << "\n";
	ofstream fout118;
	fout118.open("ShellSort_NearlySorted_10000.txt");
	if(!fout118)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n117; i++)
	{
		shellSort(q1111, n117);
		fout118 << q1111[i] << " ";
	}
	fout118.close();
	double time_start118, time_end118;
	static int r1111[30000];
	static int n118 = sizeof(r1111) / sizeof(r1111[0]);
	GenerateNearlySortedData(r1111, n118);
	time_start118 = clock();
	shellSort(r1111, n118);
	time_end118 = clock();
	cout << "Shell sort with 30000 elements nearly sorted: " << (time_end118 - time_start118) / CLK_TCK << " sec" << "\n";
	ofstream fout119;
	fout119.open("ShellSort_NearlySorted_30000.txt");
	if(!fout119)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n118; i++)
	{
		shellSort(r1111, n118);
		fout119 << r1111[i] << " ";
	}
	fout119.close();
	double time_start119, time_end119;
	static int s1111[100000];
	static int n119 = sizeof(s1111) / sizeof(s1111[0]);
	GenerateNearlySortedData(s1111, n119);
	time_start119 = clock();
	shellSort(s1111, n119);
	time_end119 = clock();
	cout << "Shell sort with 100000 elements nearly sorted: " << (time_end119 - time_start119) / CLK_TCK << " sec" << "\n";
	ofstream fout120;
	fout120.open("ShellSort_NearlySorted_100000.txt");
	if(!fout120)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n119; i++)
	{
		shellSort(s1111, n119);
		fout120 << s1111[i] << " ";
	}
	fout120.close();*/




	///////////////////////////Heap Sort//////////////////////
	/*double time_start120, time_end120;
	int t1111[1000];
	int n120 = sizeof(t1111) / sizeof(t1111[0]);
	GenerateRandomData(t1111, n120);
	time_start120 = clock();
	build_max_heap(t1111, n120);
	time_end120 = clock();
	cout << "Heap sort with 1000 elements random: " << (time_end120 - time_start120) / CLK_TCK << " sec" << "\n";
	ofstream fout121;
	fout121.open("HeapSort_Random_1000.txt");
	if(!fout121)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n120; i++)
	{
		build_max_heap(t1111, n120);
		fout121 << t1111[i] << " ";
	}
	fout121.close();
	double time_start121, time_end121;
	int u1111[3000];
	int n121 = sizeof(u1111) / sizeof(u1111[0]);
	GenerateRandomData(u1111, n121);
	time_start121 = clock();
	build_max_heap(u1111, n121);
	time_end121 = clock();
	cout << "Heap sort with 3000 elements random: " << (time_end121 - time_start121) / CLK_TCK << " sec" << "\n";
	ofstream fout122;
	fout122.open("HeapSort_Random_3000.txt");
	if(!fout122)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n121; i++)
	{
		build_max_heap(u1111, n121);
		fout122 << u1111[i] << " ";
	}
	fout122.close();
	double time_start122, time_end122;
	int v1111[10000];
	int n122 = sizeof(v1111) / sizeof(v1111[0]);
	GenerateRandomData(v1111, n122);
	time_start122 = clock();
	build_max_heap(v1111, n122);
	time_end122 = clock();
	cout << "Heap sort with 10000 elements random: " << (time_end122 - time_start122) / CLK_TCK << " sec" << "\n";
	ofstream fout123;
	fout123.open("HeapSort_Random_10000.txt");
	if(!fout123)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n122; i++)
	{
		build_max_heap(v1111, n122);
		fout123 << v1111[i] << " ";
	}
	fout123.close();
	double time_start123, time_end123;
	static int w1111[30000];
	static int n123 = sizeof(w1111) / sizeof(w1111[0]);
	GenerateRandomData(w1111, n123);
	time_start123 = clock();
	build_max_heap(w1111, n123);
	time_end123 = clock();
	cout << "Heap sort with 30000 elements random: " << (time_end123 - time_start123) / CLK_TCK << " sec" << "\n";
	ofstream fout124;
	fout124.open("HeapSort_Random_30000.txt");
	if(!fout124)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n123; i++)
	{
		build_max_heap(w1111, n123);
		fout124 << w1111[i] << " ";
	}
	fout124.close();
	double time_start124, time_end124;
	static int x1111[100000];
	static int n124 = sizeof(x1111) / sizeof(x1111[0]);
	GenerateRandomData(x1111, n124);
	time_start124 = clock();
	build_max_heap(x1111, n124);
	time_end124 = clock();
	cout << "Heap sort with 100000 elements random: " << (time_end124 - time_start124) / CLK_TCK << " sec" << "\n";
	ofstream fout125;
	fout125.open("HeapSort_Random_100000.txt");
	if(!fout125)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n124; i++)
	{
		build_max_heap(x1111, n124);
		fout125 << x1111[i] << " ";
	}
	fout125.close();*/

	/*double time_start125, time_end125;
	int y1111[1000];
	int n125 = sizeof(y1111) / sizeof(y1111[0]);
	GenerateSortedData(y1111, n125);
	time_start125 = clock();
	build_max_heap(y1111, n125);
	time_end125 = clock();
	cout << "Heap sort with 1000 elements sorted: " << (time_end125 - time_start125) / CLK_TCK << " sec" << "\n";
	ofstream fout126;
	fout126.open("HeapSort_Sorted_1000.txt");
	if(!fout126)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n125; i++)
	{
		build_max_heap(y1111, n125);
		fout126 << y1111[i] << " ";
	}
	fout126.close();
	double time_start126, time_end126;
	int z1111[3000];
	int n126 = sizeof(z1111) / sizeof(z1111[0]);
	GenerateSortedData(z1111, n126);
	time_start126 = clock();
	build_max_heap(z1111, n126);
	time_end126 = clock();
	cout << "Heap sort with 3000 elements sorted: " << (time_end126 - time_start126) / CLK_TCK << " sec" << "\n";
	ofstream fout127;
	fout127.open("HeapSort_Sorted_3000.txt");
	if(!fout127)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n126; i++)
	{
		build_max_heap(z1111, n126);
		fout127 << z1111[i] << " ";
	}
	fout127.close();
	double time_start127, time_end127;
	int a11111[10000];
	int n127 = sizeof(a11111) / sizeof(a11111[0]);
	GenerateSortedData(a11111, n127);
	time_start127 = clock();
	build_max_heap(a11111, n127);
	time_end127 = clock();
	cout << "Heap sort with 10000 elements sorted: " << (time_end127 - time_start127) / CLK_TCK << " sec" << "\n";
	ofstream fout128;
	fout128.open("HeapSort_Sorted_10000.txt");
	if(!fout128)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n127; i++)
	{
		build_max_heap(a11111, n127);
		fout128 << a11111[i] << " ";
	}
	fout128.close();
	double time_start128, time_end128;
	int b11111[30000];
	int n128 = sizeof(b11111) / sizeof(b11111[0]);
	GenerateSortedData(b11111, n128);
	time_start128 = clock();
	build_max_heap(b11111, n128);
	time_end128 = clock();
	cout << "Heap sort with 30000 elements sorted: " << (time_end128 - time_start128) / CLK_TCK << " sec" << "\n";
	ofstream fout129;
	fout129.open("HeapSort_Sorted_30000.txt");
	if(!fout129)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n128; i++)
	{
		build_max_heap(b11111, n128);
		fout129 << b11111[i] << " ";
	}
	fout129.close();
	double time_start129, time_end129;
	static int c11111[100000];
	static int n129 = sizeof(c11111) / sizeof(c11111[0]);
	GenerateSortedData(c11111, n129);
	time_start129 = clock();
	build_max_heap(c11111, n129);
	time_end129 = clock();
	cout << "Heap sort with 100000 elements sorted: " << (time_end129 - time_start129) / CLK_TCK << " sec" << "\n";
	ofstream fout130;
	fout130.open("HeapSort_Sorted_100000.txt");
	if(!fout130)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n129; i++)
	{
		build_max_heap(c11111, n129);
		fout130 << c11111[i] << " ";
	}
	fout130.close();*/

	/*double time_start130, time_end130;
	int d11111[1000];
	int n130 = sizeof(d11111) / sizeof(d11111[0]);
	GenerateReverseData(d11111, n130);
	time_start130 = clock();
	build_max_heap(d11111, n130);
	time_end130 = clock();
	cout << "Heap sort with 1000 elements reversed: " << (time_end130 - time_start130) / CLK_TCK << " sec" << "\n";
	ofstream fout131;
	fout131.open("HeapSort_Reversed_1000.txt");
	if(!fout131)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n130; i++)
	{
		build_max_heap(d11111, n130);
		fout131 << d11111[i] << " ";
	}
	fout131.close();
	double time_start131, time_end131;
	int e11111[3000];
	int n131 = sizeof(e11111) / sizeof(e11111[0]);
	GenerateReverseData(e11111, n131);
	time_start131 = clock();
	build_max_heap(e11111, n131);
	time_end131 = clock();
	cout << "Heap sort with 3000 elements reversed: " << (time_end131 - time_start131) / CLK_TCK << " sec" << "\n";
	ofstream fout132;
	fout132.open("HeapSort_Reversed_3000.txt");
	if(!fout132)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n131; i++)
	{
		build_max_heap(e11111, n131);
		fout132 << e11111[i] << " ";
	}
	fout132.close();
	double time_start132, time_end132;
	int f11111[10000];
	int n132 = sizeof(f11111) / sizeof(f11111[0]);
	GenerateReverseData(f11111, n132);
	time_start132 = clock();
	build_max_heap(f11111, n132);
	time_end132 = clock();
	cout << "Heap sort with 10000 elements reversed: " << (time_end132 - time_start132) / CLK_TCK << " sec" << "\n";
	ofstream fout133;
	fout133.open("HeapSort_Reversed_10000.txt");
	if(!fout133)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n132; i++)
	{
		build_max_heap(f11111, n132);
		fout133 << f11111[i] << " ";
	}
	fout133.close();
	double time_start133, time_end133;
	static int g11111[30000];
	static int n133 = sizeof(g11111) / sizeof(g11111[0]);
	GenerateReverseData(g11111, n133);
	time_start133 = clock();
	build_max_heap(g11111, n133);
	time_end133 = clock();
	cout << "Heap sort with 30000 elements reversed: " << (time_end133 - time_start133) / CLK_TCK << " sec" << "\n";
	ofstream fout134;
	fout134.open("HeapSort_Reversed_30000.txt");
	if(!fout134)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n133; i++)
	{
		build_max_heap(g11111, n133);
		fout134 << g11111[i] << " ";
	}
	fout134.close();
	double time_start134, time_end134;
	static int h11111[100000];
	static int n134 = sizeof(h11111) / sizeof(h11111[0]);
	GenerateReverseData(h11111, n134);
	time_start134 = clock();
	build_max_heap(h11111, n134);
	time_end134 = clock();
	cout << "Heap sort with 100000 elements reversed: " << (time_end134 - time_start134) / CLK_TCK << " sec" << "\n";
	ofstream fout135;
	fout135.open("HeapSort_Reversed_100000.txt");
	if(!fout135)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n134; i++)
	{
		build_max_heap(h11111, n134);
		fout135 << h11111[i] << " ";
	}
	fout135.close();*/

	/*double time_start135, time_end135;
	int i11111[1000];
	int n135 = sizeof(i11111) / sizeof(i11111[0]);
	GenerateNearlySortedData(i11111, n135);
	time_start135 = clock();
	build_max_heap(i11111, n135);
	time_end135 = clock();
	cout << "Heap sort with 1000 elements nearly sorted: " << (time_end135 - time_start135) / CLK_TCK << " sec" << "\n";
	ofstream fout136;
	fout136.open("HeapSort_NearlySorted_1000.txt");
	if(!fout136)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n135; i++)
	{
		build_max_heap(i11111, n135);
		fout136 << i11111[i] << " ";
	}
	fout136.close();
	double time_start136, time_end136;
	int j11111[3000];
	int n136 = sizeof(j11111) / sizeof(j11111[0]);
	GenerateNearlySortedData(j11111, n136);
	time_start136 = clock();
	build_max_heap(j11111, n136);
	time_end136 = clock();
	cout << "Heap sort with 3000 elements nearly sorted: " << (time_end136 - time_start136) / CLK_TCK << " sec" << "\n";
	ofstream fout137;
	fout137.open("HeapSort_NearlySorted_3000.txt");
	if(!fout137)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n136; i++)
	{
		build_max_heap(j11111, n136);
		fout137 << j11111[i] << " ";
	}
	fout137.close();
	double time_start137, time_end137;
	int k11111[10000];
	int n137 = sizeof(k11111) / sizeof(k11111[0]);
	GenerateNearlySortedData(k11111, n137);
	time_start137 = clock();
	build_max_heap(k11111, n137);
	time_end137 = clock();
	cout << "Heap sort with 10000 elements nearly sorted: " << (time_end137 - time_start137) / CLK_TCK << " sec" << "\n";
	ofstream fout138;
	fout138.open("HeapSort_NearlySorted_10000.txt");
	if(!fout138)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n137; i++)
	{
		build_max_heap(k11111, n137);
		fout138 << k11111[i] << " ";
	}
	fout138.close();
	double time_start138, time_end138;
	static int l11111[30000];
	static int n138 = sizeof(l11111) / sizeof(l11111[0]);
	GenerateNearlySortedData(l11111, n138);
	time_start138 = clock();
	build_max_heap(l11111, n138);
	time_end138 = clock();
	cout << "Heap sort with 30000 elements nearly sorted: " << (time_end138 - time_start138) / CLK_TCK << " sec" << "\n";
	ofstream fout139;
	fout139.open("HeapSort_NearlySorted_30000.txt");
	if(!fout139)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n138; i++)
	{
		build_max_heap(l11111, n138);
		fout139 << l11111[i] << " ";
	}
	fout139.close();
	double time_start139, time_end139;
	static int m11111[100000];
	static int n139 = sizeof(m11111) / sizeof(m11111[0]);
	GenerateNearlySortedData(m11111, n139);
	time_start139 = clock();
	build_max_heap(m11111, n139);
	time_end139 = clock();
	cout << "Heap sort with 100000 elements nearly sorted: " << (time_end139 - time_start139) / CLK_TCK << " sec" << "\n";
	ofstream fout140;
	fout140.open("HeapSort_NearlySorted_100000.txt");
	if(!fout140)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n139; i++)
	{
		build_max_heap(m11111, n139);
		fout140 << m11111[i] << " ";
	}
	fout140.close();*/




	////////////////////////Merge sort///////////////////////////
	/*double time_start140, time_end140;
	int n11111[1000];
	int n140 = sizeof(n11111) / sizeof(n11111[0]);
	GenerateRandomData(n11111, n140);
	time_start140 = clock();
	mergeSort(n11111, 0, n140 - 1);
	time_end140 = clock();
	cout << "Merge sort with 1000 elements random: " << (time_end140 - time_start140) / CLK_TCK << " sec" << "\n";
	ofstream fout141;
	fout141.open("MergeSort_Random_1000.txt");
	if(!fout141)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n140; i++)
	{
		mergeSort(n11111, 0, n140 - 1);
		fout141 << n11111[i] << " ";
	}
	fout141.close();
	double time_start141, time_end141;
	int o11111[3000];
	int n141 = sizeof(o11111) / sizeof(o11111[0]);
	GenerateRandomData(o11111, n141);
	time_start141 = clock();
	mergeSort(o11111, 0, n141 - 1);
	time_end141 = clock();
	cout << "Merge sort with 3000 elements random: " << (time_end141 - time_start141) / CLK_TCK << " sec" << "\n";
	ofstream fout142;
	fout142.open("MergeSort_Random_3000.txt");
	if(!fout142)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n141; i++)
	{
		mergeSort(o11111, 0, n141 - 1);
		fout142 << o11111[i] << " ";
	}
	fout142.close();
	double time_start142, time_end142;
	int p11111[10000];
	int n142 = sizeof(p11111) / sizeof(p11111[0]);
	GenerateRandomData(p11111, n142);
	time_start142 = clock();
	mergeSort(p11111, 0, n142 - 1);
	time_end142 = clock();
	cout << "Merge sort with 10000 elements random: " << (time_end142 - time_start142) / CLK_TCK << " sec" << "\n";
	ofstream fout143;
	fout143.open("MergeSort_Random_10000.txt");
	if(!fout143)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n142; i++)
	{
		mergeSort(p11111, 0, n142 - 1);
		fout143 << p11111[i] << " ";
	}
	fout143.close();
	double time_start143, time_end143;
	static int q11111[30000];
	static int n143 = sizeof(q11111) / sizeof(q11111[0]);
	GenerateRandomData(q11111, n143);
	time_start143 = clock();
	mergeSort(q11111, 0, n143 - 1);
	time_end143 = clock();
	cout << "Merge sort with 30000 elements random: " << (time_end143 - time_start143) / CLK_TCK << " sec" << "\n";
	ofstream fout144;
	fout144.open("MergeSort_Random_30000.txt");
	if(!fout144)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n143; i++)
	{
		mergeSort(q11111, 0, n143 - 1);
		fout144 << q11111[i] << " ";
	}
	fout144.close();
	double time_start144, time_end144;
	static int r11111[100000];
	static int n144 = sizeof(r11111) / sizeof(r11111[0]);
	GenerateRandomData(r11111, n144);
	time_start144 = clock();
	mergeSort(r11111, 0, n144 - 1);
	time_end144 = clock();
	cout << "Merge sort with 100000 elements random: " << (time_end144 - time_start144) / CLK_TCK << " sec" << "\n";
	ofstream fout145;
	fout145.open("MergeSort_Random_100000.txt");
	if(!fout145)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n144; i++)
	{
		mergeSort(r11111, 0, n144 - 1);
		fout145 << r11111[i] << " ";
	}
	fout145.close();*/

	/*double time_start145, time_end145;
	int s11111[1000];
	int n145 = sizeof(s11111) / sizeof(s11111[0]);
	GenerateSortedData(s11111, n145);
	time_start145 = clock();
	mergeSort(s11111, 0, n145 - 1);
	time_end145 = clock();
	cout << "Merge sort with 1000 elements sorted: " << (time_end145 - time_start145) / CLK_TCK << " sec" << "\n";
	ofstream fout146;
	fout146.open("MergeSort_Sorted_1000.txt");
	if(!fout146)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n145; i++)
	{
		mergeSort(s11111, 0, n145 - 1);
		fout146 << s11111[i] << " ";
	}
	fout146.close();
	double time_start146, time_end146;
	int t11111[3000];
	int n146 = sizeof(t11111) / sizeof(t11111[0]);
	GenerateSortedData(t11111, n146);
	time_start146 = clock();
	mergeSort(t11111, 0, n146 - 1);
	time_end146 = clock();
	cout << "Merge sort with 3000 elements sorted: " << (time_end146 - time_start146) / CLK_TCK << " sec" << "\n";
	ofstream fout147;
	fout147.open("MergeSort_Sorted_3000.txt");
	if(!fout147)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n146; i++)
	{
		mergeSort(t11111, 0, n146 - 1);
		fout147 << t11111[i] << " ";
	}
	fout147.close();
	double time_start147, time_end147;
	int u11111[10000];
	int n147 = sizeof(u11111) / sizeof(u11111[0]);
	GenerateSortedData(u11111, n147);
	time_start147 = clock();
	mergeSort(u11111, 0, n147 - 1);
	time_end147 = clock();
	cout << "Merge sort with 10000 elements sorted: " << (time_end147 - time_start147) / CLK_TCK << " sec" << "\n";
	ofstream fout148;
	fout148.open("MergeSort_Sorted_10000.txt");
	if(!fout148)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n147; i++)
	{
		mergeSort(u11111, 0, n147 - 1);
		fout148 << u11111[i] << " ";
	}
	fout148.close();
	double time_start148, time_end148;
	static int v11111[30000];
	static int n148 = sizeof(v11111) / sizeof(v11111[0]);
	GenerateSortedData(v11111, n148);
	time_start148 = clock();
	mergeSort(v11111, 0, n148 - 1);
	time_end148 = clock();
	cout << "Merge sort with 30000 elements sorted: " << (time_end148 - time_start148) / CLK_TCK << " sec" << "\n";
	ofstream fout149;
	fout149.open("MergeSort_Sorted_30000.txt");
	if(!fout149)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n148; i++)
	{
		mergeSort(v11111, 0, n148 - 1);
		fout149 << v11111[i] << " ";
	}
	fout149.close();
	double time_start149, time_end149;
	static int w11111[100000];
	static int n149 = sizeof(w11111) / sizeof(w11111[0]);
	GenerateSortedData(w11111, n149);
	time_start149 = clock();
	mergeSort(w11111, 0, n149 - 1);
	time_end149 = clock();
	cout << "Merge sort with 100000 elements sorted: " << (time_end149 - time_start149) / CLK_TCK << " sec" << "\n";
	ofstream fout150;
	fout150.open("MergeSort_Sorted_100000.txt");
	if(!fout150)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n149; i++)
	{
		mergeSort(w11111, 0, n149 - 1);
		fout150 << w11111[i] << " ";
	}
	fout150.close();*/

	/*double time_start150, time_end150;
	int x11111[1000];
	int n150 = sizeof(x11111) / sizeof(x11111[0]);
	GenerateReverseData(x11111, n150);
	time_start150 = clock();
	mergeSort(x11111, 0, n150 - 1);
	time_end150 = clock();
	cout << "Merge sort with 1000 elements reversed: " << (time_end150 - time_start150) / CLK_TCK << " sec" << "\n";
	ofstream fout151;
	fout151.open("MergeSort_Reversed_1000.txt");
	if(!fout151)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n150; i++)
	{
		mergeSort(x11111, 0, n150 - 1);
		fout151 << x11111[i] << " ";
	}
	fout151.close();
	double time_start151, time_end151;
	int y11111[3000];
	int n151 = sizeof(y11111) / sizeof(y11111[0]);
	GenerateReverseData(y11111, n151);
	time_start151 = clock();
	mergeSort(y11111, 0, n151 - 1);
	time_end151 = clock();
	cout << "Merge sort with 3000 elements reversed: " << (time_end151 - time_start151) / CLK_TCK << " sec" << "\n";
	ofstream fout152;
	fout152.open("MergeSort_Reversed_3000.txt");
	if(!fout152)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n151; i++)
	{
		mergeSort(y11111, 0, n151 - 1);
		fout152 << y11111[i] << " ";
	}
	fout152.close();
	double time_start152, time_end152;
	int z11111[10000];
	int n152 = sizeof(z11111) / sizeof(z11111[0]);
	GenerateReverseData(z11111, n152);
	time_start152 = clock();
	mergeSort(z11111, 0, n152 - 1);
	time_end152 = clock();
	cout << "Merge sort with 10000 elements reversed: " << (time_end152 - time_start152) / CLK_TCK << " sec" << "\n";
	ofstream fout153;
	fout153.open("MergeSort_Reversed_10000.txt");
	if(!fout153)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n152; i++)
	{
		mergeSort(z11111, 0, n152 - 1);
		fout153 << z11111[i] << " ";
	}
	fout153.close();
	double time_start153, time_end153;
	static int a111111[30000];
	static int n153 = sizeof(a111111) / sizeof(a111111[0]);
	GenerateReverseData(a111111, n153);
	time_start153 = clock();
	mergeSort(a111111, 0, n153 - 1);
	time_end153 = clock();
	cout << "Merge sort with 30000 elements reversed: " << (time_end153 - time_start153) / CLK_TCK << " sec" << "\n";
	ofstream fout154;
	fout154.open("MergeSort_Reversed_30000.txt");
	if(!fout154)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n153; i++)
	{
		mergeSort(a111111, 0, n153 - 1);
		fout154 << a111111[i] << " ";
	}
	fout154.close();
	double time_start154, time_end154;
	static int b111111[100000];
	static int n154 = sizeof(b111111) / sizeof(b111111[0]);
	GenerateReverseData(b111111, n154);
	time_start154 = clock();
	mergeSort(b111111, 0, n154 - 1);
	time_end154 = clock();
	cout << "Merge sort with 100000 elements reversed: " << (time_end154 - time_start154) / CLK_TCK << " sec" << "\n";
	ofstream fout155;
	fout155.open("MergeSort_Reversed_100000.txt");
	if(!fout155)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n154; i++)
	{
		mergeSort(b111111, 0, n154 - 1);
		fout155 << b111111[i] << " ";
	}
	fout155.close();*/

	/*double time_start155, time_end155;
	int c111111[1000];
	int n155 = sizeof(c111111) / sizeof(c111111[0]);
	GenerateNearlySortedData(c111111, n155);
	time_start155 = clock();
	mergeSort(c111111, 0, n155 - 1);
	time_end155 = clock();
	cout << "Merge sort with 1000 elements nearly sorted: " << (time_end155 - time_start155) / CLK_TCK << " sec" << "\n";
	ofstream fout156;
	fout156.open("MergeSort_NearlySorted_1000.txt");
	if(!fout156)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n155; i++)
	{
		mergeSort(c111111, 0, n155 - 1);
		fout156 << c111111[i] << " ";
	}
	fout156.close();
	double time_start156, time_end156;
	int d111111[3000];
	int n156 = sizeof(d111111) / sizeof(d111111[0]);
	GenerateNearlySortedData(d111111, n156);
	time_start156 = clock();
	mergeSort(d111111, 0, n156 - 1);
	time_end156 = clock();
	cout << "Merge sort with 3000 elements nearly sorted: " << (time_end156 - time_start156) / CLK_TCK << " sec" << "\n";
	ofstream fout157;
	fout157.open("MergeSort_NearlySorted_3000.txt");
	if(!fout157)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n156; i++)
	{
		mergeSort(d111111, 0, n156 - 1);
		fout157 << d111111[i] << " ";
	}
	fout157.close();
	double time_start157, time_end157;
	int e111111[10000];
	int n157 = sizeof(e111111) / sizeof(e111111[0]);
	GenerateNearlySortedData(e111111, n157);
	time_start157 = clock();
	mergeSort(e111111, 0, n157 - 1);
	time_end157 = clock();
	cout << "Merge sort with 10000 elements nearly sorted: " << (time_end157 - time_start157) / CLK_TCK << " sec" << "\n";
	ofstream fout158;
	fout158.open("MergeSort_NearlySorted_10000.txt");
	if(!fout158)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n157; i++)
	{
		mergeSort(e111111, 0, n157 - 1);
		fout158 << e111111[i] << " ";
	}
	fout158.close();
	double time_start158, time_end158;
	static int f111111[30000];
	static int n158 = sizeof(f111111) / sizeof(f111111[0]);
	GenerateNearlySortedData(f111111, n158);
	time_start158 = clock();
	mergeSort(f111111, 0, n158 - 1);
	time_end158 = clock();
	cout << "Merge sort with 30000 elements nearly sorted: " << (time_end158 - time_start158) / CLK_TCK << " sec" << "\n";
	ofstream fout159;
	fout159.open("MergeSort_NearlySorted_30000.txt");
	if(!fout159)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n158; i++)
	{
		mergeSort(f111111, 0, n158 - 1);
		fout159 << f111111[i] << " ";
	}
	fout159.close();
	double time_start159, time_end159;
	static int g111111[100000];
	static int n159 = sizeof(g111111) / sizeof(g111111[0]);
	GenerateNearlySortedData(g111111, n159);
	time_start159 = clock();
	mergeSort(g111111, 0, n159 - 1);
	time_end159 = clock();
	cout << "Merge sort with 100000 elements nearly sorted: " << (time_end159 - time_start159) / CLK_TCK << " sec" << "\n";
	ofstream fout160;
	fout160.open("MergeSort_NearlySorted_100000.txt");
	if(!fout160)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n159; i++)
	{
		mergeSort(g111111, 0, n159 - 1);
		fout160 << g111111[i] << " ";
	}
	fout160.close();*/




	///////////////////////Quick Sort//////////////////////
	/*double time_start160, time_end160;
	int h111111[1000];
	int n160 = sizeof(h111111) / sizeof(h111111[0]);
	GenerateRandomData(h111111, n160);
	time_start160 = clock();
	quickSort(h111111, 0, n160 - 1);
	time_end160 = clock();
	cout << "Quick sort with 1000 elements random: " << (time_end160 - time_start160) / CLK_TCK << " sec" << "\n";
	ofstream fout161;
	fout161.open("QuickSort_Random_1000.txt");
	if(!fout161)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n160; i++)
	{
		quickSort(h111111, 0, n160 - 1);
		fout161 << h111111[i] << " ";
	}
	fout161.close();
	double time_start161, time_end161;
	int i111111[3000];
	int n161 = sizeof(i111111) / sizeof(i111111[0]);
	GenerateRandomData(i111111, n161);
	time_start161 = clock();
	quickSort(i111111, 0, n161 - 1);
	time_end161 = clock();
	cout << "Quick sort with 3000 elements random: " << (time_end161 - time_start161) / CLK_TCK << " sec" << "\n";
	ofstream fout162;
	fout162.open("QuickSort_Random_3000.txt");
	if(!fout162)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n161; i++)
	{
		quickSort(i111111, 0, n161 - 1);
		fout162 << i111111[i] << " ";
	}
	fout162.close();
	double time_start162, time_end162;
	int j111111[10000];
	int n162 = sizeof(j111111) / sizeof(j111111[0]);
	GenerateRandomData(j111111, n162);
	time_start162 = clock();
	quickSort(j111111, 0, n162 - 1);
	time_end162 = clock();
	cout << "Quick sort with 10000 elements random: " << (time_end162 - time_start162) / CLK_TCK << " sec" << "\n";
	ofstream fout163;
	fout163.open("QuickSort_Random_10000.txt");
	if(!fout163)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n162; i++)
	{
		quickSort(j111111, 0, n162 - 1);
		fout163 << j111111[i] << " ";
	}
	fout163.close();
	double time_start163, time_end163;
	static int k111111[30000];
	static int n163 = sizeof(k111111) / sizeof(k111111[0]);
	GenerateRandomData(k111111, n163);
	time_start163 = clock();
	quickSort(k111111, 0, n163 - 1);
	time_end163 = clock();
	cout << "Quick sort with 30000 elements random: " << (time_end163 - time_start163) / CLK_TCK << " sec" << "\n";
	ofstream fout164;
	fout164.open("QuickSort_Random_30000.txt");
	if(!fout164)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n163; i++)
	{
		quickSort(k111111, 0, n163 - 1);
		fout164 << k111111[i] << " ";
	}
	fout164.close();
	double time_start164, time_end164;
	static int l111111[100000];
	static int n164 = sizeof(l111111) / sizeof(l111111[0]);
	GenerateRandomData(l111111, n164);
	time_start164 = clock();
	quickSort(l111111, 0, n164 - 1);
	time_end164 = clock();
	cout << "Quick sort with 100000 elements random: " << (time_end164 - time_start164) / CLK_TCK << " sec" << "\n";
	ofstream fout165;
	fout165.open("QuickSort_Random_100000.txt");
	if(!fout165)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n164; i++)
	{
		quickSort(l111111, 0, n164 - 1);
		fout165 << l111111[i] << " ";
	}
	fout165.close();*/

	/*double time_start165, time_end165;
	int m111111[1000];
	int n165 = sizeof(m111111) / sizeof(m111111[0]);
	GenerateSortedData(m111111, n165);
	time_start165 = clock();
	quickSort(m111111, 0, n165 - 1);
	time_end165 = clock();
	cout << "Quick sort with 1000 elements sorted: " << (time_end165 - time_start165) / CLK_TCK << " sec" << "\n";
	ofstream fout166;
	fout166.open("QuickSort_Sorted_1000.txt");
	if(!fout166)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n165; i++)
	{
		quickSort(m111111, 0, n165 - 1);
		fout166 << m111111[i] << " ";
	}
	fout166.close();
	double time_start166, time_end166;
	int n111111[3000];
	int n166 = sizeof(n111111) / sizeof(n111111[0]);
	GenerateSortedData(n111111, n166);
	time_start166 = clock();
	quickSort(n111111, 0, n166 - 1);
	time_end166 = clock();
	cout << "Quick sort with 3000 elements sorted: " << (time_end166 - time_start166) / CLK_TCK << " sec" << "\n";
	ofstream fout167;
	fout167.open("QuickSort_Sorted_3000.txt");
	if(!fout167)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n166; i++)
	{
		quickSort(n111111, 0, n166 - 1);
		fout167 << n111111[i] << " ";
	}
	fout167.close();
	double time_start167, time_end167;
	int o111111[10000];
	int n167 = sizeof(o111111) / sizeof(o111111[0]);
	GenerateSortedData(o111111, n167);
	time_start167 = clock();
	quickSort(o111111, 0, n167 - 1);
	time_end167 = clock();
	cout << "Quick sort with 10000 elements sorted: " << (time_end167 - time_start167) / CLK_TCK << " sec" << "\n";
	ofstream fout168;
	fout168.open("QuickSort_Sorted_10000.txt");
	if(!fout168)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n167; i++)
	{
		quickSort(o111111, 0, n167 - 1);
		fout168 << o111111[i] << " ";
	}
	fout168.close();
	double time_start168, time_end168;
	static int p111111[30000];
	static int n168 = sizeof(p111111) / sizeof(p111111[0]);
	GenerateSortedData(p111111, n168);
	time_start168 = clock();
	quickSort(p111111, 0, n168 - 1);
	time_end168 = clock();
	cout << "Quick sort with 30000 elements sorted: " << (time_end168 - time_start168) / CLK_TCK << " sec" << "\n";
	ofstream fout169;
	fout169.open("QuickSort_Sorted_30000.txt");
	if(!fout169)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n168; i++)
	{
		quickSort(p111111, 0, n168 - 1);
		fout169 << p111111[i] << " ";
	}
	fout169.close();
	double time_start169, time_end169;
	static int q111111[100000];
	static int n169 = sizeof(q111111) / sizeof(q111111[0]);
	GenerateSortedData(q111111, n169);
	time_start169 = clock();
	quickSort(q111111, 0, n169 - 1);
	time_end169 = clock();
	cout << "Quick sort with 100000 elements sorted: " << (time_end169 - time_start169) / CLK_TCK << " sec" << "\n";
	ofstream fout170;
	fout170.open("QuickSort_Sorted_100000.txt");
	if(!fout170)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n168; i++)
	{
		quickSort(q111111, 0, n169 - 1);
		fout170 << q111111[i] << " ";
	}
	fout170.close();*/

	/*double time_start170, time_end170;
	int r111111[1000];
	int n170 = sizeof(r111111) / sizeof(r111111[0]);
	GenerateReverseData(r111111, n170);
	time_start170 = clock();
	quickSort(r111111, 0, n170 - 1);
	time_end170 = clock();
	cout << "Quick sort with 1000 elements reversed: " << (time_end170 - time_start170) / CLK_TCK << " sec" << "\n";
	ofstream fout171;
	fout171.open("QuickSort_Reversed_1000.txt");
	if(!fout171)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n170; i++)
	{
		quickSort(r111111, 0, n170 - 1);
		fout171 << r111111[i] << " ";
	}
	fout171.close();
	double time_start171, time_end171;
	int s111111[3000];
	int n171 = sizeof(s111111) / sizeof(s111111[0]);
	GenerateReverseData(s111111, n171);
	time_start171 = clock();
	quickSort(s111111, 0, n171 - 1);
	time_end171 = clock();
	cout << "Quick sort with 3000 elements reversed: " << (time_end171 - time_start171) / CLK_TCK << " sec" << "\n";
	ofstream fout172;
	fout172.open("QuickSort_Reversed_3000.txt");
	if(!fout172)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n171; i++)
	{
		quickSort(s111111, 0, n171 - 1);
		fout172 << s111111[i] << " ";
	}
	fout172.close();
	double time_start172, time_end172;
	int t111111[10000];
	int n172 = sizeof(t111111) / sizeof(t111111[0]);
	GenerateReverseData(t111111, n172);
	time_start172 = clock();
	quickSort(t111111, 0, n172 - 1);
	time_end172 = clock();
	cout << "Quick sort with 10000 elements reversed: " << (time_end172 - time_start172) / CLK_TCK << " sec" << "\n";
	ofstream fout173;
	fout173.open("QuickSort_Reversed_10000.txt");
	if(!fout173)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n172; i++)
	{
		quickSort(t111111, 0, n172 - 1);
		fout173 << t111111[i] << " ";
	}
	fout173.close();
	double time_start173, time_end173;
	static int u111111[30000];
	static int n173 = sizeof(u111111) / sizeof(u111111[0]);
	GenerateReverseData(u111111, n173);
	time_start173 = clock();
	quickSort(u111111, 0, n173 - 1);
	time_end173 = clock();
	cout << "Quick sort with 30000 elements reversed: " << (time_end173 - time_start173) / CLK_TCK << " sec" << "\n";
	ofstream fout174;
	fout174.open("QuickSort_Reversed_30000.txt");
	if(!fout174)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n173; i++)
	{
		quickSort(u111111, 0, n173 - 1);
		fout174 << u111111[i] << " ";
	}
	fout174.close();
	double time_start174, time_end174;
	int v111111[100000];
	int n174 = sizeof(v111111) / sizeof(v111111[0]);
	GenerateReverseData(v111111, n174);
	time_start174 = clock();
	quickSort(v111111, 0, n174 - 1);
	time_end174 = clock();
	cout << "Quick sort with 100000 elements reversed: " << (time_end174 - time_start174) / CLK_TCK << " sec" << "\n";
	ofstream fout175;
	fout175.open("QuickSort_Reversed_100000.txt");
	if(!fout175)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n174; i++)
	{
		quickSort(v111111, 0, n174 - 1);
		fout175 << v111111[i] << " ";
	}
	fout175.close();*/

	/*double time_start175, time_end175;
	int w111111[1000];
	int n175 = sizeof(w111111) / sizeof(w111111[0]);
	GenerateNearlySortedData(w111111, n175);
	time_start175 = clock();
	quickSort(w111111, 0, n175 - 1);
	time_end175 = clock();
	cout << "Quick sort with 1000 elements nearly sorted: " << (time_end175 - time_start175) / CLK_TCK << " sec" << "\n";
	ofstream fout176;
	fout176.open("QuickSort_NearlySorted_1000.txt");
	if(!fout176)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n175; i++)
	{
		quickSort(w111111, 0, n175 - 1);
		fout176 << w111111[i] << " ";
	}
	fout176.close();
	double time_start176, time_end176;
	int x111111[3000];
	int n176 = sizeof(x111111) / sizeof(x111111[0]);
	GenerateNearlySortedData(x111111, n176);
	time_start176 = clock();
	quickSort(x111111, 0, n176 - 1);
	time_end176 = clock();
	cout << "Quick sort with 3000 elements nearly sorted: " << (time_end176 - time_start176) / CLK_TCK << " sec" << "\n";
	ofstream fout177;
	fout177.open("QuickSort_NearlySorted_3000.txt");
	if(!fout177)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n176; i++)
	{
		quickSort(x111111, 0, n176 - 1);
		fout177 << x111111[i] << " ";
	}
	fout177.close();
	double time_start177, time_end177;
	int y111111[10000];
	int n177 = sizeof(y111111) / sizeof(y111111[0]);
	GenerateNearlySortedData(y111111, n177);
	time_start177 = clock();
	quickSort(y111111, 0, n177 - 1);
	time_end177 = clock();
	cout << "Quick sort with 10000 elements nearly sorted: " << (time_end177 - time_start177) / CLK_TCK << " sec" << "\n";
	ofstream fout178;
	fout178.open("QuickSort_NearlySorted_10000.txt");
	if(!fout178)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n177; i++)
	{
		quickSort(y111111, 0, n177 - 1);
		fout178 << y111111[i] << " ";
	}
	fout178.close();
	double time_start178, time_end178;
	static int z111111[30000];
	static int n178 = sizeof(z111111) / sizeof(z111111[0]);
	GenerateNearlySortedData(z111111, n178);
	time_start178 = clock();
	quickSort(z111111, 0, n178 - 1);
	time_end178 = clock();
	cout << "Quick sort with 30000 elements nearly sorted: " << (time_end178 - time_start178) / CLK_TCK << " sec" << "\n";
	ofstream fout179;
	fout179.open("QuickSort_NearlySorted_30000.txt");
	if(!fout179)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n178; i++)
	{
		quickSort(z111111, 0, n178 - 1);
		fout179 << z111111[i] << " ";
	}
	fout179.close();
	double time_start179, time_end179;
	static int a1111111[100000];
	static int n179 = sizeof(a1111111) / sizeof(a1111111[0]);
	GenerateNearlySortedData(a1111111, n179);
	time_start179 = clock();
	quickSort(a1111111, 0, n179 - 1);
	time_end179 = clock();
	cout << "Quick sort with 100000 elements nearly sorted: " << (time_end179 - time_start179) / CLK_TCK << " sec" << "\n";
	ofstream fout180;
	fout180.open("QuickSort_NearlySorted_100000.txt");
	if(!fout180)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n179; i++)
	{
		quickSort(a1111111, 0, n179 - 1);
		fout180 << a1111111[i] << " ";
	}
	fout180.close();*/




	//////////////////////Counting Sort///////////////////////
	/*double time_start180, time_end180;
	int b1111111[1000];
	int n180 = sizeof(b1111111) / sizeof(b1111111[0]);
	GenerateRandomData(b1111111, n180);
	time_start180 = clock();
	countingSort(b1111111, n180);
	time_end180 = clock();
	cout << "Counting sort with 1000 elements random: " << (time_end180 - time_start180) / CLK_TCK << " sec" << "\n";
	ofstream fout181;
	fout181.open("CountingSort_Random_1000.txt");
	if(!fout181)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n180; i++)
	{
		countingSort(b1111111, n180);
		fout181 << b1111111[i] << " ";
	}
	fout181.close();
	double time_start181, time_end181;
	int c1111111[3000];
	int n181 = sizeof(c1111111) / sizeof(c1111111[0]);
	GenerateRandomData(c1111111, n181);
	time_start181 = clock();
	countingSort(c1111111, n181);
	time_end181 = clock();
	cout << "Counting sort with 3000 elements random: " << (time_end181 - time_start181) / CLK_TCK << " sec" << "\n";
	ofstream fout182;
	fout182.open("CountingSort_Random_3000.txt");
	if(!fout182)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n181; i++)
	{
		countingSort(c1111111, n181);
		fout182 << c1111111[i] << " ";
	}
	fout182.close();
	double time_start182, time_end182;
	int d1111111[10000];
	int n182 = sizeof(d1111111) / sizeof(d1111111[0]);
	GenerateRandomData(d1111111, n182);
	time_start182 = clock();
	countingSort(d1111111, n182);
	time_end182 = clock();
	cout << "Counting sort with 10000 elements random: " << (time_end182 - time_start182) / CLK_TCK << " sec" << "\n";
	ofstream fout183;
	fout183.open("CountingSort_Random_10000.txt");
	if(!fout183)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n182; i++)
	{
		countingSort(d1111111, n182);
		fout183 << d1111111[i] << " ";
	}
	fout183.close();
	double time_start183, time_end183;
	static int e1111111[30000];
	static int n183 = sizeof(e1111111) / sizeof(e1111111[0]);
	GenerateRandomData(e1111111, n183);
	time_start183 = clock();
	countingSort(e1111111, n183);
	time_end183 = clock();
	cout << "Counting sort with 30000 elements random: " << (time_end183 - time_start183) / CLK_TCK << " sec" << "\n";
	ofstream fout184;
	fout184.open("CountingSort_Random_30000.txt");
	if(!fout184)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n183; i++)
	{
		countingSort(e1111111, n183);
		fout184 << e1111111[i] << " ";
	}
	fout184.close();
	double time_start184, time_end184;
	static int f1111111[100000];
	static int n184 = sizeof(f1111111) / sizeof(f1111111[0]);
	GenerateRandomData(f1111111, n184);
	time_start184 = clock();
	countingSort(f1111111, n184);
	time_end184 = clock();
	cout << "Counting sort with 100000 elements random: " << (time_end184 - time_start184) / CLK_TCK << " sec" << "\n";
	ofstream fout185;
	fout185.open("CountingSort_Random_100000.txt");
	if(!fout185)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n184; i++)
	{
		countingSort(f1111111, n184);
		fout185 << f1111111[i] << " ";
	}
	fout185.close();*/

	/*double time_start185, time_end185;
	int g1111111[1000];
	int n185 = sizeof(g1111111) / sizeof(g1111111[0]);
	GenerateSortedData(g1111111, n185);
	time_start185 = clock();
	countingSort(g1111111, n185);
	time_end185 = clock();
	cout << "Counting sort with 1000 elements sorted: " << (time_end185 - time_start185) / CLK_TCK << " sec" << "\n";
	ofstream fout186;
	fout186.open("CountingSort_Sorted_1000.txt");
	if(!fout186)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n185; i++)
	{
		countingSort(g1111111, n185);
		fout186 << g1111111[i] << " ";
	}
	fout186.close();
	double time_start186, time_end186;
	int h1111111[3000];
	int n186 = sizeof(h1111111) / sizeof(h1111111[0]);
	GenerateSortedData(h1111111, n186);
	time_start186 = clock();
	countingSort(h1111111, n186);
	time_end186 = clock();
	cout << "Counting sort with 3000 elements sorted: " << (time_end186 - time_start186) / CLK_TCK << " sec" << "\n";
	ofstream fout187;
	fout187.open("CountingSort_Sorted_3000.txt");
	if(!fout187)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n186; i++)
	{
		countingSort(h1111111, n186);
		fout187 << h1111111[i] << " ";
	}
	fout187.close();
	double time_start187, time_end187;
	int i1111111[10000];
	int n187 = sizeof(i1111111) / sizeof(i1111111[0]);
	GenerateSortedData(i1111111, n187);
	time_start187 = clock();
	countingSort(i1111111, n187);
	time_end187 = clock();
	cout << "Counting sort with 10000 elements sorted: " << (time_end187 - time_start187) / CLK_TCK << " sec" << "\n";
	ofstream fout188;
	fout188.open("CountingSort_Sorted_10000.txt");
	if(!fout188)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n187; i++)
	{
		countingSort(i1111111, n187);
		fout188 << i1111111[i] << " ";
	}
	fout188.close();
	double time_start188, time_end188;
	static int j1111111[30000];
	static int n188 = sizeof(j1111111) / sizeof(j1111111[0]);
	GenerateSortedData(j1111111, n188);
	time_start188 = clock();
	countingSort(j1111111, n188);
	time_end188 = clock();
	cout << "Counting sort with 30000 elements sorted: " << (time_end188 - time_start188) / CLK_TCK << " sec" << "\n";
	ofstream fout189;
	fout189.open("CountingSort_Sorted_30000.txt");
	if(!fout189)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n188; i++)
	{
		countingSort(j1111111, n188);
		fout189 << j1111111[i] << " ";
	}
	fout189.close();
	double time_start189, time_end189;
	static int k1111111[100000];
	static int n189 = sizeof(k1111111) / sizeof(k1111111[0]);
	GenerateSortedData(k1111111, n189);
	time_start189 = clock();
	countingSort(k1111111, n189);
	time_end189 = clock();
	cout << "Counting sort with 100000 elements sorted: " << (time_end189 - time_start189) / CLK_TCK << " sec" << "\n";
	ofstream fout190;
	fout190.open("CountingSort_Sorted_100000.txt");
	if(!fout190)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n189; i++)
	{
		countingSort(k1111111, n189);
		fout190 << k1111111[i] << " ";
	}
	fout190.close();*/

	/*double time_start190, time_end190;
	int l1111111[1000];
	int n190 = sizeof(l1111111) / sizeof(l1111111[0]);
	GenerateReverseData(l1111111, n190);
	time_start190 = clock();
	countingSort(l1111111, n190);
	time_end190 = clock();
	cout << "Counting sort with 1000 elements reversed: " << (time_end190 - time_start190) / CLK_TCK << " sec" << "\n";
	ofstream fout191;
	fout191.open("CountingSort_Reversed_1000.txt");
	if(!fout191)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n190; i++)
	{
		countingSort(l1111111, n190);
		fout191 << l1111111[i] << " ";
	}
	fout191.close();
	double time_start191, time_end191;
	int m1111111[3000];
	int n191 = sizeof(m1111111) / sizeof(m1111111[0]);
	GenerateReverseData(m1111111, n191);
	time_start191 = clock();
	countingSort(m1111111, n191);
	time_end191 = clock();
	cout << "Counting sort with 3000 elements reversed: " << (time_end191 - time_start191) / CLK_TCK << " sec" << "\n";
	ofstream fout192;
	fout192.open("CountingSort_Reversed_3000.txt");
	if(!fout192)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n191; i++)
	{
		countingSort(m1111111, n191);
		fout192 << m1111111[i] << " ";
	}
	fout192.close();
	double time_start192, time_end192;
	int n1111111[10000];
	int n192 = sizeof(n1111111) / sizeof(n1111111[0]);
	GenerateReverseData(n1111111, n192);
	time_start192 = clock();
	countingSort(n1111111, n192);
	time_end192 = clock();
	cout << "Counting sort with 10000 elements reversed: " << (time_end192 - time_start192) / CLK_TCK << " sec" << "\n";
	ofstream fout193;
	fout193.open("CountingSort_Reversed_10000.txt");
	if(!fout193)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n192; i++)
	{
		countingSort(n1111111, n192);
		fout193 << n1111111[i] << " ";
	}
	fout193.close();
	double time_start193, time_end193;
	static int o1111111[30000];
	static int n193 = sizeof(o1111111) / sizeof(o1111111[0]);
	GenerateReverseData(o1111111, n193);
	time_start193 = clock();
	countingSort(o1111111, n193);
	time_end193 = clock();
	cout << "Counting sort with 30000 elements reversed: " << (time_end193 - time_start193) / CLK_TCK << " sec" << "\n";
	ofstream fout194;
	fout194.open("CountingSort_Reversed_30000.txt");
	if(!fout194)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n193; i++)
	{
		countingSort(o1111111, n193);
		fout194 << o1111111[i] << " ";
	}
	fout194.close();
	double time_start194, time_end194;
	static int p1111111[100000];
	static int n194 = sizeof(p1111111) / sizeof(p1111111[0]);
	GenerateReverseData(p1111111, n194);
	time_start194 = clock();
	countingSort(p1111111, n194);
	time_end194 = clock();
	cout << "Counting sort with 100000 elements reversed: " << (time_end194 - time_start194) / CLK_TCK << " sec" << "\n";
	ofstream fout195;
	fout195.open("CountingSort_Reversed_100000.txt");
	if(!fout195)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n194; i++)
	{
		countingSort(p1111111, n194);
		fout195 << p1111111[i] << " ";
	}
	fout195.close();*/

	/*double time_start195, time_end195;
	int q1111111[1000];
	int n195 = sizeof(q1111111) / sizeof(q1111111[0]);
	GenerateNearlySortedData(q1111111, n195);
	time_start195 = clock();
	countingSort(q1111111, n195);
	time_end195 = clock();
	cout << "Counting sort with 1000 elements nearly sorted: " << (time_end195 - time_start195) / CLK_TCK << " sec" << "\n";
	ofstream fout196;
	fout196.open("CountingSort_NearlySorted_1000.txt");
	if(!fout196)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n195; i++)
	{
		countingSort(q1111111, n195);
		fout196 << q1111111[i] << " ";
	}
	fout196.close();
	double time_start196, time_end196;
	int r1111111[3000];
	int n196 = sizeof(r1111111) / sizeof(r1111111[0]);
	GenerateNearlySortedData(r1111111, n196);
	time_start196 = clock();
	countingSort(r1111111, n196);
	time_end196 = clock();
	cout << "Counting sort with 3000 elements nearly sorted: " << (time_end196 - time_start196) / CLK_TCK << " sec" << "\n";
	ofstream fout197;
	fout197.open("CountingSort_NearlySorted_3000.txt");
	if(!fout197)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n196; i++)
	{
		countingSort(r1111111, n196);
		fout197 << r1111111[i] << " ";
	}
	fout197.close();
	double time_start197, time_end197;
	int s1111111[10000];
	int n197 = sizeof(s1111111) / sizeof(s1111111[0]);
	GenerateNearlySortedData(s1111111, n197);
	time_start197 = clock();
	countingSort(s1111111, n197);
	time_end197 = clock();
	cout << "Counting sort with 10000 elements nearly sorted: " << (time_end197 - time_start197) / CLK_TCK << " sec" << "\n";
	ofstream fout198;
	fout198.open("CountingSort_NearlySorted_10000.txt");
	if(!fout198)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n197; i++)
	{
		countingSort(s1111111, n197);
		fout198 << s1111111[i] << " ";
	}
	fout198.close();
	double time_start198, time_end198;
	static int t1111111[30000];
	static int n198 = sizeof(t1111111) / sizeof(t1111111[0]);
	GenerateNearlySortedData(t1111111, n198);
	time_start198 = clock();
	countingSort(t1111111, n198);
	time_end198 = clock();
	cout << "Counting sort with 30000 elements nearly sorted: " << (time_end198 - time_start198) / CLK_TCK << " sec" << "\n";
	ofstream fout199;
	fout199.open("CountingSort_NearlySorted_30000.txt");
	if(!fout199)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n198; i++)
	{
		countingSort(t1111111, n198);
		fout199 << t1111111[i] << " ";
	}
	fout199.close();
	double time_start199, time_end199;
	static int u1111111[100000];
	static int n199 = sizeof(u1111111) / sizeof(u1111111[0]);
	GenerateNearlySortedData(u1111111, n199);
	time_start199 = clock();
	countingSort(u1111111, n199);
	time_end199 = clock();
	cout << "Counting sort with 100000 elements nearly sorted: " << (time_end199 - time_start199) / CLK_TCK << " sec" << "\n";
	ofstream fout200;
	fout200.open("CountingSort_NearlySorted_100000.txt");
	if(!fout200)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n199; i++)
	{
		countingSort(u1111111, n199);
		fout200 << u1111111[i] << " ";
	}
	fout200.close();*/




	///////////////////////////Radix sort/////////////////////////
	/*double time_start200, time_end200;
	int v1111111[1000];
	int n200 = sizeof(v1111111) / sizeof(v1111111[0]);
	GenerateRandomData(v1111111, n200);
	time_start200 = clock();
	radixSort(v1111111, n200);
	time_end200 = clock();
	cout << "Radix sort with 1000 elements random: " << (time_end200 - time_start200) / CLK_TCK << " sec" << "\n";
	ofstream fout201;
	fout201.open("RadixSort_Random_1000.txt");
	if(!fout201)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n200; i++)
	{
		radixSort(v1111111, n200);
		fout201 << v1111111[i] << " ";
	}
	fout201.close();
	double time_start201, time_end201;
	int w1111111[3000];
	int n201 = sizeof(w1111111) / sizeof(w1111111[0]);
	GenerateRandomData(w1111111, n201);
	time_start201 = clock();
	radixSort(w1111111, n201);
	time_end201 = clock();
	cout << "Radix sort with 3000 elements random: " << (time_end201 - time_start201) / CLK_TCK << " sec" << "\n";
	ofstream fout202;
	fout202.open("RadixSort_Random_3000.txt");
	if(!fout202)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n201; i++)
	{
		radixSort(w1111111, n201);
		fout202 << w1111111[i] << " ";
	}
	fout202.close();
	double time_start202, time_end202;
	int x1111111[10000];
	int n202 = sizeof(x1111111) / sizeof(x1111111[0]);
	GenerateRandomData(x1111111, n202);
	time_start202 = clock();
	radixSort(x1111111, n202);
	time_end202 = clock();
	cout << "Radix sort with 10000 elements random: " << (time_end202 - time_start202) / CLK_TCK << " sec" << "\n";
	ofstream fout203;
	fout203.open("RadixSort_Random_10000.txt");
	if(!fout203)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n202; i++)
	{
		radixSort(x1111111, n202);
		fout203 << x1111111[i] << " ";
	}
	fout203.close();
	double time_start203, time_end203;
	static int y1111111[30000];
	static int n203 = sizeof(y1111111) / sizeof(y1111111[0]);
	GenerateRandomData(y1111111, n203);
	time_start203 = clock();
	radixSort(y1111111, n203);
	time_end203 = clock();
	cout << "Radix sort with 30000 elements random: " << (time_end203 - time_start203) / CLK_TCK << " sec" << "\n";
	ofstream fout204;
	fout204.open("RadixSort_Random_30000.txt");
	if(!fout204)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n203; i++)
	{
		radixSort(y1111111, n203);
		fout204 << y1111111[i] << " ";
	}
	fout204.close();
	double time_start204, time_end204;
	static int z1111111[100000];
	static int n204 = sizeof(z1111111) / sizeof(z1111111[0]);
	GenerateRandomData(z1111111, n204);
	time_start204 = clock();
	radixSort(z1111111, n204);
	time_end204 = clock();
	cout << "Radix sort with 100000 elements random: " << (time_end204 - time_start204) / CLK_TCK << " sec" << "\n";
	ofstream fout205;
	fout205.open("RadixSort_Random_100000.txt");
	if(!fout205)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n204; i++)
	{
		radixSort(z1111111, n204);
		fout205 << z1111111[i] << " ";
	}
	fout205.close();*/

	/*double time_start205, time_end205;
	int a11111111[1000];
	int n205 = sizeof(a11111111) / sizeof(a11111111[0]);
	GenerateSortedData(a11111111, n205);
	time_start205 = clock();
	radixSort(a11111111, n205);
	time_end205 = clock();
	cout << "Radix sort with 1000 elements sorted: " << (time_end205 - time_start205) / CLK_TCK << " sec" << "\n";
	ofstream fout206;
	fout206.open("RadixSort_Sorted_1000.txt");
	if(!fout206)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n205; i++)
	{
		radixSort(a11111111, n205);
		fout206 << a11111111[i] << " ";
	}
	fout206.close();
	double time_start206, time_end206;
	int b11111111[3000];
	int n206 = sizeof(b11111111) / sizeof(b11111111[0]);
	GenerateSortedData(b11111111, n206);
	time_start206 = clock();
	radixSort(b11111111, n206);
	time_end206 = clock();
	cout << "Radix sort with 3000 elements sorted: " << (time_end206 - time_start206) / CLK_TCK << " sec" << "\n";
	ofstream fout207;
	fout207.open("RadixSort_Sorted_3000.txt");
	if(!fout207)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n206; i++)
	{
		radixSort(b11111111, n206);
		fout207 << b11111111[i] << " ";
	}
	fout207.close();
	double time_start207, time_end207;
	int c11111111[10000];
	int n207 = sizeof(c11111111) / sizeof(c11111111[0]);
	GenerateSortedData(c11111111, n207);
	time_start207 = clock();
	radixSort(c11111111, n207);
	time_end207 = clock();
	cout << "Radix sort with 10000 elements sorted: " << (time_end207 - time_start207) / CLK_TCK << " sec" << "\n";
	ofstream fout208;
	fout208.open("RadixSort_Sorted_10000.txt");
	if(!fout208)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n207; i++)
	{
		radixSort(c11111111, n207);
		fout208 << c11111111[i] << " ";
	}
	fout208.close();
	double time_start208, time_end208;
	static int d11111111[30000];
	static int n208 = sizeof(d11111111) / sizeof(d11111111[0]);
	GenerateSortedData(d11111111, n208);
	time_start208 = clock();
	radixSort(d11111111, n208);
	time_end208 = clock();
	cout << "Radix sort with 30000 elements sorted: " << (time_end208 - time_start208) / CLK_TCK << " sec" << "\n";
	ofstream fout209;
	fout209.open("RadixSort_Sorted_30000.txt");
	if(!fout209)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n208; i++)
	{
		radixSort(d11111111, n208);
		fout209 << d11111111[i] << " ";
	}
	fout209.close();
	double time_start209, time_end209;
	static int e11111111[100000];
	static int n209 = sizeof(e11111111) / sizeof(e11111111[0]);
	GenerateSortedData(e11111111, n209);
	time_start209 = clock();
	radixSort(e11111111, n209);
	time_end209 = clock();
	cout << "Radix sort with 100000 elements sorted: " << (time_end209 - time_start209) / CLK_TCK << " sec" << "\n";
	ofstream fout210;
	fout210.open("RadixSort_Sorted_100000.txt");
	if(!fout210)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n209; i++)
	{
		radixSort(e11111111, n209);
		fout210 << e11111111[i] << " ";
	}
	fout210.close();*/

	/*double time_start210, time_end210;
	int f11111111[1000];
	int n210 = sizeof(f11111111) / sizeof(f11111111[0]);
	GenerateReverseData(f11111111, n210);
	time_start210 = clock();
	radixSort(f11111111, n210);
	time_end210 = clock();
	cout << "Radix sort with 1000 elements reversed: " << (time_end210 - time_start210) / CLK_TCK << " sec" << "\n";
	ofstream fout211;
	fout211.open("RadixSort_Reversed_1000.txt");
	if(!fout211)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n210; i++)
	{
		radixSort(f11111111, n210);
		fout211 << f11111111[i] << " ";
	}
	fout211.close();
	double time_start211, time_end211;
	int g11111111[3000];
	int n211 = sizeof(g11111111) / sizeof(g11111111[0]);
	GenerateReverseData(g11111111, n211);
	time_start211 = clock();
	radixSort(g11111111, n211);
	time_end211 = clock();
	cout << "Radix sort with 3000 elements reversed: " << (time_end211 - time_start211) / CLK_TCK << " sec" << "\n";
	ofstream fout212;
	fout212.open("RadixSort_Reversed_3000.txt");
	if(!fout212)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n211; i++)
	{
		radixSort(g11111111, n211);
		fout212 << g11111111[i] << " ";
	}
	fout212.close();
	double time_start212, time_end212;
	int h11111111[10000];
	int n212 = sizeof(h11111111) / sizeof(h11111111[0]);
	GenerateReverseData(h11111111, n212);
	time_start212 = clock();
	radixSort(h11111111, n212);
	time_end212 = clock();
	cout << "Radix sort with 10000 elements reversed: " << (time_end212 - time_start212) / CLK_TCK << " sec" << "\n";
	ofstream fout213;
	fout213.open("RadixSort_Reversed_10000.txt");
	if(!fout213)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n212; i++)
	{
		radixSort(h11111111, n212);
		fout213 << h11111111[i] << " ";
	}
	fout213.close();
	double time_start213, time_end213;
	static int i11111111[30000];
	static int n213 = sizeof(i11111111) / sizeof(i11111111[0]);
	GenerateReverseData(i11111111, n213);
	time_start213 = clock();
	radixSort(i11111111, n213);
	time_end213 = clock();
	cout << "Radix sort with 30000 elements reversed: " << (time_end213 - time_start213) / CLK_TCK << " sec" << "\n";
	ofstream fout214;
	fout214.open("RadixSort_Reversed_30000.txt");
	if(!fout214)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n213; i++)
	{
		radixSort(i11111111, n213);
		fout214 << i11111111[i] << " ";
	}
	fout214.close();
	double time_start214, time_end214;
	static int j11111111[100000];
	static int n214 = sizeof(j11111111) / sizeof(j11111111[0]);
	GenerateReverseData(j11111111, n214);
	time_start214 = clock();
	radixSort(j11111111, n214);
	time_end214 = clock();
	cout << "Radix sort with 100000 elements reversed: " << (time_end214 - time_start214) / CLK_TCK << " sec" << "\n";
	ofstream fout215;
	fout215.open("RadixSort_Reversed_100000.txt");
	if(!fout215)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n214; i++)
	{
		radixSort(j11111111, n214);
		fout215 << j11111111[i] << " ";
	}
	fout215.close();*/

	/*double time_start215, time_end215;
	int k11111111[1000];
	int n215 = sizeof(k11111111) / sizeof(k11111111[0]);
	GenerateNearlySortedData(k11111111, n215);
	time_start215 = clock();
	radixSort(k11111111, n215);
	time_end215 = clock();
	cout << "Radix sort with 1000 elements nearly sorted: " << (time_end215 - time_start215) / CLK_TCK << " sec" << "\n";
	ofstream fout216;
	fout216.open("RadixSort_NearlySorted_1000.txt");
	if(!fout216)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n215; i++)
	{
		radixSort(k11111111, n215);
		fout216 << k11111111[i] << " ";
	}
	fout216.close();
	double time_start216, time_end216;
	int l11111111[3000];
	int n216 = sizeof(l11111111) / sizeof(l11111111[0]);
	GenerateNearlySortedData(l11111111, n216);
	time_start216 = clock();
	radixSort(l11111111, n216);
	time_end216 = clock();
	cout << "Radix sort with 3000 elements nearly sorted: " << (time_end216 - time_start216) / CLK_TCK << " sec" << "\n";
	ofstream fout217;
	fout217.open("RadixSort_NearlySorted_3000.txt");
	if(!fout217)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n216; i++)
	{
		radixSort(l11111111, n216);
		fout217 << l11111111[i] << " ";
	}
	fout217.close();
	double time_start217, time_end217;
	int m11111111[10000];
	int n217 = sizeof(m11111111) / sizeof(m11111111[0]);
	GenerateNearlySortedData(m11111111, n217);
	time_start217 = clock();
	radixSort(m11111111, n217);
	time_end217 = clock();
	cout << "Radix sort with 10000 elements nearly sorted: " << (time_end217 - time_start217) / CLK_TCK << " sec" << "\n";
	ofstream fout218;
	fout218.open("RadixSort_NearlySorted_10000.txt");
	if(!fout218)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n217; i++)
	{
		radixSort(m11111111, n217);
		fout218 << m11111111[i] << " ";
	}
	fout218.close();
	double time_start218, time_end218;
	static int n11111111[30000];
	static int n218 = sizeof(n11111111) / sizeof(n11111111[0]);
	GenerateNearlySortedData(n11111111, n218);
	time_start218 = clock();
	radixSort(n11111111, n218);
	time_end218 = clock();
	cout << "Radix sort with 30000 elements nearly sorted: " << (time_end218 - time_start218) / CLK_TCK << " sec" << "\n";
	ofstream fout219;
	fout219.open("RadixSort_NearlySorted_30000.txt");
	if(!fout219)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n218; i++)
	{
		radixSort(n11111111, n218);
		fout219 << n11111111[i] << " ";
	}
	fout219.close();
	double time_start219, time_end219;
	static int o11111111[100000];
	static int n219 = sizeof(o11111111) / sizeof(o11111111[0]);
	GenerateNearlySortedData(o11111111, n219);
	time_start219 = clock();
	radixSort(o11111111, n219);
	time_end219 = clock();
	cout << "Radix sort with 100000 elements nearly sorted: " << (time_end219 - time_start219) / CLK_TCK << " sec" << "\n";
	ofstream fout220;
	fout220.open("RadixSort_NearlySorted_100000.txt");
	if(!fout220)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n219; i++)
	{
		radixSort(o11111111, n219);
		fout220 << o11111111[i] << " ";
	}
	fout220.close();*/





	////////////////////////Flash sort///////////////////////
	/*double time_start220, time_end220;
	int p11111111[1000];
	int n220 = sizeof(p11111111) / sizeof(p11111111[0]);
	GenerateRandomData(p11111111, n220);
	time_start220 = clock();
	flashSort(p11111111, n220);
	time_end220 = clock();
	cout << "Flash sort with 1000 elements random: " << (time_end220 - time_start220) / CLK_TCK << " sec" << "\n";
	ofstream fout221;
	fout221.open("FlashSort_Random_1000.txt");
	if(!fout221)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n220; i++)
	{
		flashSort(p11111111, n220);
		fout221 << p11111111[i] << " ";
	}
	fout221.close();
	double time_start221, time_end221;
	int q11111111[3000];
	int n221 = sizeof(q11111111) / sizeof(q11111111[0]);
	GenerateRandomData(q11111111, n221);
	time_start221 = clock();
	flashSort(q11111111, n221);
	time_end221 = clock();
	cout << "Flash sort with 3000 elements random: " << (time_end221 - time_start221) / CLK_TCK << " sec" << "\n";
	ofstream fout222;
	fout222.open("FlashSort_Random_3000.txt");
	if(!fout222)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n221; i++)
	{
		flashSort(q11111111, n221);
		fout222 << q11111111[i] << " ";
	}
	fout222.close();
	double time_start222, time_end222;
	int r11111111[10000];
	int n222 = sizeof(r11111111) / sizeof(r11111111[0]);
	GenerateRandomData(r11111111, n222);
	time_start222 = clock();
	flashSort(r11111111, n222);
	time_end222 = clock();
	cout << "Flash sort with 10000 elements random: " << (time_end222 - time_start222) / CLK_TCK << " sec" << "\n";
	ofstream fout223;
	fout223.open("FlashSort_Random_10000.txt");
	if(!fout223)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n222; i++)
	{
		flashSort(r11111111, n222);
		fout223 << r11111111[i] << " ";
	}
	fout223.close();
	double time_start223, time_end223;
	static int s11111111[30000];
	static int n223 = sizeof(s11111111) / sizeof(s11111111[0]);
	GenerateRandomData(s11111111, n223);
	time_start223 = clock();
	flashSort(s11111111, n223);
	time_end223 = clock();
	cout << "Flash sort with 30000 elements random: " << (time_end223 - time_start223) / CLK_TCK << " sec" << "\n";
	ofstream fout224;
	fout224.open("FlashSort_Random_30000.txt");
	if(!fout224)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n223; i++)
	{
		flashSort(s11111111, n223);
		fout224 << s11111111[i] << " ";
	}
	fout224.close();
	double time_start224, time_end224;
	static int t11111111[100000];
	static int n224 = sizeof(t11111111) / sizeof(t11111111[0]);
	GenerateRandomData(t11111111, n224);
	time_start224 = clock();
	flashSort(t11111111, n224);
	time_end224 = clock();
	cout << "Flash sort with 100000 elements random: " << (time_end224 - time_start224) / CLK_TCK << " sec" << "\n";
	ofstream fout225;
	fout225.open("FlashSort_Random_100000.txt");
	if(!fout225)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n224; i++)
	{
		flashSort(t11111111, n224);
		fout225 << t11111111[i] << " ";
	}
	fout225.close();*/

	/*double time_start225, time_end225;
	int u11111111[1000];
	int n225 = sizeof(u11111111) / sizeof(u11111111[0]);
	GenerateSortedData(u11111111, n225);
	time_start225 = clock();
	flashSort(u11111111, n225);
	time_end225 = clock();
	cout << "Flash sort with 1000 elements sorted: " << (time_end225 - time_start225) / CLK_TCK << " sec" << "\n";
	ofstream fout226;
	fout226.open("FlashSort_Sorted_1000.txt");
	if(!fout226)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n225; i++)
	{
		flashSort(u11111111, n225);
		fout226 << u11111111[i] << " ";
	}
	fout226.close();
	double time_start226, time_end226;
	int v11111111[3000];
	int n226 = sizeof(v11111111) / sizeof(v11111111[0]);
	GenerateSortedData(v11111111, n226);
	time_start226 = clock();
	flashSort(v11111111, n226);
	time_end226 = clock();
	cout << "Flash sort with 3000 elements sorted: " << (time_end226 - time_start226) / CLK_TCK << " sec" << "\n";
	ofstream fout227;
	fout227.open("FlashSort_Sorted_3000.txt");
	if(!fout227)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n226; i++)
	{
		flashSort(v11111111, n226);
		fout227 << v11111111[i] << " ";
	}
	fout227.close();
	double time_start227, time_end227;
	int w11111111[10000];
	int n227 = sizeof(w11111111) / sizeof(w11111111[0]);
	GenerateSortedData(w11111111, n227);
	time_start227 = clock();
	flashSort(w11111111, n227);
	time_end227 = clock();
	cout << "Flash sort with 10000 elements sorted: " << (time_end227 - time_start227) / CLK_TCK << " sec" << "\n";
	ofstream fout228;
	fout228.open("FlashSort_Sorted_10000.txt");
	if(!fout228)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n227; i++)
	{
		flashSort(w11111111, n227);
		fout228 << w11111111[i] << " ";
	}
	fout228.close();
	double time_start228, time_end228;
	static int x11111111[30000];
	static int n228 = sizeof(x11111111) / sizeof(x11111111[0]);
	GenerateSortedData(x11111111, n228);
	time_start228 = clock();
	flashSort(x11111111, n228);
	time_end228 = clock();
	cout << "Flash sort with 30000 elements sorted: " << (time_end228 - time_start228) / CLK_TCK << " sec" << "\n";
	ofstream fout229;
	fout229.open("FlashSort_Sorted_30000.txt");
	if(!fout229)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n228; i++)
	{
		flashSort(x11111111, n228);
		fout229 << x11111111[i] << " ";
	}
	fout229.close();
	double time_start229, time_end229;
	static int y11111111[100000];
	static int n229 = sizeof(y11111111) / sizeof(y11111111[0]);
	GenerateSortedData(y11111111, n229);
	time_start229 = clock();
	flashSort(y11111111, n229);
	time_end229 = clock();
	cout << "Flash sort with 100000 elements sorted: " << (time_end229 - time_start229) / CLK_TCK << " sec" << "\n";
	ofstream fout230;
	fout230.open("FlashSort_Sorted_100000.txt");
	if(!fout230)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n229; i++)
	{
		flashSort(y11111111, n229);
		fout230 << y11111111[i] << " ";
	}
	fout230.close();*/

	/*double time_start230, time_end230;
	int z11111111[1000];
	int n230 = sizeof(z11111111) / sizeof(z11111111[0]);
	GenerateReverseData(z11111111, n230);
	time_start230 = clock();
	flashSort(z11111111, n230);
	time_end230 = clock();
	cout << "Flash sort with 1000 elements reversed: " << (time_end230 - time_start230) / CLK_TCK << " sec" << "\n";
	ofstream fout231;
	fout231.open("FlashSort_Reversed_1000.txt");
	if(!fout231)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n230; i++)
	{
		flashSort(z11111111, n230);
		fout231 << z11111111[i] << " ";
	}
	fout231.close();
	double time_start231, time_end231;
	int a111111111[3000];
	int n231 = sizeof(a111111111) / sizeof(a111111111[0]);
	GenerateReverseData(a111111111, n231);
	time_start231 = clock();
	flashSort(a111111111, n231);
	time_end231 = clock();
	cout << "Flash sort with 3000 elements reversed: " << (time_end231 - time_start231) / CLK_TCK << " sec" << "\n";
	ofstream fout232;
	fout232.open("FlashSort_Reversed_3000.txt");
	if(!fout232)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n231; i++)
	{
		flashSort(a111111111, n231);
		fout232 << a111111111[i] << " ";
	}
	fout232.close();
	double time_start232, time_end232;
	int b111111111[10000];
	int n232 = sizeof(b111111111) / sizeof(b111111111[0]);
	GenerateReverseData(b111111111, n232);
	time_start232 = clock();
	flashSort(b111111111, n232);
	time_end232 = clock();
	cout << "Flash sort with 10000 elements reversed: " << (time_end232 - time_start232) / CLK_TCK << " sec" << "\n";
	ofstream fout233;
	fout233.open("FlashSort_Reversed_10000.txt");
	if(!fout233)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n232; i++)
	{
		flashSort(b111111111, n232);
		fout233 << b111111111[i] << " ";
	}
	fout233.close();
	double time_start233, time_end233;
	static int c111111111[30000];
	static int n233 = sizeof(c111111111) / sizeof(c111111111[0]);
	GenerateReverseData(c111111111, n233);
	time_start233 = clock();
	flashSort(c111111111, n233);
	time_end233 = clock();
	cout << "Flash sort with 30000 elements reversed: " << (time_end233 - time_start233) / CLK_TCK << " sec" << "\n";
	ofstream fout234;
	fout234.open("FlashSort_Reversed_30000.txt");
	if(!fout234)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n233; i++)
	{
		flashSort(c111111111, n233);
		fout234 << c111111111[i] << " ";
	}
	fout234.close();
	double time_start234, time_end234;
	static int d111111111[100000];
	static int n234 = sizeof(d111111111) / sizeof(d111111111[0]);
	GenerateReverseData(d111111111, n234);
	time_start234 = clock();
	flashSort(d111111111, n234);
	time_end234 = clock();
	cout << "Flash sort with 100000 elements reversed: " << (time_end234 - time_start234) / CLK_TCK << " sec" << "\n";
	ofstream fout235;
	fout235.open("FlashSort_Reversed_100000.txt");
	if(!fout235)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n234; i++)
	{
		flashSort(d111111111, n234);
		fout235 << d111111111[i] << " ";
	}
	fout235.close();*/

	/*double time_start235, time_end235;
	int e111111111[1000];
	int n235 = sizeof(e111111111) / sizeof(e111111111[0]);
	GenerateNearlySortedData(e111111111, n235);
	time_start235 = clock();
	flashSort(e111111111, n235);
	time_end235 = clock();
	cout << "Flash sort with 1000 elements nearly sorted: " << (time_end235 - time_start235) / CLK_TCK << " sec" << "\n";
	ofstream fout236;
	fout236.open("FlashSort_NearlySorted_1000.txt");
	if(!fout236)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n235; i++)
	{
		flashSort(e111111111, n235);
		fout236 << e111111111[i] << " ";
	}
	fout236.close();
	double time_start236, time_end236;
	int f111111111[3000];
	int n236 = sizeof(f111111111) / sizeof(f111111111[0]);
	GenerateNearlySortedData(f111111111, n236);
	time_start236 = clock();
	flashSort(f111111111, n236);
	time_end236 = clock();
	cout << "Flash sort with 3000 elements nearly sorted: " << (time_end236 - time_start236) / CLK_TCK << " sec" << "\n";
	ofstream fout237;
	fout237.open("FlashSort_NearlySorted_3000.txt");
	if(!fout237)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n236; i++)
	{
		flashSort(f111111111, n236);
		fout237 << e111111111[i] << " ";
	}
	fout237.close();
	double time_start237, time_end237;
	int g111111111[10000];
	int n237 = sizeof(g111111111) / sizeof(g111111111[0]);
	GenerateNearlySortedData(g111111111, n237);
	time_start237 = clock();
	flashSort(g111111111, n237);
	time_end237 = clock();
	cout << "Flash sort with 10000 elements nearly sorted: " << (time_end237 - time_start237) / CLK_TCK << " sec" << "\n";
	ofstream fout238;
	fout238.open("FlashSort_NearlySorted_10000.txt");
	if(!fout238)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n237; i++)
	{
		flashSort(g111111111, n237);
		fout238 << g111111111[i] << " ";
	}
	fout238.close();
	double time_start238, time_end238;
	static int h111111111[30000];
	static int n238 = sizeof(h111111111) / sizeof(h111111111[0]);
	GenerateNearlySortedData(h111111111, n238);
	time_start238 = clock();
	flashSort(h111111111, n238);
	time_end238 = clock();
	cout << "Flash sort with 30000 elements nearly sorted: " << (time_end238 - time_start238) / CLK_TCK << " sec" << "\n";
	ofstream fout239;
	fout239.open("FlashSort_NearlySorted_30000.txt");
	if(!fout239)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n238; i++)
	{
		flashSort(h111111111, n238);
		fout239 << h111111111[i] << " ";
	}
	fout239.close();
	double time_start239, time_end239;
	static int i111111111[100000];
	static int n239 = sizeof(i111111111) / sizeof(i111111111[0]);
	GenerateNearlySortedData(i111111111, n239);
	time_start239 = clock();
	flashSort(i111111111, n239);
	time_end239 = clock();
	cout << "Flash sort with 100000 elements nearly sorted: " << (time_end239 - time_start239) / CLK_TCK << " sec" << "\n";
	ofstream fout240;
	fout240.open("FlashSort_NearlySorted_100000.txt");
	if(!fout240)
	{
		cerr << "File can't open";
		exit(0);
	}
	for(int i = 0; i < n239; i++)
	{
		flashSort(i111111111, n239);
		fout240 << i111111111[i] << " ";
	}
	fout240.close();*/

	
	
	//ofstream fout1;
	//fout1.open("Result.csv", ios::app);
	//fout1 << "Input State, Input Size, Selection, Insertion, Binary, Bubble, Shaker, Shell, Heap, Merge, Quick, Counting, Radix, Flash\n";
	//fout1 << "Random, 1000" << "," << (time_end - time_start) / CLK_TCK << "," << (time_end20 - time_start20) / CLK_TCK << "," << (time_end40 - time_start40) / CLK_TCK  << "," << (time_end60 - time_start60) / CLK_TCK  << "," << (time_end80 - time_start80) / CLK_TCK  << "," << (time_end100 - time_start100) / CLK_TCK  << "," << (time_end120 - time_start120) / CLK_TCK  << "," << (time_end140 - time_start140) / CLK_TCK  << "," << (time_end160 - time_start160) / CLK_TCK  << "," << (time_end180 - time_start180) / CLK_TCK  << "," << (time_end200 - time_start200) / CLK_TCK  << "," << (time_end220 - time_start220) / CLK_TCK << "\n";
    //fout1 << "Random, 3000" << "," << (time_end1 - time_start1) / CLK_TCK << "," << (time_end21 - time_start21) / CLK_TCK << "," << (time_end41 - time_start41) / CLK_TCK  << "," << (time_end61 - time_start61) / CLK_TCK  << "," << (time_end81 - time_start81) / CLK_TCK  << "," << (time_end101 - time_start101) / CLK_TCK  << "," << (time_end121 - time_start121) / CLK_TCK  << "," << (time_end141 - time_start141) / CLK_TCK  << "," << (time_end161 - time_start161) / CLK_TCK  << "," << (time_end181 - time_start181) / CLK_TCK  << "," << (time_end201 - time_start201) / CLK_TCK  << "," << (time_end221 - time_start221) / CLK_TCK << "\n";
	//fout1 << "Random, 10000" << "," << (time_end2 - time_start2) / CLK_TCK << "," << (time_end22 - time_start22) / CLK_TCK << "," << (time_end42 - time_start42) / CLK_TCK  << "," << (time_end62 - time_start62) / CLK_TCK  << "," << (time_end82 - time_start82) / CLK_TCK  << "," << (time_end102 - time_start102) / CLK_TCK  << "," << (time_end122 - time_start122) / CLK_TCK  << "," << (time_end142 - time_start142) / CLK_TCK  << "," << (time_end162 - time_start162) / CLK_TCK  << "," << (time_end182 - time_start182) / CLK_TCK  << "," << (time_end202 - time_start202) / CLK_TCK  << "," << (time_end222 - time_start222) / CLK_TCK << "\n";
	//fout1 << "Random, 30000" << "," << (time_end3 - time_start3) / CLK_TCK << "," << (time_end23 - time_start23) / CLK_TCK << "," << (time_end43 - time_start43) / CLK_TCK  << "," << (time_end63 - time_start63) / CLK_TCK  << "," << (time_end83 - time_start83) / CLK_TCK  << "," << (time_end103 - time_start103) / CLK_TCK  << "," << (time_end123 - time_start123) / CLK_TCK  << "," << (time_end143 - time_start143) / CLK_TCK  << "," << (time_end163 - time_start163) / CLK_TCK  << "," << (time_end183 - time_start183) / CLK_TCK  << "," << (time_end203 - time_start203) / CLK_TCK  << "," << (time_end223 - time_start223) / CLK_TCK << "\n";
	//fout1 << "Random, 100000" << "," << (time_end4 - time_start4) / CLK_TCK << "," << (time_end24 - time_start24) / CLK_TCK << "," << (time_end44 - time_start44) / CLK_TCK  << "," << (time_end64 - time_start64) / CLK_TCK  << "," << (time_end84 - time_start84) / CLK_TCK  << "," << (time_end104 - time_start104) / CLK_TCK  << "," << (time_end124 - time_start124) / CLK_TCK  << "," << (time_end144 - time_start144) / CLK_TCK  << "," << (time_end164 - time_start164) / CLK_TCK  << "," << (time_end184 - time_start184) / CLK_TCK  << "," << (time_end204 - time_start204) / CLK_TCK  << "," << (time_end224 - time_start224) / CLK_TCK << "\n";
	//fout1 << "Sorted, 1000" << "," << (time_end5 - time_start5) / CLK_TCK << "," << (time_end25 - time_start25) / CLK_TCK << "," << (time_end45 - time_start45) / CLK_TCK  << "," << (time_end65 - time_start65) / CLK_TCK  << "," << (time_end85 - time_start85) / CLK_TCK  << "," << (time_end105 - time_start105) / CLK_TCK  << "," << (time_end125 - time_start125) / CLK_TCK  << "," << (time_end145 - time_start145) / CLK_TCK  << "," << (time_end165 - time_start165) / CLK_TCK  << "," << (time_end185 - time_start185) / CLK_TCK  << "," << (time_end205 - time_start205) / CLK_TCK  << "," << (time_end225 - time_start225) / CLK_TCK << "\n";
	//fout1 << "Sorted, 3000" << "," << (time_end6 - time_start6) / CLK_TCK << "," << (time_end26 - time_start26) / CLK_TCK << "," << (time_end46 - time_start46) / CLK_TCK  << "," << (time_end66 - time_start66) / CLK_TCK  << "," << (time_end86 - time_start86) / CLK_TCK  << "," << (time_end106 - time_start106) / CLK_TCK  << "," << (time_end126 - time_start126) / CLK_TCK  << "," << (time_end146 - time_start146) / CLK_TCK  << "," << (time_end166 - time_start166) / CLK_TCK  << "," << (time_end186 - time_start186) / CLK_TCK  << "," << (time_end206 - time_start206) / CLK_TCK  << "," << (time_end226 - time_start226) / CLK_TCK << "\n";
	//fout1 << "Sorted, 10000" << "," << (time_end7 - time_start7) / CLK_TCK << "," << (time_end27 - time_start27) / CLK_TCK << "," << (time_end47 - time_start47) / CLK_TCK  << "," << (time_end67 - time_start67) / CLK_TCK  << "," << (time_end87 - time_start87) / CLK_TCK  << "," << (time_end107 - time_start107) / CLK_TCK  << "," << (time_end127 - time_start127) / CLK_TCK  << "," << (time_end147 - time_start147) / CLK_TCK  << "," << (time_end167 - time_start167) / CLK_TCK  << "," << (time_end187 - time_start187) / CLK_TCK  << "," << (time_end207 - time_start207) / CLK_TCK  << "," << (time_end227 - time_start227) / CLK_TCK << "\n";
	//fout1 << "Sorted, 30000" << "," << (time_end8 - time_start8) / CLK_TCK << "," << (time_end28 - time_start28) / CLK_TCK << "," << (time_end48 - time_start48) / CLK_TCK  << "," << (time_end68 - time_start68) / CLK_TCK  << "," << (time_end88 - time_start88) / CLK_TCK  << "," << (time_end108 - time_start108) / CLK_TCK  << "," << (time_end128 - time_start128) / CLK_TCK  << "," << (time_end148 - time_start148) / CLK_TCK  << "," << (time_end168 - time_start168) / CLK_TCK  << "," << (time_end188 - time_start188) / CLK_TCK  << "," << (time_end208 - time_start208) / CLK_TCK  << "," << (time_end228 - time_start228) / CLK_TCK << "\n";
	//fout1 << "Sorted, 100000" << "," << (time_end9 - time_start9) / CLK_TCK << "," << (time_end29 - time_start29) / CLK_TCK << "," << (time_end49 - time_start49) / CLK_TCK  << "," << (time_end69 - time_start69) / CLK_TCK  << "," << (time_end89 - time_start89) / CLK_TCK  << "," << (time_end109 - time_start109) / CLK_TCK  << "," << (time_end129 - time_start129) / CLK_TCK  << "," << (time_end149 - time_start149) / CLK_TCK  << "," << (time_end169 - time_start169) / CLK_TCK  << "," << (time_end189 - time_start189) / CLK_TCK  << "," << (time_end209 - time_start209) / CLK_TCK  << "," << (time_end229 - time_start229) / CLK_TCK << "\n";
    //fout1 << "Reversed, 1000" << "," << (time_end10 - time_start10) / CLK_TCK << "," << (time_end30 - time_start30) / CLK_TCK << "," << (time_end50 - time_start50) / CLK_TCK  << "," << (time_end70 - time_start70) / CLK_TCK  << "," << (time_end90 - time_start90) / CLK_TCK  << "," << (time_end110 - time_start110) / CLK_TCK  << "," << (time_end130 - time_start130) / CLK_TCK  << "," << (time_end150 - time_start150) / CLK_TCK  << "," << (time_end170 - time_start170) / CLK_TCK  << "," << (time_end190 - time_start190) / CLK_TCK  << "," << (time_end210 - time_start210) / CLK_TCK  << "," << (time_end230 - time_start230) / CLK_TCK << "\n";
	//fout1 << "Reversed, 3000" << "," << (time_end11 - time_start11) / CLK_TCK << "," << (time_end31 - time_start31) / CLK_TCK << "," << (time_end51 - time_start51) / CLK_TCK  << "," << (time_end71 - time_start71) / CLK_TCK  << "," << (time_end91 - time_start91) / CLK_TCK  << "," << (time_end111 - time_start111) / CLK_TCK  << "," << (time_end131 - time_start131) / CLK_TCK  << "," << (time_end151 - time_start151) / CLK_TCK  << "," << (time_end171 - time_start171) / CLK_TCK  << "," << (time_end191 - time_start191) / CLK_TCK  << "," << (time_end211 - time_start211) / CLK_TCK  << "," << (time_end231 - time_start231) / CLK_TCK << "\n";
	//fout1 << "Reversed, 10000" << "," << (time_end12 - time_start12) / CLK_TCK << "," << (time_end32 - time_start32) / CLK_TCK << "," << (time_end52 - time_start52) / CLK_TCK  << "," << (time_end72 - time_start72) / CLK_TCK  << "," << (time_end92 - time_start92) / CLK_TCK  << "," << (time_end112 - time_start112) / CLK_TCK  << "," << (time_end132 - time_start132) / CLK_TCK  << "," << (time_end152 - time_start152) / CLK_TCK  << "," << (time_end172 - time_start172) / CLK_TCK  << "," << (time_end192 - time_start192) / CLK_TCK  << "," << (time_end212 - time_start212) / CLK_TCK  << "," << (time_end232 - time_start232) / CLK_TCK << "\n";
	//fout1 << "Reversed, 30000" << "," << (time_end13 - time_start13) / CLK_TCK << "," << (time_end33 - time_start33) / CLK_TCK << "," << (time_end53 - time_start53) / CLK_TCK  << "," << (time_end73 - time_start73) / CLK_TCK  << "," << (time_end93 - time_start93) / CLK_TCK  << "," << (time_end113 - time_start113) / CLK_TCK  << "," << (time_end133 - time_start133) / CLK_TCK  << "," << (time_end153 - time_start153) / CLK_TCK  << "," << (time_end173 - time_start173) / CLK_TCK  << "," << (time_end193 - time_start193) / CLK_TCK  << "," << (time_end213 - time_start213) / CLK_TCK  << "," << (time_end233 - time_start233) / CLK_TCK << "\n";
	//fout1 << "Reversed, 100000" << "," << (time_end14 - time_start14) / CLK_TCK << "," << (time_end34 - time_start34) / CLK_TCK << "," << (time_end54 - time_start54) / CLK_TCK  << "," << (time_end74 - time_start74) / CLK_TCK  << "," << (time_end94 - time_start94) / CLK_TCK  << "," << (time_end114 - time_start114) / CLK_TCK  << "," << (time_end134 - time_start134) / CLK_TCK  << "," << (time_end154 - time_start154) / CLK_TCK  << "," << (time_end174 - time_start174) / CLK_TCK  << "," << (time_end194 - time_start194) / CLK_TCK  << "," << (time_end214 - time_start214) / CLK_TCK  << "," << (time_end234 - time_start234) / CLK_TCK << "\n";
	//fout1 << "Nearly sorted, 1000" << "," << (time_end15 - time_start15) / CLK_TCK << "," << (time_end35 - time_start35) / CLK_TCK << "," << (time_end55 - time_start55) / CLK_TCK  << "," << (time_end75 - time_start75) / CLK_TCK  << "," << (time_end95 - time_start95) / CLK_TCK  << "," << (time_end115 - time_start115) / CLK_TCK  << "," << (time_end135 - time_start135) / CLK_TCK  << "," << (time_end155 - time_start155) / CLK_TCK  << "," << (time_end175 - time_start175) / CLK_TCK  << "," << (time_end195 - time_start195) / CLK_TCK  << "," << (time_end215 - time_start215) / CLK_TCK  << "," << (time_end235 - time_start235) / CLK_TCK << "\n";
	//fout1 << "Nearly sorted, 3000" << "," << (time_end16 - time_start16) / CLK_TCK << "," << (time_end36 - time_start36) / CLK_TCK << "," << (time_end56 - time_start56) / CLK_TCK  << "," << (time_end76 - time_start76) / CLK_TCK  << "," << (time_end96 - time_start96) / CLK_TCK  << "," << (time_end116 - time_start116) / CLK_TCK  << "," << (time_end136 - time_start136) / CLK_TCK  << "," << (time_end156 - time_start156) / CLK_TCK  << "," << (time_end176 - time_start176) / CLK_TCK  << "," << (time_end196 - time_start196) / CLK_TCK  << "," << (time_end216 - time_start216) / CLK_TCK  << "," << (time_end236 - time_start236) / CLK_TCK << "\n";
	//fout1 << "Nearly sorted, 10000" << "," << (time_end17 - time_start17) / CLK_TCK << "," << (time_end37 - time_start37) / CLK_TCK << "," << (time_end57 - time_start57) / CLK_TCK  << "," << (time_end77 - time_start77) / CLK_TCK  << "," << (time_end97 - time_start97) / CLK_TCK  << "," << (time_end117 - time_start117) / CLK_TCK  << "," << (time_end137 - time_start137) / CLK_TCK  << "," << (time_end157 - time_start157) / CLK_TCK  << "," << (time_end177 - time_start177) / CLK_TCK  << "," << (time_end197 - time_start197) / CLK_TCK  << "," << (time_end217 - time_start217) / CLK_TCK  << "," << (time_end237 - time_start237) / CLK_TCK << "\n";
	//fout1 << "Nearly sorted, 30000" << "," << (time_end18 - time_start18) / CLK_TCK << "," << (time_end38 - time_start38) / CLK_TCK << "," << (time_end58 - time_start58) / CLK_TCK  << "," << (time_end78 - time_start78) / CLK_TCK  << "," << (time_end98 - time_start98) / CLK_TCK  << "," << (time_end118 - time_start118) / CLK_TCK  << "," << (time_end138 - time_start138) / CLK_TCK  << "," << (time_end158 - time_start158) / CLK_TCK  << "," << (time_end178 - time_start178) / CLK_TCK  << "," << (time_end198 - time_start198) / CLK_TCK  << "," << (time_end218 - time_start218) / CLK_TCK  << "," << (time_end238 - time_start238) / CLK_TCK << "\n";
	//fout1 << "Nearly sorted, 100000" << "," << (time_end19 - time_start19) / CLK_TCK << "," << (time_end39 - time_start39) / CLK_TCK << "," << (time_end59 - time_start59) / CLK_TCK  << "," << (time_end79 - time_start79) / CLK_TCK  << "," << (time_end99 - time_start99) / CLK_TCK  << "," << (time_end119 - time_start119) / CLK_TCK  << "," << (time_end139 - time_start139) / CLK_TCK  << "," << (time_end159 - time_start159) / CLK_TCK  << "," << (time_end179 - time_start179) / CLK_TCK  << "," << (time_end199 - time_start199) / CLK_TCK  << "," << (time_end219 - time_start219) / CLK_TCK  << "," << (time_end239 - time_start239) / CLK_TCK << "\n";
	//fout1.close();
	cout << "Open Result.csv to see time complexity for each algorithm !!!";
	return 0;
}