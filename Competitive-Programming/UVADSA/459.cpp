#include<bits/stdc++.h>
#define pu push_back
using namespace std;

vector<int> *adj;

void addEdge(int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

void bfs(vector <int>adj[],int* visited, int n,int index)
{
  queue<int> q;
  q.push(index);
  // int n = adj.size();
  while(!q.empty())
  {
    int u = q.front();
    // cout<<u<<" ";
    visited[u] = 1;
    q.pop();
    for(int i=0;i<adj[u].size();i++)
    {
      if(visited[adj[u][i]]==0){q.push(adj[u][i]);visited[adj[u][i]] = 1;}
    }
  }
}

int connected(int n)
{
  int* visited = (int*)calloc(n,sizeof(int));
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if (visited[i]==1)continue;
    else {bfs(adj,visited,n,i);count++;}
  }
  return count;
}

int main()
{
  int t;
  cin>>t;
  // string k;
  // cin>>k;
  vector<int> v;
  while(t--)
  {
    char c;
    cin>>c;
    int n = c-65+1;
    string s = "1";
    cin.ignore(256,'\n');
    adj = new vector <int>[n];
    while(!s.empty())
    {
      getline(cin,s);
      if(s.empty())break;
      addEdge(s[0]-65,s[1]-65);
    }
    // int n,q;
    // cin>>n>>q;
    // for(int i=0;i<q;i++)
    // {
    //   int a,b;
    //   cin>>a>>b;
    //   addEdge(a,b);
    // }
    cout<<connected(n)<<'\n'<<'\n';
    // cout<<connected(n)<<endl;
    // cout<<endl;
  }
  return 0;
}
