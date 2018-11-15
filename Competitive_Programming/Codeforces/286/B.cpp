#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int dfs(vector<int> *adj,int* visited,int u,int v)
{
  if(visited[u]) return 0;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]==v) return 1;
    else if(dfs(adj,visited,adj[u][i],v)==1) return 1;
  }
  return 0;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>**adj = new vector<int>*[m];
  for(int i=0;i<m;i++) adj[i] = new vector<int>[n];
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;c--;
    addEdge(adj[c],a,b);
  }
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    int count = 0;
    for(int i=0;i<m;i++)
    {
      int* visited = (int*)calloc(n,sizeof(int));
      count+=dfs(adj[i],visited,a,b);
    }
    cout<<count<<endl;
  }
  return 0;
}
