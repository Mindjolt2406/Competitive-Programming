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
  adj[v].pu(u);
}

ll min(ll x,ll y)
{
  if(x<y) return x;
  return y;
}

ll dfs(vector<int>*adj,int*visited,int*l, int u,int parent,int root)
{
  if(visited[u]) return -1;
  // cout<<"u: "<<u<<" l[u]: "<<l[u]<<endl;
  // cout<<"u: "<<u<<" l[0]: "<<l[0]<<endl;
  vector<ll> v;
  visited[u] = 1;
  if(adj[u].size()==1 && root!=u) {l[u]--;return 1;}
  else if(adj[u].size()==0 && root==u) {l[u]--;return 0;}
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]!=parent) v.pu(dfs(adj,visited,l,adj[u][i],u,root));
  }
  ll count;
  if(u!=root)count = 1;
  else count = 0;
  if(u!=root) l[u]--;
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());
  for(int i=0;i<min((int)l[u],(int)v.size());i++) count+=v[i];
  count+=min((int)l[u],(int)v.size());
  l[u]-=min((int)l[u],(int)v.size());
  for(int i=0;i<adj[u].size();i++)
  {
    if(l[u]>=1 && l[adj[u][i]] && adj[u][i]!=parent)
    {
      ll c = min(l[u],l[adj[u][i]]);
      count+=2*c;
      l[u]-=c;l[adj[u][i]]-=c;
    }
  }
  return count;
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  vector<int>*adj = new vector<int>[n];
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    addEdge(adj,a,b);
  }
  int k;sc(k);k--;
  int*visited = (int*)calloc(n,sizeof(int));
  cout<<dfs(adj,visited,l,k,-1,k)<<endl;
  return 0;
}
