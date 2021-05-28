#include <fstream>
using namespace std;

#define INFILE "arrin.txt"
#define OUTFILE "arrout.txt"

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
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

void sort(int* arr, int n)
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

int getSize(string filename)
{
	int n = 0;
	char buf;
	ifstream fin(filename);
	while (!fin.eof())
	{
		fin.get(buf);
		if (buf == ' ')
			n++;
	}
	fin.close();
	return n;
}

void readArr(string filename, int* arr, int n)
{
	int i;
	ifstream fin(filename);
	for (i = 0; i < n; i++)
		fin >> arr[i];
	fin.close();
}

void writeArr(string filename, int* arr, int n)
{
	int i;
	ofstream fout(filename);
	for (i = 0; i < n; i++)
		fout << arr[i] << " ";
	fout.close();
}

int main()
{
	int n = getSize(INFILE);
	int* arr = new int[n];
	readArr(INFILE, arr, n);
	sort(arr, n);
	writeArr(OUTFILE, arr, n);
	return 0;
}