#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define N 10

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void print(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << "arr[" << i << "] = " << arr[i] << endl;
	cout << endl;
}

void init(int* arr, int n)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
		arr[i] = rand() % 100 + 1;
	print(arr, n);
}

void pyramid(int* arr, int n, int i)
{
	int k = i, l = 2 * i + 1, r = 2 * i + 2;
	if (l < n && arr[k] < arr[l])
		k = l;
	if (r < n && arr[k] < arr[r])
		k = r;
	if (k != i)
	{
		swap(arr[i], arr[k]);
		pyramid(arr, n, k);
	}
}

void sorting(int* arr, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; i--)
		pyramid(arr, n, i);
	for (i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		pyramid(arr, i, 0);
	}
}

int main()
{
	int arr[N];
	init(arr, N);
	sorting(arr, N);
	print(arr, N);
	return 0;
}