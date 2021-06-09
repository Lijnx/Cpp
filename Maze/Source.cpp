#include <iostream>
#include <fstream>
#include <queue>
#include <Windows.h>
#include <iomanip>
using namespace std;

#define start_x 0
#define start_y 6

#define finish_x 9
#define finish_y 4

void print_maze(int** matrix, int size)
{
	for (int i = 0; i < size + 2; i++) cout << setw(3) << "X";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << setw(3) << "X";
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == -1)
				cout << setw(3) << "X";
			else
				if (matrix[i][j] == 0)
					cout << setw(3) << " ";
				else cout << setw(3) << matrix[i][j];
		}
		cout << setw(3) << "X" << endl;
	}
	for (int i = 0; i < size + 2; i++) cout << setw(3) << "X";
	cout << endl;
}

bool is_finish(pair<int, int> cell)
{
	return (cell.first == finish_x && cell.second == finish_y);
}

int main()
{
	int** matrix;
	int size;
	queue<pair<int, int>> q;

	ifstream fin("maze.txt");
	fin >> size;

	matrix = new int* [size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			fin >> matrix[i][j];

	matrix[start_x][start_y] = 1;
	q.push(make_pair(start_x, start_y));

	print_maze(matrix, size);
	Sleep(5000);

	while (!q.empty())
	{
		pair<int, int> cell = q.front();
		q.pop();

		if (!is_finish(cell))
		{
			int value = matrix[cell.first][cell.second] + 1;
			if (cell.first - 1 >= 0 && matrix[cell.first - 1][cell.second] == 0)
			{
				matrix[cell.first - 1][cell.second] = value;
				q.push(make_pair(cell.first - 1, cell.second));
			}
			if (cell.first + 1 < size && matrix[cell.first + 1][cell.second] == 0)
			{
				matrix[cell.first + 1][cell.second] = value;
				q.push(make_pair(cell.first + 1, cell.second));
			}
			if (cell.second - 1 >= 0 && matrix[cell.first][cell.second - 1] == 0)
			{
				matrix[cell.first][cell.second - 1] = value;
				q.push(make_pair(cell.first, cell.second - 1));
			}
			if (cell.second + 1 < size && matrix[cell.first][cell.second + 1] == 0)
			{
				matrix[cell.first][cell.second + 1] = value;
				q.push(make_pair(cell.first, cell.second + 1));
			}
		}
		else
		{
			cout << matrix[cell.first][cell.second];
			break;
		}

		print_maze(matrix, size);
		Sleep(1000);
	}

	return 0;
}