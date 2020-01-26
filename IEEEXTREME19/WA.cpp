/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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

const int N = 1e5;
int n;
vector<pair<int,ll> > adj[N] = {};
vector<int> sz(N);
vector<ll> ans1(N), ans2(N);
vector<pair<int,ll> > par(N);

void dfs1(int u = 0,int p = -1)
{
  bool isLeaf = false;
  sz[u] = 1;
  
  for(auto temp : adj[u])
  {
    int v = temp.fi;
    ll w = temp.se;

    if(v-p)
    {
      dfs1(v,u);
      par[v] = mp(u,w);
      sz[u] += sz[v];
      ans1[u] += (1LL*w*sz[v] + ans1[v]);
      ans1[u] %= MOD;
    }
  }
}

void dfs2(int u = 0, int p = -1)
{
  t(u);
  ans2[u] = ans1[u];
  if(p+1)
  {
    ans2[u] += ans1[p] - (ans1[u] + sz[u]*par[u].se)%MOD + (par[u].se*(n-sz[u]))%MOD + MOD;
    ans2[u] %= MOD;
  }

  for(auto temp : adj[u])
  {
    int v = temp.fi;
    if(v-p)
    {
      dfs2(v,u);
    }
  }
}

int main()
{
  __;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    adj[a].pu(mp(b,c));
    adj[b].pu(mp(a,c));
  }

  dfs1();
  for(int i=0;i<n;i++) t(par[i],i);
  dfs2();
  for(int i=0;i<n;i++) t(i,ans2[i]);

  ll sum1 = 0;
  for(int i=0;i<n;i++) {sum1 += ans2[i]; sum1 %= MOD;}

  cout << sum1 << endl;
  return 0;
}

