// Checked the testcase for when the cycle is a loop
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;
void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
}

pair<int,int> dfs(vector<int>*adj,int u,int parent,int*visited,int*cost,int key)
{
  if(visited[u]!=0) return mp(-1,0);
  visited[u] = key;
  pair<int,int> p = mp(-1,0);
  for(int i=0;i<adj[i].size();i++)
  {
    if(visited[adj[u][i]]==key && adj[u][i]!=u) {return mp(adj[u][i],cost[u]);}
    else if(visited[adj[u][i]]==key) {return mp(-1,cost[u]);}
    else if(visited[adj[u][i]]!=key)
    {
      p = dfs(adj,adj[u][i],u,visited,cost,key);
      if(p.first==-1) continue;
      else if(p.first==u) {p.first = -1;p.second = min(p.second,cost[u]);return p;}
      else
      {
        p.second = min(p.second,cost[u]);
      }
    }
  }
  return p;
}

int main()
{
  int n;
  sc(n);
  vector<int>*adj = new vector<int>[n];
  int* cost = new int[n];
  int* edge = new int[n];
  for(int i=0;i<n;i++) sc(cost[i]);
  for(int i=0;i<n;i++) {sc(edge[i]);edge[i]--;addEdge(adj,i,edge[i]);}
  int*visited = (int*)calloc(n,sizeof(int));
  ll count = 0;
  int key = 1;
  for(int i=0;i<n;i++)
  {
    if(visited[i]==0)
    {
      count+=dfs(adj,i,-1,visited,cost,key).second;
      key++;
    }
  }
  cout<<count<<endl;
  return 0;
}
