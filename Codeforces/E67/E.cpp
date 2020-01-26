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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 2e5+10;
vector<int> adj[N] = {};
ll dp[N] = {0};
int parent[N] = {0};
int sz[N] = {0};
ll ans[N] = {0};
int n;

ll max( ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int dfs2(int u = 0,int p = -1)
{
  int cnt = 1;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      cnt += dfs2(v,u);
    }
  }

  return sz[u] = cnt;
}

ll dfs1(int u = 0,int p = -1)
{
  bool isLeaf = true;
  ll cnt = 0;
  parent[u] = p;
  for(auto v: adj[u])
  {
    if(v-p)
    {
      cnt += dfs1(v,u);   
      isLeaf = false;
    }
  }

  if(isLeaf) 
  {
    dp[u] = 1;
  }
  
  dp[u] = cnt;

  return dp[u]+sz[u];
}

void dfs3(int u = 0,int p = -1,ll val = 0)
{
  // Calculate my own answer
  ans[u] = val+dp[u] + n;
  // t(u,val,sz[u],dp[u],ans[u]);

  for(auto v : adj[u])
  {
    if(v-p) 
    {
      ll val_child = dp[u]-(dp[v]+sz[v]) +n-sz[v]+val;
      // t(v,u,dp[u],dp[v],sz[v],val);
      // t(val_child);
      dfs3(v,u,val_child);
    }
  }
}

int main()
{
  __;
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  dfs2();
  dfs1();
  dfs3();

  ll max1 = 0;

  for(int i=0;i<n;i++) max1 = max(max1,ans[i]);

  cout<<max1<<endl;
  return 0;
}

