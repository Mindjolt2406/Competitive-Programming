#include<bits/stdc++.h>
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
using namespace std;

// void prlong long int(vector<long long int> *adj,long long int n)
// {
//   for(long long int i=0;i<n;i++)
//   {
//     cout<<i<<": ";
//     for(long long int j=0;j<adj[i].size();j++)cout<<adj[i][j]<<" ";cout<<endl;
//   }
// }

void addEdge(vector<long long int>*adj,long long int u,long long int v)
{
  adj[u].pu(v);
}

long long int dfs(vector<long long int>*adj,long long int*visited,long long int*cost, long long int u,long long int key,stack<long long int> &s)
{
  if(visited[u]) return INF;
  visited[u] = key;
  long long int min1 = cost[u];
  // cout<<"u: "<<u<<" min1: "<<min1<<endl;
  for(long long int i=0;i<adj[u].size();i++) {min1 = min(min1,dfs(adj,visited,cost,adj[u][i],key,s));}
  s.push(u);
  return min1;
}

int main()
{
  long long int n;
  cin>>n;
  long long int cost[n];
  vector<long long int>*adj = new vector<long long int>[n];
  for(long long int i=0;i<n;i++) cin>>cost[i];
  long long int q;
  cin>>q;
  for(long long int h=0;h<q;h++)
  {
    long long int a,b;
    cin>>a>>b;
    a--;b--;
    addEdge(adj,a,b);
  }
  // prlong long int(adj,n);
  long long int*visited = (long long int*)calloc(n,sizeof(long long int));
  stack<long long int> s;
  long long int count = 0,key = 1;
  for(long long int i=0;i<n;i++)
  {
    if(!visited[i]) {dfs(adj,visited,cost,i,key,s);}
  }
  //Reverse the graph
  vector<long long int>*adj1 = new vector<long long int>[n];
  for(long long int i=0;i<n;i++)
  {
    for(long long int j=0;j<adj[i].size();j++)
    {
      addEdge(adj1,adj[i][j],i);
    }
  }
  // prlong long int(adj1,n);
  long long int prod = 1,c = 0;
  long long int* key1 = (long long int*)calloc(n+1,sizeof(long long int));
  long long int* product = (long long int*)calloc(n+1,sizeof(long long int));
  for(long long int i=0;i<n;i++) visited[i] = 0;
  while(!s.empty())
  {
    long long int i = s.top();
    if(!visited[i])
    {
      // cout<<"i: "<<i<<endl;
      c=dfs(adj1,visited,cost,i,key,s);
      // cout<<"c: "<<c<<" key: "<<key<<endl;
      key1[key] = c;
      count+=c;
      key++;
    }
    s.pop();
  }
  for(long long int i=0;i<n;i++)
  {
    if(cost[i]==key1[visited[i]])product[visited[i]]++;
  }
  // for(int i=1;i<key;i++) cout<<product[i]<<" ";cout<<endl;
  for(long long int i=1;i<key;i++)
  {
    if(product[i])prod*=product[i];
    prod%=MOD;
  }
  cout<<count<<" "<<prod<<endl;
  return 0;
}
