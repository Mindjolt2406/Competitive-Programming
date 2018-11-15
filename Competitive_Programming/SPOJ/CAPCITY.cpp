#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int>*adj,int a,int b)
{
  adj[a].pu(b);
}

void dfs(vector<int>*adj,int* visited, int u,stack<int>&s,int key)
{
  if(visited[u]) return;
  visited[u] = key;
  for(int i=0;i<adj[u].size();i++)
  {
    dfs(adj,visited,adj[u][i],s,key);
  }
  s.push(u);
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>*adj = new vector<int>[n];
  vector<int>*rev = new vector<int>[n];
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    addEdge(adj,a,b);
  }
  stack<int> s;
  int* visited = (int*)calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    if(!visited[i]) dfs(adj,visited,i,s,1);
  }
  for(int i=0;i<n;i++) visited[i] = 0;
  // Reverse the graph
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<adj[i].size();j++) rev[adj[i][j]].pu(i);
  }
  int c = -1;
  int* visited1 = (int*)calloc(n,sizeof(int));
  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      dfs(rev,visited1,i,s,1);
    }
    int sum1 = 0;
    for(int i=0;i<n;i++){sum1+=visited1[i];if(visited1[i]==1) visited[i] = 1;visited1[i] = 0;}
    if(sum1==n) {c = i;break;}
  }
  for(int i=0;i<n;i++) visited[i] = 0;
  stack<int>s1;
  int key = 1;
  while(!s.empty())
  {
    int u = s.top();
    s.pop();
    if(!visited[u]) {dfs(adj,visited,u,s1,key);key++;}
  }
  int sum1 = 0;
  int d = visited[c];
  vector<int> v;
  for(int i=0;i<n;i++) if(visited[i]==d) {v.pu(i);sum1++;}
  cout<<sum1<<endl;
  for(int i=0;i<v.size();i++)cout<<v[i]+1<<" ";
  cout<<endl;
}
