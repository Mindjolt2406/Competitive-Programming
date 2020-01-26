/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
#define MOD1 1000000007
#define MOD2 1000000009
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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < 10; ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


const int N = 1e5;
vector<pair<int,ll> > adj[N] = {};
vector<pair<int,ll> > adj2[N] = {};
vector<pair<int,ll> > dag[N] = {};

vector<int> parent1(N,-1);
vector<ll> dist1(N,INF);

vector<int> parent2(N,-1);
vector<ll> dist2(N,INF);

vector<int> vis(N),invtopo(N),back(N,-1);
vector<int> in(N),out(n);
vector<int> topo;

struct greater1{
  bool operator()(const long& a,const long& b) const{
    return a>b;
  }
};

void path(int n,int u,vector<int> &parent,vector<ll> &dist)
{
  // priority_queue<pair<ll,ll> , vector<pair<ll,ll> > , greater<ll> > pq;
  priority_queue<pair<ll,ll> , vector<pair<ll,ll> > , greater<pair<ll,ll> > > pq;

  pq.push(mp(0,u));
  dist[u] = 0;
  while(!pq.empty())
  {
    int u = pq.top().se;
    pq.pop();

    for(auto p : adj[u])
    {
      int v = p.fi;
      ll weight = p.se;
      if(dist[v]> dist[u]+weight)
      {
        dist[v] = dist[u] + weight;
        parent[v] = u;
        pq.push(mp(dist[v],v));
      }
    }
  }
}

void path2(int n,int u,vector<int> &parent,vector<ll> &dist)
{
  priority_queue<pair<ll,ll> , vector<pair<ll,ll> > , greater<pair<ll,ll> > > pq;

  pq.push(mp(0,u));
  dist[u] = 0;
  while(!pq.empty())
  {
    int u = pq.top().se;
    pq.pop();

    for(auto p : adj2[u])
    {
      int v = p.fi; 
      ll weight = p.se;
      if(dist[v]> dist[u]+weight)
      {
        dist[v] = dist[u] + weight;
        parent[v] = u;
        pq.push(mp(dist[v],v));
      }
    }
  }
}

void dfs(int u,int p = -1)
{
  for(auto v : adj[u])
  {
    if(v.fi-p && vis[v.fi]==0)
    {
      vis[v.fi] = 1;
      dfs(v.fi,u);
    }
  }
  topo.pu(u);
}

int main()
{
  __;
  int n,m,s,t;
  cin>>n>>m>>s>>t;
  s--;t--;
  vector<pair<pair<int,int>,ll>  > v;
  for(int i=0;i<m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    a--;b--;
    v.pu(mp(mp(a,b),w));
    adj[a].pu(mp(b,w));
    adj2[b].pu(mp(a,w)); // Reverse graph
  }

  path(n,s,parent1,dist1);
  path2(n,t,parent2,dist2);

  // t(dist1,dist2);

  ll cost = dist1[t];
  set<pair<pair<int,int>,ll>  > d;
  
  for(int i=0;i<v.size();i++)
  {
    int a = v[i].fi.fi, b = v[i].fi.se;
    ll w = v[i].se;
    // t(dist1[a],dist2[b],w,cost);
    if(dist1[a] + w + dist2[b] == cost) 
    {
      // t(a,b);
      dag[a].pu(mp(b,w));
      in[b]++;
      out[a]++;
      d.insert(v[i]);
    }
  }

  dfs(s);
  // reverse(topo.begin(),topo.end());
  for(int i=0;i<n;i++) invtopo[topo[i]] = i;

  for(int i=n-1;i>=0;i--)
  {
    int u = topo[i];
    
  }

  for(int i=0;i<v.size();i++)
  {
    if(d.find(v[i])!=d.end())
    {
      cout<<"YES"<<endl;
    }
    else
    {
      int a = v[i].fi.fi, b = v[i].fi.se;
      ll w = v[i].se;
      ll costnow = dist1[a] + w + dist2[b];
      if(costnow- (cost+1) > w)
      {
        cout<<"CAN "<<costnow-(cost+1)<<endl;
      }
      else cout<<"NO"<<endl;
    }
  }

  return 0;
}

