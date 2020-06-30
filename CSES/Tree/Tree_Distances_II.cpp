#include<bits/stdc++.h>
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

const int N = 2e5+10;

vector<int> adj[N] = {};
vector<ll> dist(N);
vector<ll> ans(N);
vector<int> sz(N);

void dfs1(int u = 0,int p = -1)
{
  bool isLeaf = true;
  sz[u] = 1;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      isLeaf = false;
      dfs1(v,u);
      sz[u] += sz[v];
      dist[u] += dist[v]+sz[v];
      // t(u,v,sz[u],sz[v],dist[u],dist[v]);
    }
  }
}

void dfs2(int n,int u = 0,int p = -1)
{
  for(auto v : adj[u])
  {
    if(v-p)
    {
      ll temp = ans[u] - dist[v] - sz[v];
      temp += (n-sz[v]);
      ans[v] = temp + dist[v];
      dfs2(n,v,u);
    }
  }
}

int main()
{
  __;
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }
  dfs1();
  ans[0] = dist[0];
  dfs2(n);

  // for(int i=0;i<n;i++) cout << dist[i] << " "; cout <<endl;
  for(int i=0;i<n;i++) cout << ans[i] << " "; cout << endl;
  return 0;
}
