#include <iostream>
#include <fstream>
#include <limits>
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

	~Graph()
	{
	}

	int get_size()
	{
		return size;
	}

	int** get_matrix()
	{
		return matrix;
	}

	void set_adj_matrix(string filename)
	{
		ifstream fin(filename);
		fin >> size;

		matrix = new int* [get_size()];
		for (int i = 0; i < get_size(); i++)
			matrix[i] = new int[get_size()];

		for (int i = 0; i < get_size(); i++)
			for (int j = 0; j < get_size(); j++)
				matrix[i][j] = 0;

		while (!fin.eof())
		{
			int node0, node1;
			fin >> node0;
			fin >> node1;
			matrix[node0 - 1][node1 - 1] = 1;
		}
	}

	void set_weight_matrix(string filename)
	{
		ifstream fin(filename);
		fin >> size;

		matrix = new int* [get_size()];
		for (int i = 0; i < get_size(); i++)
			matrix[i] = new int[get_size()];

		for (int i = 0; i < get_size(); i++)
			for (int j = 0; j < get_size(); j++)
				matrix[i][j] = 0;

		while (!fin.eof())
		{
			int node0, node1, weight;
			fin >> node0;
			fin >> node1;
			fin >> weight;
			matrix[node0 - 1][node1 - 1] = weight;
			//matrix[node1 - 1][node0 - 1] = weight;
		}
	}

	void MSF()
	{
		int** weight_matrix = get_matrix();
		int* node_array = new int[get_size()];
		for (int i = 0; i < get_size(); i++)
			node_array[i] = i;

		int min, min_i, min_j;

		//Initialization
		for (int i = 0; i < get_size(); i++)
			for (int j = 0; j < get_size(); j++)
				if (weight_matrix[i][j] != 0)
				{
					min = weight_matrix[i][j];
					min_i = i;
					min_j = j;
				}

		//Sort
		for (int i = 0; i < get_size(); i++)
			for (int j = 0; j < get_size(); j++)
				if ((weight_matrix[i][j] != 0) && (weight_matrix[i][j] < min))
				{
					min = weight_matrix[i][j];
					min_i = i;
					min_j = j;
				}
		node_array[min_j] = node_array[min_i];

	}

	void top_sort()
	{
		int** adj_matrix = get_matrix();

		bool* used_nodes = new bool[get_size()];
		for (int i = 0; i < get_size(); i++)
			used_nodes[i] = false;

		bool run = true;
		while (run)
		{
			run = false;
			for (int i = 0; i < get_size(); i++)
			{
				if (used_nodes[i] == false)
				{

					bool check = true;
					for (int j = 0; j < get_size(); j++)
						if (adj_matrix[j][i] != 0)
							check = false;

					if (check)
					{
						cout << i + 1;
						used_nodes[i] = true;
						for (int j = 0; j < get_size(); j++)
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
	Graph graph;
	graph.set_adj_matrix("G:\\C++\\TopSort\\matrix.txt");
	graph.top_sort();
	return 0;
}