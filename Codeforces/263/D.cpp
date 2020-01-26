/*
Rathin Bhargava
IIIT Bangalore

*/
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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

const int N = 1e5+10;

vector<int> adj[N];
vector<vector<ll> > dp(N,vector<ll>(2));
vector<int> col(N);
vector<bool> flag(N);

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

bool dfs(int u,int p)
{
  bool a = false;
  for(auto v : adj[u]) if(v-p) a |= dfs(v,u);
  flag[u] = a;
  if(col[u]==0) // Red
  {
    ll prod = 1;
    dp[u][0] = 1;
    for(auto v : adj[u]) 
    {
      if(v-p)
      {
        ll a = 0;
        if(flag[v]) a = dp[v][0]+1;
        else flag[v] = dp[v][0];
        prod*=a;
      }
    }
    for(auto v : adj[u])
    {
      if(v-p)
      {
        // For calculating black
        ll temp = dp[v][1]*prod;
        temp%=MOD;
        if(flag[v]) temp*=power(dp[v][0]+1,MOD-2,MOD);
        else temp*=power(dp[v][0],MOD-2,MOD);
        temp%=MOD;
        dp[u][1]+=temp;
        dp[u][1]%=MOD;

        // For red
        dp[u][0]*=(dp[v][0]+1);
        dp[u][0]%=MOD;
      }
    }
  }
  else
  {
    flag[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(auto v : adj[u]) 
    {
      if(v-p) 
      {
        if(flag[v]) dp[u][1]*=(dp[v][0]+1);
        else dp[u][1]*=dp[v][0];
        dp[u][1]%=MOD;
      }
    }
  }
  return flag[u];
}

int main()
{
  __;
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    int a;
    cin>>a;
    adj[a].pu(i+1);
    adj[i+1].pu(a);
  }

  for(int i=0;i<n;i++) cin>>col[i];
  dfs(0,-1);
  cout<<dp[0][1]<<endl;

  for(int i=0;i<n;i++) t(i,dp[i][0],dp[i][1]);
  return 0;
}

