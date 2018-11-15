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

void dfs(int**dp,vector<int>*adj,int u,int parent)
{
  if(adj[u].size()==1) {dp[u][0] = 0;dp[u][1] = 1;}
  dp[u][0] = 0;dp[u][1] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]!=parent)
    {
      dfs(dp,adj,adj[u][i],u);
      dp[u][0] +=dp[adj[u][i]][1];
      dp[u][1] +=min(dp[adj[u][i]][0],dp[adj[u][i]][1]);
    }
  }
}

void dfs2(vector<int>*adj,int**dp,int u,int parent,vector<int> &v)
{
  bool boo = dp[u][0]<=dp[u][1];
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]!=parent && (dp[adj[u][i]][1]<=dp[adj[u][i]][0] || boo))
    {
      v.pu(adj[u][i]);
      dfs2(adj,dp,adj[u][i],u,v);
    }
  }
}

int main()
{
  int n;
  sc(n);
  vector<int>*adj = new vector<int>[n];
  int*memo = new int[n];
  int**dp = new int*[n];
  for(int i=0;i<n;i++) {dp[i] = new int[2];}
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    addEdge(adj,a,b);
    memo[i] = 2;
  }
  dfs(dp,adj,0,-1);
  printf("%d\n",min(dp[0][0],dp[0][1]));
  vector<int> v;
  dfs2(adj,dp,0,-1,v);
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  for(int i=0;i<n;i++){for(int j=0;j<2;j++) cout<<dp[i][j]<<" ";cout<<endl;}
  return 0;
}
