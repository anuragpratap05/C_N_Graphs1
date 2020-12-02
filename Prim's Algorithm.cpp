# C_N_Graphs1
#include <bits/stdc++.h>
using namespace std;

int findMinVertex(int* weight,bool* visited,int V){
    int min_vertex=-1;
    for(int i=0;i<V;i++){
        if(!visited[i] && (min_vertex==-1 || weight[i]<weight[min_vertex]))
            min_vertex=i;
    }
    
    return min_vertex;
}

int main()
{
  int V, E;
  cin >> V >> E;
    
  int **edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    
    int v1,v2,w;
    for(int i=0;i<E;i++){
        cin>>v1>>v2>>w;
        edges[v1][v2]=w;
        edges[v2][v1]=w;
    }
    
    int* weight=new int[V];
    bool* visited=new bool[V];
    int* parent=new int[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    weight[0]=0;
    parent[0]=-1;            //it is done to select 0 as source vertex 
    
    for(int i=0;i<V;i++){
        int min_vertex=findMinVertex(weight,visited,V);
        visited[min_vertex]=true;
        
        for(int j=0;j<V;j++){
            if(!visited[j] && edges[min_vertex][j]!=0 && edges[min_vertex][j]<weight[j]){
                weight[j]=edges[min_vertex][j];
                parent[j]=min_vertex;
            }
        }
    }
    
    for(int i=1;i<V;i++){
        cout<<min(parent[i],i)<<" "<<max(parent[i],i)<<" "<<weight[i]<<endl;
    }
    
  return 0;
}
