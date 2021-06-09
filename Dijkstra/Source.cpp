#include <iostream>
#include <string>
using namespace std;

int fact(int n)
{
	if (n == 0) return 1;
	else return n * fact(n - 1);
}

void output(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i];
	cout << " ";
}

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void reverse(int* arr, int a, int n)
{
	int i, j;
	for (i = a + 1, j = n - 1; i < j; i++, j--)
		swap(arr[i], arr[j]);
}

int minInTail(int* arr, int i, int n)
{
	int j, min, k;
	for (j = i + 1; j < n; j++)
	{
		if (arr[j] > arr[i])
		{
			min = arr[j];
			k = j;
			break;
		}
	}
	for (j = i + 1; j < n; j++)
	{
		if ((arr[j] > arr[i]) && (arr[j] < min))
		{
			min = arr[j];
			k = j;
		}
	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	string input;
	int n, i, j, k;
	bool flag;

	cout << "Введите набор цифр:" << endl;
	cin >> input;
	n = input.length();
	int* arr = new int[n];
	for (i = 0; i < n; i++)
		arr[i] = input[i] - '0';

	cout << "Перестановки:" << endl;
	for (j = 0; j < fact(n); j++)
	{
		flag = false;
		for (i = n - 2; i >= 0; i--)
		{
			if (arr[i] < arr[i + 1])
			{
				k = minInTail(arr, i, n);
				swap(arr[k], arr[i]);
				reverse(arr, i, n);
				output(arr, n);
				flag = true;
				break;
			}
		}
		if (!flag)
			break;
	}

	return 0;
}