#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int> *adj,int u, int v)
{
  adj[u].pu(v);
}

void dfs(vector<int> *adj,int* visited,int u)
{
  if(visited[u]) return;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++) dfs(adj,visited,adj[u][i]);
}

int main()
{
  int n,k;
  cin>>n>>k;
  k-=1;
  vector<int>*adj = new vector<int> [n];
  int l[n];
  for(int i=0;i<n-1;i++) cin>>l[i];
  for(int i=0;i<n-1;i++) addEdge(adj,i,i+l[i]);
  int* visited = (int*)calloc(n,sizeof(int));
  dfs(adj,visited,0);
  if(visited[k]) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
