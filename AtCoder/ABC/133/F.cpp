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

const int N = 2e5+1;
vector<int> adj[N] = {};
vector<int> adj2[N] = {};
int MAXN = 2e5+1,MAXLOG = 25;
int parent[N][25] = {0};
int height[N] = {0};

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;  
    }
};

void dfsLCA(int u = 0,int p = -1)
{
  // t(u);
  if(p+1) height[u] = height[p]+1;
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

int lca(int u,int v)
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

int colour[N] = {0};
int dist[N] = {0};
int distcol[N] = {0};
unordered_map<pair<int,int> , int, pair_hash> d;
unordered_map<pair<int,int> , int, pair_hash> col;
unordered_map<pair<int,int> , int, pair_hash> answercol;
unordered_map<pair<int,int> , int, pair_hash> answerdcol;

void dfs3(int u = 0,int p = -1)
{
  // Answer queries for u here
  // t(u);
  for(auto v : adj2[u])
  {
    answercol[mp(u,v)] = colour[v];
    answerdcol[mp(u,v)] = distcol[v];
  } 

  for(auto v : adj[u])
  {
    if(v-p)
    {
      colour[col[mp(u,v)]]++;
      distcol[col[mp(u,v)]] += d[mp(u,v)];
      dfs3(v,u);
      colour[col[mp(u,v)]]--;
      distcol[col[mp(u,v)]] -= d[mp(u,v)];
    }
  }
}

int dfs2(int u = 0,int p = -1,int val = 0)
{
  dist[u] = val;
  for(auto v : adj[u]) if(v-p) dfs2(v,u,val+d[mp(u,v)]);

  return dist[u];
}



int main()
{
  __;
  int n,q;
  cin>>n>>q;
  vector<vector<int> > ans;

  for(int i=0;i<n-1;i++)
  {
    int a,b,c,di;
    cin>>a>>b>>c>>di;
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
    col[mp(a,b)] = col[mp(b,a)] = c;
    d[mp(a,b)] = d[mp(b,a)] = di;
  }

  dfsLCA();

  for(int h=1;h<=q;h++)
  {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    c--;d--;
    ans.pu({a,b,c,d});
    adj2[c].pu(a);
    adj2[d].pu(a);
    adj2[lca(c,d)].pu(a);
  }

  dfs2();
  dfs3();

  for(int i=0;i<ans.size();i++)
  {
    int x = ans[i][2], y = ans[i][3], z = lca(x,y);
    int co = ans[i][0], change = ans[i][1];

    int a = dist[x], b = dist[y], c = dist[z];
    a += answercol[mp(x,co)]*change - answerdcol[mp(x,co)];
    b += answercol[mp(y,co)]*change - answerdcol[mp(y,co)];
    c += answercol[mp(z,co)]*change - answerdcol[mp(z,co)];
    
    cout<<a+b-2*c<<endl;
  }
  return 0;
}

