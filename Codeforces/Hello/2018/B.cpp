#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
}

int dfs(vector<int>*adj,int*visited, int u)
{
  if(visited[u]) return 0;
  visited[u] = 1;
  if(adj[u].size()==0) return 1;
  int count = 0;
  for(int i=0;i<adj[u].size();i++)
  {
    int c = dfs(adj,visited,adj[u][i]);
    if(c==-1) return -1;
    else count+=c;
  }
  if(count>=3) return 0;
  else return -1;
}

int main()
{
  int n;
  cin>>n;
  vector<int>*adj = new vector<int>[n];
  for(int i=1;i<n;i++)
  {
    int a;
    cin>>a;
    a--;
    addEdge(adj,a,i);
  }
  int* visited = (int*)calloc(n,sizeof(int));
  int d = dfs(adj,visited,0);
  if(d==-1) cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
}
