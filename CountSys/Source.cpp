#include <stdio.h>
#include <string.h>
#include <iostream>

int charToInt(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return (ch - '0');
	else return (ch - 'A' + 10);
}

char intToChar(int a)
{
	if ((a >= 0) && (a <= 9))
		return (a + '0');
	else return (a + 'A' - 10);
}

int main()
{
	setlocale(LC_ALL, "RUS");
	char str[255], * whole, * frac;
	int i = 0, j = 0, flen, wlen, b, k;
	puts("������� �����:");
	gets_s(str);
	puts("������� ��������� ����������� ������� ���������:");
	scanf_s("%d", &k);
	puts("������� ��������� �������� ������� ���������:");
	scanf_s("%d", &b);

	//����������� ������� ������������ ��������
	while (str[i] != '.') i++;
	i++; j = i;
	whole = (char*)malloc(sizeof(char) * i);
	while (str[i] != '\0') i++;
	frac = (char*)malloc(sizeof(char) * (i - j));

	//���������� ������������ ��������
	i = 0;
	while (str[i] != '.')
	{
		str[i] = toupper(str[i]);
		whole[i] = str[i];
		i++;
	}
	wlen = i;
	whole[wlen] = '\0';
	i++; j = i;
	while (str[i] != '\0')
	{
		str[i] = toupper(str[i]);
		frac[i - j] = str[i];
		i++;
	}
	flen = i - j;
	frac[flen] = '\0';

	//����� ����� � 10 �.�.
	int w = 0;
	for (i = 0; i < wlen; i++)
		w = w * k + charToInt(whole[i]);
	free(whole);


	//������� ����� � 10 �.�.
	double f = 0;
	for (i = 0; i < flen; i++)
		f = (charToInt(frac[i]) + f) / k;
	free(frac);

	//����� � b �.�.

	//������� � b �.�.

	return 0;
}