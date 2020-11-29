#include <bits/stdc++.h>
using namespace std;

void print(bool** edges, int start, bool* visited, int n)
{
	cout << start << ",";
	visited[start] = true;
	for (int i = 0; i < n; i++)
	{
		if (i == start)
		{
			continue;
		}
		if (edges[start][i])
		{
			if (visited[i])
			{
				continue;
			}
			print(edges, i, visited, n);
		}
	}
	return;
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int V, e;
	cin >> V >> e;

	bool** edges = new bool*[V];
	{
		for (int i = 0; i < V; i++)
		{
			edges[i] = new bool[V];
		}
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			edges[i][j] = false;
		}
	}

	for (int i = 0; i < e; ++i)
	{
		int f, s;
		cin >> f >> s;
		edges[f][s] = true;
		edges[s][f] = true;
	}

	bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		/* code */visited[i] = false;
	}

	print(edges, 0, visited, V);
}
