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

void buildRepl(int* arr, int* repl, int* inv, int* res, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
		repl[i] = 0;
	for (i = 0; i < n; i++)
	{
		k = 0;
		for (j = 0; j < n; j++)
			if (repl[j] == 0)
			{
				if (inv[i] == k)
				{
					repl[j] = i + 1;
					break;
				}
				else k++;
			}
	}
	for (i = 0; i < n; i++)
		res[i] = arr[repl[i] - 1];
}

void nextTable(int* inv, int n)
{
	int i = n, x;
	bool flag = true;
	while (flag)
	{
		x = inv[i - 1] + 1;
		if (x > n - i)
		{
			inv[i - 1] = 0;
			i--;
		}
		else
		{
			inv[i - 1] = x;
			flag = false;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	string input;
	int n, i, j;
	cout << "Введите набор цифр:" << endl;
	cin >> input;
	n = input.length();
	int* arr = new int[n];
	int* inv = new int[n];
	int* repl = new int[n];
	int* res = new int[n];
	for (i = 0; i < n; i++)
	{
		arr[i] = input[i] - '0';
		inv[i] = 0;
		repl[i] = 0;
		res[i] = 0;
	}

	cout << "Перестановки:" << endl;
	for (i = 0; i < fact(n); i++)
	{
		buildRepl(arr, repl, inv, res, n);
		output(res, n);
		nextTable(inv, n);
	}

	return 0;
}