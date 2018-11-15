#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int counter = 0;
void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int dfs(vector<int>*adj,int*visited,int u)
{
  if(visited[u]) return 0;
  visited[u] = 1;
  int boo = 0,count = 0;
  for(int i=0;i<adj[u].size();i++)
  {
    if(!boo && !visited[adj[u][i]]) boo = 1;
    count+=dfs(adj,visited,adj[u][i]);
  }
  if(!boo || count==0) return 1;
  else if(count%2==0) return 1;
  else if(count%2==1) {counter++;return 0;}
}

int main()
{
  int n,q;
  cin>>n>>q;
  vector<int>*adj = new vector<int>[n];
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    addEdge(adj,a,b);
  }
  int* visited = (int*)calloc(n,sizeof(int));
  dfs(adj,visited,0);
  cout<<counter-1<<endl;
  return 0;
}
