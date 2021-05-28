#include <iostream>
#include <string>
using namespace std;

#define ASize 256

void inputData(string& s, string& q)
{
	cout << "¬ведите строку:" << endl;
	getline(cin, s);
	cout << "¬ведите подстроку:" << endl;
	getline(cin, q);
}

int BMSearch(string s, string q)
{
	int d[ASize];
	int N = s.length(), M = q.length();
	int i, j, k;
	for (i = 0; i < ASize; i++)
		d[i] = M;
	for (i = 0; i < M - 1; i++)
		d[q[i]] = M - i - 1;
	i = M - 1;
	do
	{
		j = M - 1;
		k = i;
		while ((j >= 0) && (q[j] == s[k]))
		{
			k--;
			j--;
		}
		if (j < 0)
		{
			return k + 1;
		}
		i += d[s[i]];
	} while (i < N);
	return -1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string s, q;
	inputData(s, q);
	cout << BMSearch(s, q);
	return 0;
}