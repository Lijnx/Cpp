#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU
{
private:
	int* parent;
	int* rank;
public:
	DSU(int size)
	{
		parent = new int[size];
		rank = new int[size];
	}

	~DSU()
	{
		delete[] parent;
		delete[] rank;
	}

	void make_set(int v) {
		parent[v] = v;
		rank[v] = 0;
	}

	int find_set(int v) {
		if (v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (rank[a] < rank[b])
				swap(a, b);
			parent[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}
	}
};

class Graph
{
private:
	vector<pair<int, pair<int, int>>> G;
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
		G.clear();
	}

	void set_lines(string filename)
	{
		ifstream fin(filename);
		fin >> size;

		while (!fin.eof())
		{
			int a, b, l;
			fin >> a;
			fin >> b;
			fin >> l;
			G.push_back(make_pair(l, make_pair(a - 1, b - 1)));
		}
	}

	void MST()
	{
		sort(G.begin(), G.end());
		vector<pair<int, int>> result;
		DSU dsu(size);
		for (int i = 0; i < size; i++)
			dsu.make_set(i);

		for (int i = 0; i < G.size(); i++)
		{
			int a = G[i].second.first, b = G[i].second.second, l = G[i].first;
			if (dsu.find_set(a) != dsu.find_set(b))
			{
				result.push_back(G[i].second);
				dsu.union_sets(a, b);
			}
		}

		for (int i = 0; i < result.size(); i++)
			cout << result.at(i).first + 1 << result.at(i).second + 1 << " ";
	}
};

int main()
{
	Graph graph("lines.txt");
	graph.MST();
}