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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

void dfs(vector<pair<int,int> > *adj,int*visited,vector<vector<int> > &dp,vector<vector<int> > &dp2,stack<int> &s,int u,int n)
{
  if(visited[u]) return;
  // visited[u] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    dp[adj[u][i].fi][1] = 0;
    s.push(adj[u][i].fi);
    int c = s.size();
    t(u,adj[u][i].fi,adj[u][i].se,c);
    for(int j=1;j<n;j++) dp[adj[u][i].fi][j+1]= min(dp[u][j]+adj[u][i].se,dp[adj[u][i].fi][j+1]);
    for(int j=1;j<=c;j++) dp2[adj[u][i].fi][j] = 1;
    dfs(adj,visited,dp,dp2,s,adj[u][i].fi,n);
    s.pop();
    // int c = dp[i]+adj[u][i].se;
    // dp[adj[u][i].fi] = min(dp[adj[u][i].fi],c);
    // if(dp[adj[u][i].fi]==c) dp2[adj[u][i].fi] = i;
    // dfs(adj,visited, dp,dp2,adj[u][i].fi);
  }
}

int main()
{
  int n,m,k;
  sc(n);sc(m);sc(k);
  vector<pair<int,int> >*adj = new vector<pair<int,int> >[n+1];
  for(int i=0;i<m;i++)
  {
    int a,b,c;
    sc(a);sc(b);sc(c);
    adj[a].pu(mp(b,c));
  }
  stack<int> s;
  vector<vector<int> > dp(n+1,vector<int>(n+1));
  vector<vector<int> > dp2(n+1,vector<int>(n+1));
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {dp[i][j] = INF;dp2[i][j] = 0;}
  for(int i=0;i<n;i++) dp[1][i] = 0;
  int*visited = (int*)calloc(n+1,sizeof(int));
  s.push(1);
  dfs(adj,visited,dp,dp2,s,1,n);
  s.pop();
  for(int i=n-1;i>=0;i--)
  {
    if(dp[n][i]<=k && dp2[n][i]) {cout<<i<<endl;break;}
  } 
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";cout<<endl;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++) cout<<dp2[i][j]<<" ";cout<<endl;
  }
  return 0;
}

