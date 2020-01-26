/*
Rathin Bhargava
IIIT Bangalore

*/
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

const int N = 1e4+20;
vector<int> adj[N] = {};
map<pair<int,int> , pair<int,int> > edge;

vector<int> vis(N),fin(N);
vector<pair<int,int> > ans(N);
int timer = 0;

void dfs(int u = 0)
{
  // start[u] = timer;
  timer++;
  vis[u] = 1;
  for(auto v : adj[u])
  {
    if(!vis[v])
    {
      dfs(v);
    }
  }
  fin[u] = timer;
  timer++;
}

int main()
{
  __;
  int total,n;
  cin >> total >> n;
  set<string> se;
  map<pair<string,string> , pair<int,int> > d;

  for(int i=0;i<n;i++)
  {
    string derived, base, ing;
    cin >> derived >> base >> ing;
    int cost, val;
    cin >> cost >> val;
    d[mp(derived,base)] = mp(cost,val);
    se.insert(derived);
    se.insert(base);
  }

  map<string,int> counter;
  int cnt = 0;
  for(auto it : se) 
  {
    counter[it] = cnt;
    cnt++;
  }

  n = cnt;
  for(auto it : d)
  {
    int u = counter[it.fi.fi], v = counter[it.fi.se];
    edge[mp(u,v)] = it.se;
    adj[u].pu(v);
  }

  for(int i=0;i<n;i++)
  {
    if(!vis[i]) dfs(i);
  }

  vector<pair<int,int> > topo;
  for(int i=0;i<n;i++) topo.pu(mp(fin[i],i));
  sort(topo.begin(),topo.end());

  for(int i=0;i<topo.size();i++)
  {
    int u = topo[i].se;
    ans[u] = mp(0,0);
    bool isLeaf = true;
    pair<int,int> opt = mp(INF,-INF);

    for(auto v : adj[u])
    {
      isLeaf = false;
      pair<int,int> p2 = edge[mp(u,v)];
      pair<int,int> p = ans[v];
      p.fi += p2.fi;
      p.se += p2.se;
      // t(u,v,p);

      if(p.fi < opt.fi)
      {
        opt = p;
      }
      else if(p.fi == opt.fi && p.se > opt.se)
      {
        opt = p;
      } 
      // if(p.se > opt.se) 
      // {
      //   opt = p;
      // }
      // else if(p.se == opt.se && p.fi < opt.fi) 
      // {
      //   opt = p;
      // }
    }

    if(!isLeaf) ans[u] = opt;
  }

  // for(int i=0;i<n;i++) t(i,ans[i]);

  vector<vector<int> > dp(2,vector<int>(1e4+20,-INF));

  dp[0][ans[0].fi] = ans[0].se;
  dp[0][0] = 0;

  // for(int i=0;i<n;i++) t(i,ans[i]);
  // for(int j=0;j<=total;j++) cout << dp[0][j] << " "; cout << endl;

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<=total;j++)
    {
      // if(dp[0][j] == -INF) continue;
      if(j-ans[i].fi>=0 && dp[0][j-ans[i].fi] != -INF) 
      {
        dp[1][j] = max(dp[0][j-ans[i].fi] + ans[i].se,dp[0][j]);
      } 
      else dp[1][j] = dp[0][j];
    }
    swap(dp[1],dp[0]);
    // for(int j=0;j<=total;j++) cout << dp[0][j] << " "; cout << endl;
  }

  int max1 = -1,idx = 0;
  for(int i=0;i<=total;i++) 
  {
    if(dp[0][i] > max1)
    {
      max1 = dp[0][i];
      idx = i;
    }
  }

  if(max1 == -1) cout << "0 0" << endl;
  else cout << max1 << endl << idx << endl;
  return 0;
}

/*
15
6
pizza_tomato pizza_base tomato 101 2
pizza_cheese pizza_base cheese 105 10
pizza_classic pizza_tomato cheese 105 5
pizza_classic pizza_cheese tomato 101 2
pizza_salami pizza_classic salami 107 6
pizza_spicy pizza_tomato chili 3 101

*/