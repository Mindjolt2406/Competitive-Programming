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

ll max(ll x, ll y)
{
  if(x > y) return x;
  return y;
}

const int N = 2e5+10;

map<pair<int,int>,int> edge;
set<pair<int,int> > edge_mst;
map<pair<int,int>, ll> answer;


vector<int> adj[N] = {};
int MAXLOG = 25;
vector<vector<int> >  parent(N,vector<int>(MAXLOG,-1));
vector<vector<int> >  lift(N,vector<int>(MAXLOG,0));
int height[N] = {0};
ll weight[N] = {0};

void dfsLCA(int u = 0,int p = -1)
{
  // t(u);
  if(p+1) 
  {
    height[u] = height[p]+1;
    weight[u] = edge[mp(u,p)];
  }

  lift[u][0] = weight[u];
  parent[u][0] = p;
  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
      lift[u][i] = max(lift[u][i-1],lift[parent[u][i-1]][i-1]);
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

ll query(int u,int v)
{
  if(u == v) return 0;
  if(height[v] > height[u]) swap(u,v);
  ll max1 = lift[u][0];

  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[v]) 
    {
      max1 = max(max1,lift[u][i]);
      u = parent[u][i];
    }
  }

  return max1;
}

int p[N], sz[N];

void create(int x){
	p[x] = x;
	sz[x] = 1;
	return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

vector<int> graph[N] = {};
vector<int> vis(N);
ll mst_cost = 0;

void dfs1(int u = 0,int p = -1)
{
  vis[u] = 1;
  for(auto v : graph[u])
  {
    if(v-p)
    {
      if(vis[v])
      {
        // (u,v) is a back edge
        int temp_lca = LCA(u,v);
        ll temp = max(query(u,temp_lca),query(v,temp_lca));
        answer[mp(u,v)] = answer[mp(v,u)] = mst_cost - temp + edge[mp(u,v)];
      }
      else
      {
        // If it's a mst edge, do a dfs
        if(edge_mst.count(mp(u,v)))
        {
          answer[mp(u,v)] = answer[mp(v,u)] = mst_cost;
          dfs1(v,u);
        }
        // Otherwise let it be a future back edge. Don't do anything
      } 
    }
  }
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;

vector<pair<int,pair<int,int> > > edge_graph;
vector<pair<int,int> > edge_order;

  for(int i=0;i<n;i++) create(i);

  for(int i=0;i<m;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    a--; b--;
    graph[a].pu(b);
    graph[b].pu(a);
    edge[mp(a,b)] = edge[mp(b,a)] = c;
    edge_order.pu(mp(a,b));
    edge_graph.pu(mp(c,mp(a,b)));
  }

  sort(edge_graph.begin(),edge_graph.end());

  for(int i=0;i<edge_graph.size();i++)
  {
    auto it = edge_graph[i];
    int u = it.se.fi, v = it.se.se;
    if(find(u) == find(v)) continue;
    else 
    {
      // For checking in the dfs
      edge_mst.insert(mp(v,u));
      edge_mst.insert(mp(u,v));
      // Tree for binary lifting
      adj[u].pu(v);
      adj[v].pu(u);
      mst_cost += it.fi;
      merge(u,v);
    }
  }

  // Propagates weight to the child node
  // Makes the LCA table 
  dfsLCA();
  // Queries for every back/cross edge
  dfs1();

  for(auto edge : edge_order)
  {
    cout << answer[edge] << endl;
  }
  return 0;
}
