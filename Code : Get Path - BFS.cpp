# C_N_Graphs1
#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
void print_dfs(bool** edges, int v1, int v2, int n, bool* visited)
{


	cout << v1 << ",";
	visited[v1] = true;
	if (v1 == v2)
	{
		//v.push_back(v2);

	}
	for (int i = 0; i < n; i++)
	{
		if (i == v1)
		{
			continue;
		}
		if (edges[v1][i])
		{
			if (visited[i])
			{
				continue;
			}
			//v.push_back(i);

			print_dfs(edges, i, v2, n, visited);
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


		//cout << cur_v << " ";

		pending_v.pop();
		int i;
		for ( i = 0; i < V; i++)
		{
			if (cur_v == i)
			{
				continue;
			}
			if (edges[cur_v][i] == true and visited[i] == false)
			{
				m[i] = cur_v;
				pending_v.push(i);
				visited[i] = true;
				if (i == dest)
					return true;
			}
		}

	}
	return false;




	/*for (auto x : m)
	{
		cout << x.first << "," << x.second << endl;
	}*/
	//return false;
	//delete [] visited;
	/*map<int, int>::reverse_iterator it;
	for (it = m.rbegin(); it != m.rend(); it++) {
		cout << it->second  << " ";

	}
	cout << src;*/
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
	bool* visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}

	int v1, v2;
	cin >> v1 >> v2;
	if (print_bfs(edges, v1, v2, V))
	{
		int temp = v2;
		while (temp != v1)
		{
			cout << temp << " ";
			temp = m[temp];
		}
		cout << v1;
	}




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

}
