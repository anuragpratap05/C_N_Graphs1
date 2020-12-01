# C_N_Graphs1
#include<bits/stdc++.h>
using namespace std;

class DSU
{
	int* parent;
	int* rank;
public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i)
	{
		if (parent[i] == -1)
		{
			return i;
		}

		return parent[i] = find(parent[i]);
	}

	void unite(int x, int y)
	{
		int s1 = find(x);
		int s2 = find(y);
		if (s1 != s2)
		{
			if (rank[s1] < rank[s2])
			{
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else
			{
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

};

class graph
{
	int V;
	vector<vector<int>> edgelist;
public:
	graph(int V)
	{
		this->V = V;
	}
	void addedge(int x, int y, int w)
	{
		edgelist.push_back({w, x, y});
	}

	void kruksal()
	{
		DSU s(V);

		sort(edgelist.begin(), edgelist.end());

		for (auto edge : edgelist)
		{
			int w = edge[0];
			int v1 = edge[1];
			int v2 = edge[2];
			if (s.find(v1) != s.find(v2))
			{
				if (v1 < v2)
				{
					cout << v1 << " " << v2 << " " << w << endl;
				}
				else
				{
					cout << v2 << " " << v1 << " " << w << endl;
				}
				s.unite(v1, v2);
			}
		}
	}





};

int main()
{


	int V, e;
	cin >> V >> e;
	graph g(V);
	for (int i = 0; i < e; i++)
	{
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		g.addedge(v1, v2, w);
	}

	g.kruksal();

}
