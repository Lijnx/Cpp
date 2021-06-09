#include <iostream>
#include <fstream>
using namespace std;

class Graph
{
private:
	int** matrix;
	int size;
public:
	Graph()
	{
		matrix = nullptr;
		size = 0;
	}

	Graph(string filename)
	{
		set_matrix(filename);
	}

	~Graph()
	{
	}

	int** get_matrix()
	{
		return matrix;
	}

	void set_matrix(string filename)
	{
		ifstream fin(filename);
		fin >> size;

		matrix = new int* [size];
		for (int i = 0; i < size; i++)
			matrix[i] = new int[size];

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				matrix[i][j] = 0;

		while (!fin.eof())
		{
			int node0, node1;
			fin >> node0;
			fin >> node1;
			matrix[node0 - 1][node1 - 1] = 1;
		}
	}

	void top_sort()
	{
		int** adj_matrix = get_matrix();

		bool* used_nodes = new bool[size];
		for (int i = 0; i < size; i++)
			used_nodes[i] = false;

		bool run = true;
		while (run)
		{
			run = false;
			for (int i = 0; i < size; i++)
			{
				if (used_nodes[i] == false)
				{

					bool check = true;
					for (int j = 0; j < size; j++)
						if (adj_matrix[j][i] != 0)
							check = false;

					if (check)
					{
						cout << i + 1;
						used_nodes[i] = true;
						for (int j = 0; j < size; j++)
							adj_matrix[i][j] = 0;
						run = true;
					}
				}
			}
		}
	}
};

int main()
{
	Graph graph("matrix.txt");
	graph.top_sort();
	return 0;
}