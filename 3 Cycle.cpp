# C_N_Graphs1
#include<bits/stdc++.h>
using namespace std;
int main()
{

    int V, e;
    cin >> V >> e;
    bool a[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            a[i][j] = false;

        }
    }

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = true;
        a[y][x] = true;
    }
    int c = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (a[i][j])
            {
                for (int k = 0; k < V; k++)
                {
                    if (k == j or k == i)
                    {
                        continue;
                    }
                    if (a[j][k])
                    {
                        if (a[k][i])
                        {
                            c++;
                        }
                    }
                }
            }
        }
    }
    cout << c / 6;
}
