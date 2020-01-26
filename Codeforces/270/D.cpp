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

const int N = 2010; // 20 FOR DEBUGGING. MAKE IT 2010 BEFORE SUBMITTING
const int MAXLOG = 25;
vector<vector<ll> > mat(N,vector<ll>(N));
vector<int> adj[N] = {};
vector<ll> dist(N,INF);
int parent[N][MAXLOG] = {0};
int height[N] = {0};
int vis[N] = {0};


void dfsLCA(int u = 0,int p = -1)
{
  // t(u);
  vis[u] = 1;
  if(p+1) height[u] = height[p]+1;
  parent[u][0] = p;
  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }
  for(auto v : adj[u]) if(!vis[v]) dfsLCA(v,u);
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


typedef pair<ll,pair<int,int> > edge;

auto comp = [](const edge& n1, const edge&n2)
{
  if(n1.fi>n2.fi) return true;
  return false;
};

void dfs(int u = 0,int p = -1, ll val = 0)
{
  dist[u] = val;
  vis[u] = 1;
  for(auto v : adj[u]) if(!vis[v]) dfs(v,u,val+mat[u][v]);
}

int main()
{
  __;
  int n;
  cin>>n;
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>mat[i][j];

  for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(mat[i][j]!=mat[j][i]) {cout<<"NO"<<endl; return 0;}

  int root = 0;
  vector<bool> check(n);
  priority_queue<edge , vector<edge> , decltype(comp) > pq(comp);
  check[root] = true;
  bool boo = false;

  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(!check[j])
      {
        pq.push(mp(mat[root][j],mp(root,j)));
      }
    }

    int u = 0, v = 0;
    int cnt = 0;
    while(true)
    {
      auto edge1 = pq.top();
      pq.pop();
      u = edge1.se.fi;
      v = edge1.se.se;
      ll val = mat[u][v];
      if(!val) {boo = true; break;}
      adj[u].pu(v);
      adj[v].pu(u);

      if(!check[v]) 
      {
        check[v] = true;
        root = v;
        break;
      }
      else if(!check[u])
      {
        check[u] = true;
        root = u;
        break;
      }
    }

    // t(u,v,root,check[u],check[v]);
    // Keep only at max n elements in the prioirty queue
    vector<edge> temp;
    if(pq.size()>n) for(int i=0;i<n;i++) {temp.pu(pq.top());pq.pop();}
    else continue;
    while(!pq.empty()) pq.pop();
    for(int i=0;i<temp.size();i++) pq.push(temp[i]);
  }

  
  if(boo) {cout<<"NO"<<endl; return 0;}
  dfs();
  memset(vis,0,sizeof(vis));
  for(int i=0;i<n;i++) if(!vis[i]) {cout<<"NO"<<endl; return 0;}
  dfsLCA();

  // for(int i=0;i<n;i++) t(i,dist[i]);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(mat[i][j] != dist[i] + dist[j] - 2*dist[LCA(i,j)]) {boo = true; break;}
    }
    if(boo) break;
  }

  if(boo) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}

