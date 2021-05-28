#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define N 10

void init(int* arr, int n)
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++)
	{
		arr[i] = rand() % 200 - 100;
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
	cout << endl;
}

void output(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << "arr[" << i << "] = " << arr[i] << endl;
	cout << endl;
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void bubble(int* arr, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
		for (j = n - 1; j >= i; j--)
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
}

void shaker(int* arr, int n)
{
	int left = 0, right = n - 1, i;
	bool f = true;
	while (f)
	{
		f = false;
		i = left;
		while (i < right)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				f = true;
			}
			i++;
		}
		right--;
		if (f)
		{
			f = false;
			i = right;
			while (i > left)
			{
				if (arr[i] < arr[i - 1])
				{
					swap(arr[i], arr[i - 1]);
					f = true;
				}
				i--;
			}
		}
		left++;
	}
}

void sort(int* arr, int n)
{
	int ch;
	cout << "Выберите метод сортировки:" << endl << "1: Пузырек" << endl << "2: Шейкер" << endl;
	cin >> ch;
	cout << endl;
	if (ch == 1)
		bubble(arr, n);
	else
		shaker(arr, n);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int arr[N];
	init(arr, N);
	sort(arr, N);
	output(arr, N);
	return 0;
}