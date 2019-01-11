#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
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

ll total;

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

void dfs(vector<pair<int,ll> > *adj,ll **dp,int u, int n,int* in,int *counter)
{
  // for(int u=0;u<n;u++)
  // {
    counter[u]++;
    // t(in[u],counter[u],u);
    // if(adj[u].size()==0) return;
    if(in[u]!=counter[u] && u!=0) return;
    for(int i=0;i<adj[u].size();i++)
    {
      for(int j=0;j<n;j++)
      {
        dp[adj[u][i].fi][j+1] = min(dp[adj[u][i].fi][j+1], dp[u][j] + adj[u][i].se);
        if(dp[adj[u][i].fi][j+1]>total) dp[adj[u][i].fi][j+1] = INF;
      }
      dfs(adj,dp,adj[u][i].fi,n,in,counter);
    }
  // }
}

void dfs2(vector<pair<int,ll> > *adj,int*visited, int u)
{
  if(visited[u]) return;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++) dfs2(adj,visited,adj[u][i].fi);
}

int main()
{
  int n,m;
  sc(n);sc(m); scll(total);
  vector<pair<int,ll> >*adj = new vector<pair<int,ll> >[n];
  vector<pair<int,ll> >*parent = new vector<pair<int,ll> >[n];
  int* in = (int*)calloc(n+1,sizeof(int));
  int* counter = (int*)calloc(n+1,sizeof(int));
  for(int i=0;i<m;i++)
  { 
    int a,b;
    ll w;
    sc(a);sc(b);
    a--;b--;
    scll(w);
    adj[a].pu(mp(b,w));
    in[b]++;
    parent[b].pu(mp(a,w));
  }
  ll**dp = new ll*[n+1];
  for(int i=0;i<=n;i++) dp[i] = new ll[n+1];
  for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j] = INF;
  dp[0][0] = 0;
  counter[0] = -1;
  int*visited = (int*)calloc(n,sizeof(int));
  dfs2(adj,visited,0);
  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      for(int j=0;j<adj[i].size();j++)
      {
        in[adj[i][j].fi]--;
      }
    }
  }
  dfs(adj,dp,0,n,in,counter);

  ll min1 = INF,min2 =-1;
  for(int i=0;i<n;i++) 
  {
    if(total>=dp[n-1][i])
    {
      min1 = dp[n-1][i];
      min2 = i;
    }
  }
  cout<<min2+1<<endl;

  // for(int i=0;i<n;i++) 
  // {
  //   for(int j=0;j<n;j++) 
  //   {
  //     if(dp[i][j]!=INF) cout<<dp[i][j]<<" ";
  //     else cout<<"INF ";
  //   }
  //   cout<<endl;
  // }
  int a = n-1,b = min2;
  vi v;
  v.pu(a);
  while(a!=0)
  {
    // t(a);
    for(int i=0;i<parent[a].size();i++)
    {
      if(dp[parent[a][i].fi][b-1]!=INF && parent[a][i].se == abs(dp[parent[a][i].fi][b-1]-dp[a][b])) 
      {
        a = parent[a][i].fi;
        b--;
        v.pu(a);
        break;
      }
    }
  }

  reverse(v.begin(),v.end());
  for(int i=0;i<v.size();i++) printf("%d ",v[i]+1);printf("\n");
  
  return 0;
}

