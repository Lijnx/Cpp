#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");

	//int n, i, j, check;
	//printf_s("Введите натуральное число: ");
	//scanf_s("%d", &n);
	//puts("Простые числа:");
	//for (i = 2; i <= n; i++)
	//{
	//	check = 0;
	//	for (j = 2; j <= i / 2; j++)
	//	{
	//		if (i % j == 0)
	//		{
	//			check = 1;
	//			break;
	//		}
	//	}
	//	if (check == 0) printf_s("%d ", i);
	//}

	int n, i, j, * a;
	printf_s("Введите натуральное число: ");
	scanf_s("%d", &n); n++;
	a = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) a[i] = i;

	for (i = 2; i < n; i++)
		if (a[i] != 0)
			for (j = 2 * i; j < n; j = j + i)
				a[j] = 0;

	for (i = 1; i < n; i++)
		if (a[i] != 0)
			printf_s("%d ", a[i]);

	free(a);

	return 0;
}