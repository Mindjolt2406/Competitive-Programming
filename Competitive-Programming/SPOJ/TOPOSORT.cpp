#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
}

int dfs(vector<int>*adj,int* visited,int u, stack<int> &s,int key)
{
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    // if(visited[adj[u][i]] && parent[u]==adj[u][i]) return 1;
    if(visited[adj[u][i]] == 1) {return 1;}

    int c = 0;
    if(!visited[adj[u][i]]) c = dfs(adj,visited,adj[u][i],s,key);
    if(c==1) return 1;
  }
  visited[u] = 2;
  s.push(u);
  return 0;
}

int main()
{
  int n,q;
  cin >> n >> q;
  vector<int>*adj = new vector<int>[n];
  int* visited = (int*)calloc(n,sizeof(int));
  stack<int> s;
  for(int h=0;h<q;h++)
  {
    int a,b;
    scanf("%d %d",&a,&b);
    a--;b--;
    addEdge(adj,a,b);
  }
  for(int i=0;i<n;i++)
  {
    sort(adj[i].begin(),adj[i].end());
    reverse(adj[i].begin(),adj[i].end());
  }
  int key = 1;
  for(int i=n-1;i>=0;i--)
  {
    if(!visited[i])
    {
      int c = dfs(adj,visited,i,s,key);
      if(c==1) {cout<<"Sandro fails."<<endl;return 0;}
    }
  }
  if(s.size()!=n) {cout<<"Sandro fails."<<endl;return 0;}
  while(!s.empty())
  {
    int u = s.top();
    s.pop();
    printf("%d ",u+1);
  }
  printf("\n");
  return 0;
}
