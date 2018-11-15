#include<bits/stdc++.h>
#define pu push_back
#define mp make_pair
using namespace std;

void addEdge(vector<int> *adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int dfs(vector<int> *adj,int u,int *cat,int k, int m,int*visited)
{
  if(visited[u]) return 0;
  visited[u] = 1;
  if(cat[u]) k--;
  else k = m;
  // cout<<"u: "<<u<<" k: "<<k<<endl;
  if(k<0) return 0;
  int count = 0,counter = 0;
  for(int i=0;i<adj[u].size();i++) {counter+=visited[adj[u][i]];count+=dfs(adj,adj[u][i],cat,k,m,visited);}
  // cout<<"u: "<<u<<" count: "<<count<<" counter: "<<counter<<endl;
  if(counter==adj[u].size()) return 1; // Leaf node
  return count;
}

int main()
{
  int n,k;
  cin>>n>>k;
  int cat[n];
  for(int i=0;i<n;i++) cin>>cat[i];
  vector<int>*adj = new vector<int>[n];
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    addEdge(adj,a,b);
  }
  int* visited = (int*)calloc(n,sizeof(int));
  int c = dfs(adj,0,cat,k,k,visited);
  cout<<c<<endl;
}
