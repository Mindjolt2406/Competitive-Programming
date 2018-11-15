#include<bits/stdc++.h>
#define mp make_pair
#define pu push_back
using namespace std;

void addEdge(vector<int> *adj, int u, int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

pair<int,int> dfs(vector< int> *adj, int *visited,int u)
{
  if(visited[u]!=0) return mp(-1,-1);
  visited[u] = 1;
  // cout<<"u: "<<u<<endl;
  vector< pair<int,int> > v;
  for(int i=0;i<adj[u].size();i++)
  {
    v.pu(dfs(adj,visited,adj[u][i]));
  }
  int max1 = -1;
  for(int i=0;i<v.size();i++) max1 = max(max1,v[i].first);
  if(max1==-1) return mp(0,u);
  pair <int,int> p;
  for(int i=0;i<v.size();i++) if(v[i].first==max1) {p=v[i];break;}
  return mp(p.first+1,p.second);
}

int main()
{
  int n;
  cin>>n;
  vector <int> *adj = new vector<int>[n];
  for(int h=0;h<n-1;h++)
  {
    int a,b;
    cin>>a>>b;
    a-=1;b-=1;
    addEdge(adj,a,b);
  }
  int* visited = (int*)calloc(n,sizeof(int));
  pair<int,int> p = dfs(adj,visited,0);
  for(int i=0;i<n;i++) visited[i] = 0;
  pair<int,int> p1 = dfs(adj,visited,p.second);
  cout<<p1.first<<endl;
}
