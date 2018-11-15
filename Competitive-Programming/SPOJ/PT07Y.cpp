#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int> *adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

void dfs(vector<int> *adj, int *visited, int u)
{
  if(visited[u]) return;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++) dfs(adj,visited,adj[u][i]);
}

int main()
{
  int n,q;
  cin>>n>>q;
  vector<int>* adj = new vector<int>[n];
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    a-=1;b-=1;
    addEdge(adj,a,b);
  }
  if(q!=n-1) cout<<"NO"<<endl;
  else
  {
    int* visited = (int*)calloc(n,sizeof(int));
    dfs(adj,visited,0);
    int count = 0;
    for(int i=0;i<n;i++) if(visited[i]) count++;
    if(count==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
