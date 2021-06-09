#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
	struct Line
	{
		int node0;
		int node1;
		int weight;
	};
	vector<Line> lines;
	int size;
public:
	Graph()
	{
		size = 0;
	}

	Graph(string filename)
	{
		set_lines(filename);
	}

	~Graph()
	{
	}

	void set_lines(string filename)
	{
		ifstream fin(filename);
		fin >> size;

		while (!fin.eof())
		{
			Line buf;
			fin >> buf.node0;
			fin >> buf.node1;
			fin >> buf.weight;
			lines.push_back(buf);
		}
	}

	void sort_lines()
	{
		for (int i = 0; i < lines.size() - 1; i++)
			for (int j = 0; j < lines.size() - i - 1; j++)
				if (lines.at(j).weight > lines.at(j + 1).weight)
					swap(lines.at(j), lines.at(j + 1));
	}

	void MST()
	{
		int* node_array = new int[size];
		for (int i = 0; i < size; i++)
			node_array[i] = i;

		sort_lines();

		for (int i = 0; i < lines.size(); i++)
		{
			node_array[lines.at(i).node1] = node_array[lines.at(i).node0];
		}
	}
};

int main()
{

}