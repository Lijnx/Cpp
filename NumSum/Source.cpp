#include <stdio.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	char s[100];
	int i = 0, sum = 0, num = 0;
	puts("¬ведите строку:");
	gets_s(s);
	while (s[i] != '\0')
	{
		if ((s[i] >= '0') && (s[i] <= '9'))
		{
			while ((s[i] >= '0') && (s[i] <= '9'))
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			sum += num;
			num = 0;
			continue;
		}
		i++;
	}
	printf("—умма чисел: %d", sum);
	return 0;
}