#include<bits/stdc++.h>
#define pu push_back
using namespace std;

void addEdge(vector<long long int>*adj,long long int u,long long int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

long long int dfs(vector<long long int>*adj,long long int*visited,long long int u,long long int key)
{
  if(visited[u]) return 0;
  visited[u] = key;
  long long int count = 1;
  for(long long int i=0;i<adj[u].size();i++)
  {
    count+=dfs(adj,visited,adj[u][i],key);
  }
  return count;
}

int main()
{
  long long int n,q;
  cin>>n>>q;
  vector<long long int>*adj = new vector<long long int>[n];
  for(long long int h=0;h<q;h++)
  {
    long long int a,b;
    cin>>a>>b;
    addEdge(adj,a,b);
  }
  long long int*visited = (long long int*)calloc(n,sizeof(long long int));
  long long int key = 1;
  for(long long int i=0;i<n;i++)
  {
    if(!visited[i]) {dfs(adj,visited,i,key);key++;}
  }
  long long int*l = (long long int*)calloc(key,sizeof(long long int));
  for(long long int i=0;i<n;i++) l[visited[i]]++;
  // for(long long int i=1;i<key;i++) cout<<l[i]<<" ";cout<<endl;
  long long int sum1 = 0;
  for(long long int i=1;i<key;i++)sum1+=l[i];
  // cout<<"sum1: "<<sum1<<endl;
  long long int sum2 = 0;
  for(long long int i=1;i<key;i++) sum2+=(sum1-l[i])*l[i];
  cout<<sum2/2<<endl;
}
