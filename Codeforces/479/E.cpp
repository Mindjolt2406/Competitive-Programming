#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int* visited;
vector < int > *adj;

void addEdge(int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

void dfs(int u,int parent,int key)
{
  if(visited[u]!=0) return ;
  visited[u] = key;
  for(int i=0;i<adj[u].size();i++)
  {
    dfs(adj[u][i],u,key);
  }
}

int main()
{
  int n,q;
  cin>>n>>q;
  // cout<<n<<" "<<q<<endl;
  adj = new vector <int> [n];
  map <int,int> d;
  map <int,int> :: iterator it;
  // cout<<"Okay"<<endl;
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    a-=1;b-=1;
    addEdge(a,b);
    // cout<<"Okay"<<endl;
  }
  // cout<<"Entered"<<endl;
  visited = (int*)calloc(n,sizeof(int));
  int key = 1,count = 0;
  for(int i=0;i<n;i++)
  {
    // for(int i=0;i<n;i++) cout<<visited[i]<<" ";
    // cout<<endl;
    if(visited[i]==0) {dfs(i,i,key);key++;}
    else continue;
  }
  for(int i=0;i<n;i++) d[visited[i]] = 1;
  for(int i=0;i<n;i++)
  {
    if(adj[i].size()==2 && d[visited[i]]==1)continue;
    else d[visited[i]] = 0;
  }
  for(it = d.begin();it!=d.end();it++) if (it->second) count++;
  // for(int i=0;i<n;i++) cout<<visited[i]<<" ";
  // cout<<endl;
  cout<<count<<endl;
  return 0;
}
