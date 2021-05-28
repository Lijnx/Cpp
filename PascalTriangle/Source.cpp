#include <stdio.h>
#include <iostream>

void arrcmp(int* a, int* b, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (b[i] == 0) break;
		a[i] = b[i];
	}
}

void arrprt(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 0) break;
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int i, j, n, * a, * b;
	puts("¬ведите степень:");
	scanf_s("%d", &n); n++;
	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		a[i] = b[i] = 0;
	a[0] = 1; printf("%d \n", a[0]);
	for (i = 1; i < n; i++)
	{
		b[0] = b[i] = 1;
		for (j = 1; j < i; j++)
			b[j] = a[j - 1] + a[j];
		arrprt(b, n);
		arrcmp(a, b, n);
	}
	free(a);
	free(b);
	return 0;
}