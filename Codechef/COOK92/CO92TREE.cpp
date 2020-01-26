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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

const int N = 100100;
int p[N], sz[N], parent[N], col[N];
vector<int> adj[N] = {};

void dfs(int u = 1, int par = -1)
{
  parent[u] = par;
  for(auto v : adj[u])
  {
    if(v-par) dfs(v,u);
  }
}

void create(int x){
	p[x] = x;
	sz[x] = 1;
	return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

int merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return sz[x];
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return sz[x];
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    // Create DSU, no need to uncreate it
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
      int a,b;
      cin >> a >> b;
      adj[a].pu(b);
      adj[b].pu(a);
    }

    dfs();

    ll ans = n;
    for(ll mask=1;mask<=n;mask++)
    {
      vector<int> supermask;
      for(int i=mask;i<=n;i=mask|(i+1)) supermask.pu(i);
      // t(mask,supermask);
      for(int i=0;i<supermask.size();i++) create(supermask[i]);

      for(int i=0;i<supermask.size();i++) col[supermask[i]] = 1;

      for(int i=0;i<supermask.size();i++)
      {
        int u = supermask[i];
        int par = parent[u];
        if(par+1 && col[par])
        {
          int temp = merge(u,par);
          ans = max(ans,temp*mask);
        }
      }

      for(int i=0;i<supermask.size();i++) col[supermask[i]] = 0;
      for(int i=0;i<supermask.size();i++) create(supermask[i]);
    }

    cout << ans << "\n";

    for(int i=1;i<=n;i++) adj[i].clear();
    // for(int i=1;i<=n;i++) parent[i] = 0;
    memset(parent,0,sizeof(int));
  } 
  return 0;
}

