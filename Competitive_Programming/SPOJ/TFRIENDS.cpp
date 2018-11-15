#include<bits/stdc++.h>
#include<cstdio>
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

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
}

void bfs(vector<int>*adj,int*visited,int u,char**m)
{
  queue<int> q;
  q.push(u);
  visited[u] = 1;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      if(!visited[adj[u][i]]) {visited[adj[u][i]] = 1;q.push(adj[u][i]);}
    }
  }
}

void dfs(vector<int>*adj,int*visited,int u,stack<int> &s,int key)
{
  if(visited[u]) return;
  visited[u] = key;
  // cout<<"U: "<<u<<endl;
  for(int i=0;i<adj[u].size();i++) if(!visited[adj[u][i]])dfs(adj,visited,adj[u][i],s,key);
  // cout<<"push: "<<u<<endl;
  s.push(u);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n;
    scanf("%d",&n);
    char dummy;
    scanf("%c",&dummy);
    char**m = (char**)calloc(n,sizeof(char*));
    for(int i=0;i<n;i++) m[i] = (char*)calloc(n,sizeof(char));
    for(int i=0;i<n;i++)
    {
      // for(int j=0;j<n;j++)
      // {
      //   scanf("%c",&m[i][j]);
      // }
      // scanf("%c",&dummy);
      char* temp = (char*)calloc(n,sizeof(char));
      scanf("%s",temp);
      m[i] = temp;
      scanf("%c",&dummy);
    }
    vector<int>*adj = new vector<int>[n];
    vector<int>*adj1 = new vector<int>[n];
    vector<int>*adj2 = new vector<int>[n];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++) if(m[i][j]=='Y') addEdge(adj,i,j);
    }
    // print(adj,n);
    for(int i=0;i<n;i++)
    {
      int* visited = (int*)calloc(n,sizeof(int));
      bfs(adj,visited,i,m);
      for(int j=0;j<n;j++)
      {
        if(visited[j] && j!=i) addEdge(adj1,i,j);
      }
    }
    // print(adj1,n);
    stack<int> s;
    int* visited = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++) if(!visited[i]) dfs(adj1,visited,i,s,1);

    // Rverse
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<adj1[i].size();j++) adj2[adj1[i][j]].pu(i);
    }
    // print(adj2,n);
    for(int i=0;i<n;i++) visited[i] = 0;
    int key  = 1;
    while(!s.empty())
    {
      int u = s.top();
      if(!visited[u])
      {
        // cout<<"u: "<<u<<endl;
        dfs(adj2,visited,u,s,key);
        key++;
      }
      s.pop();
    }
    printf("%d\n",key-1);
  }
}
