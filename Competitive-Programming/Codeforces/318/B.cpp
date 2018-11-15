#include<bits/stdc++.h>
#define pu push_back
#define INF 1000000001
#define mp make_pair
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

void dfs(vector<int>*adj,int*visited,int u, int key)
{
  if(visited[u]) return;
  visited[u] = key;
  for(int i=0;i<adj[u].size();i++) dfs(adj,visited,adj[u][i],key);
}

int main()
{
  int n,q;
  cin>>n>>q;
  vector<int>*adj = new vector<int>[n];
  vector<int>*adj1 = new vector<int>[n];
  int**l = new int*[n];
  for(int i=0;i<n;i++) l[i] = new int[n];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) l[i][j] = 0;
  int min1 = INF;
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    addEdge(adj,a,b);
    l[a][b] = 1;
    l[b][a] = 1;
  }
  // print(adj,n);
  int*known = (int*)calloc(n,sizeof(int));
  for(int i=0;i<n;i++) known[i] = adj[i].size();
  // for(int i=0;i<n;i++) cout<<known[i]<<" ";cout<<endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<adj[i].size();j++)
    {
      for(int k=j+1;k<adj[i].size();k++)
      {
        if(l[adj[i][j]][adj[i][k]]) adj1[i].pu(known[adj[i][j]]+known[adj[i][k]]);
      }
    }
  }
  // print(adj1,n);
  for(int i=0;i<n;i++) sort(adj1[i].begin(),adj1[i].end());
  for(int i=0;i<n;i++)
  {
    if(!adj1[i].size()) continue;
    else min1 = min(min1,known[i]+adj1[i][0]);
  }
  if(min1!=INF) cout<<min1-6<<endl;
  else cout<<-1<<endl;
}
