#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<int> *adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int bfs(vector<int> *adj, int u,int *visited)
{
  queue<int> q;
  q.push(u);
  visited[u] = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      // cout<<"u: "<<u<<" i: "<<i<<endl;
      if(visited[adj[u][i]]==-1) {q.push(adj[u][i]);visited[adj[u][i]] = (visited[u]+1)%2;}
      else if(visited[adj[u][i]]==visited[u]) return 0;
    }
  }
  return 1;
}

int main()
{
  int t;
  cin>>t;
  for(int k=1;k<=t;k++)
  {
    int n,q;
    cin>>n>>q;
    vector<int> *adj = new vector<int>[n];
    for(int h=0;h<q;h++)
    {
      int a,b;
      cin>>a>>b;
      a-=1;b-=1;
      addEdge(adj,a,b);
    }
    // for(int i=0;i<n;i++)
    // {
    //   cout<<i<<": ";
    //   for(int j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" ";cout<<endl;
    // }
    int* visited = new int[n];
    for(int i=0;i<n;i++) visited[i] = -1;
    int c = 0;
    for(int i=0;i<n;i++)
    {
      if(visited[i]==-1) c = bfs(adj,i,visited);
      if(c==0) break;
    }
    // for(int i=0;i<n;i++) cout<<visited[i]<<" "; cout<<endl;
    cout<<"Scenario #"<<k<<":"<<endl;
    if(c==0) cout<<"Suspicious bugs found!"<<endl;
    else cout<<"No suspicious bugs found!"<<endl;
  }
  return 0;
}
