#include <stdio.h>
#include <iostream>

int fact(int n)
{
	if (n == 0) return 1;
	else return n * fact(n - 1);
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int n, i, c;
	puts("Введите степень:");
	scanf_s("%d", &n);
	puts("Коэффициенты:");
	for (i = 0; i <= n; i++)
	{
		c = fact(n) / (fact(i) * fact(n - i));
		printf_s("%d ", c);
	}
}
