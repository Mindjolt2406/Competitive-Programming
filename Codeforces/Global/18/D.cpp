// clang-format off
#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
#define ll long long int
#define ld long double
#define fi first
#define se second
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <ll> ostream& operator<<(ostream& os, const vector<ll>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const set<T>& s) {os << "{"; for(auto it : s) {if(it != *s.rbegin()) os << it << ", "; else os << it;} os << "}"; return os;}
// clang-format on

const int N = 2e5+1;
vector<int> adj[N] = {};
int MAXLOG = 25;
vector<vector<int> >  parent(N,vector<int>(MAXLOG,-1));
int height[N] = {0};
vector<int> xorRoot(N);
map<pair<int, int>, int> edgeWeight;

void dfsLCA(int u = 0,int p = -1)
{
  // t(u);
  if(p+1) {
      height[u] = height[p]+1;
      xorRoot[u] = xorRoot[p] ^ edgeWeight[{p, u}];
  }
  parent[u][0] = p;
  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }
  for(auto v : adj[u]) if(p-v) dfsLCA(v,u);
}

int LCA(int u,int v)
{
  // height means depth here
  if(height[v]>height[u]) swap(u,v);

  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[v]) u = parent[u][i];
  }

  // height[u]==height[v]
  if(u==v) return u;
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]!=parent[v][i]) 
    {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return parent[v][0];
}

int getXor(int a, int b) {
    return xorRoot[a] ^ xorRoot[b];
}

int childLca(int u, int v) {
    return (LCA(u, v) == u) ? v : u;
}

void dfs(set<int> &goodQueries, set<pair<int, int>> takenEdges, int u = 0, int p = -1) {
    for (auto v : adj[u]) {
        if (v - p) {
            dfs(goodQueries, takenEdges, v, u);
        }
    }

    if (goodQueries.count(u))
        goodQueries.erase(u);
    if (goodQueries.size()) {
        takenEdges.insert({u, p});
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    map<pair<int, int>, bool> markedTroubledEdges;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (c == -1) {
            c = 0;
            markedTroubledEdges[{a, b}] = markedTroubledEdges[{b, a}] = false;
        }
        edgeWeight[{a, b}] = c;
        edgeWeight[{b, a}] = c;
    }

    dfsLCA();

    vector<pair<pair<int, int>, int>> queryEdges;
    vector<pair<int, int>> goodEdges;
    while (m--) {
        int a, b, p;
        cin >> a >> b >> p;
        a--; b--;
        if (__builtin_popcount(getXor(a, b)) == p) {
            goodEdges.push_back({a, b});
        }
        queryEdges.push_back({{a, b}, p});
    }

    // Delete everything now.
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        parent[i].clear();
        parent[i].resize(MAXLOG, -1);
        height[i] = 0;
        xorRoot[i] = 0;
    }
    edgeWeight.clear();
}

int main() {
    __;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
