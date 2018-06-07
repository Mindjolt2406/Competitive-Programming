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

void addEdge(vector<int> *adj,int u,int v)
{
  adj[u].pu(v);
}

int bfs(vector<int> *adj, int* visited, int u,int v)
{
  queue<int> q;
  q.push(u);
  int count = 0;
  int boo = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    // cout<<u<<" ";
    if(u==-1) {count++;boo = 0;}
    else if(u==v) return count;
    else
    {
      if(!boo){boo = 1;q.push(-1);}
      for(int i=0;i<adj[u].size();i++)
      {
        if(!visited[adj[u][i]]) {visited[adj[u][i]] = 1;q.push(adj[u][i]);}
      }
    }
  }
  return -1;
}

int main()
{
  int f,s,g,u,d;
  cin>>f>>s>>g>>u>>d;
  vector<int> *adj = new vector<int>[f+1];
  for(int i=1;i<=f;i++)
  {
    if(i+u<=f) addEdge(adj,i,i+u);
    if(i-d>=1) addEdge(adj,i,i-d);
  }
  // print(adj,f+1);
  int* visited = (int*)calloc(f+1,sizeof(int));
  int c = bfs(adj,visited,s,g);
  if(c!=-1) cout<<c<<endl;
  else cout<<"use the stairs"<<endl;
  return 0;
}
