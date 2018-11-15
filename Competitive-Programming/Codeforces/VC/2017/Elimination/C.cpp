#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void print(vector<int> *adj,int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<i<<": ";
    for(int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";cout<<endl;
  }
}

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

void dfs(vector<int>*adj,int* visited,int u,int key)
{
  if(visited[u]) return;
  visited[u] = key;
  for(int i=0;i<adj[u].size();i++) dfs(adj,visited,adj[u][i],key);
}

int main()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  vector<int>*adj = new vector<int>[n];
  for(int i=0;i<n;i++)addEdge(adj,i,l[i]-1);
  // print(adj,n);
  int* visited = (int*)calloc(n,sizeof(int));
  int key = 1;
  for(int i=0;i<n;i++)
  {
    if(visited[i]==0) {dfs(adj,visited,i,key);key++;}
  }
  cout<<key-1<<endl;
  return 0;
}
