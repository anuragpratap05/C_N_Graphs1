# C_N_Graphs1
#include<bits/stdc++.h>

int coding(vector<vector<char>> &graph,int **visited,int n,int m,int i,int j,string s1)
{
    bool ans;
    if(s1.length()==0)
        return 1;
    if(i<0 || i>=n || j<0 || j>=m || visited[i][j] || graph[i][j]!=s1[0])
        return 0;
    visited[i][j]=true;
    int ans1=coding(graph,visited,n,m,i-1,j,s1.substr(1));
    int ans2=coding(graph,visited,n,m,i-1,j+1,s1.substr(1));
    int ans3=coding(graph,visited,n,m,i,j+1,s1.substr(1));
    int ans4=coding(graph,visited,n,m,i+1,j+1,s1.substr(1));
    int ans5=coding(graph,visited,n,m,i+1,j,s1.substr(1));
    int ans6=coding(graph,visited,n,m,i+1,j-1,s1.substr(1));
    int ans7=coding(graph,visited,n,m,i,j-1,s1.substr(1));
    int ans8=coding(graph,visited,n,m,i-1,j-1,s1.substr(1));
    if(ans1 || ans2 || ans3 || ans4 ||ans5 || ans6 || ans7 ||ans8)
    {
        return 1;
    }
    visited[i][j]=0;
    return 0;
}


bool hasPath(vector<vector<char>> &board, int N, int M) {
    // Write your code here.
    string s1="CODINGNINJA";
    int **visited=new int*[N];
    for(int i=0;i<N;i++)
    {
        visited[i]=new int[M];
        for(int j=0;j<M;j++)
            visited[i][j]=0;
    }
    for(int i=0;i<N;i++)
    {
        int ans=0;
        for(int j=0;j<M;j++)
        {
            if(!visited[i][j] && board[i][j]=='C')
            {
                ans=coding(board,visited,N,M,i,j,s1);
                if(ans==1)
                    return 1;
            }
        }
    }
    return 0;
}
