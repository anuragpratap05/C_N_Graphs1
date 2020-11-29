# C_N_Graphs1
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

bool print_bfs(bool** edges, int src, int dest, int V)

{
	bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	queue<int> pending_v;
	pending_v.push(src);
	//cout<<src<<" ";
	visited[src] = true;

	while (!pending_v.empty())
	{
		int cur_v = pending_v.front();
		if (cur_v == dest)
		{
			return true;
		}
		//cout << cur_v << " ";
		pending_v.pop();
		for (int i = 0; i < V; i++)
		{
			if (cur_v == i)
			{
				continue;
			}
			if (edges[cur_v][i] == true and visited[i] == false)
			{
				pending_v.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
	//delete [] visited;
}

/*void print_bfs_helper(bool** edges, int V)
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{
			print_bfs(edges, i, V, visited);
		}
	}
	delete [] visited;
}*/

int main()
{

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

	int v1, v2;
	cin >> v1 >> v2;

	/*bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}*/
	//cout << "dfs" << endl;
	//cout << endl;
	//print(edges, 0, visited, V);
	//cout << "bfs" << endl;
	//cout << endl;
	if (print_bfs(edges, v1, v2, V))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
}
