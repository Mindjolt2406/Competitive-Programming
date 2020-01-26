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

const int N = 1e5;
vector<pair<int,ll> > adj[N] = {};
vector<pair<int,ll> > adj2[N] = {};
vector<pair<int,ll> > dag[N] = {};
vector<int> parent1(N,-1);
vector<ll> dist1(N,INF);

vector<int> parent2(N,-1);
vector<ll> dist2(N,INF);

vector<int> vis(N);
vector<ll> dp1(N), dp2(N);
vector<int> topo;

void path(int n,int u,vector<int> &parent,vector<ll> &dist)
{
  priority_queue<pair<int,int> , vector<pair<int,int> > , greater<int> > pq;

  pq.push(mp(0,u));
  dist[u] = 0;
  while(!pq.empty())
  {
    int u = pq.top().se;
    pq.pop();

    for(auto p : adj[u])
    {
      int v = p.se, weight = p.fi;
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
      int v = p.se, weight = p.fi;
      if(dist[v]> dist[u]+weight)
      {
        dist[v] = dist[u] + weight;
        parent[v] = u;
        pq.push(mp(dist[v],v));
      }
    }
  }
}

ll dfs(int u,int p = -1)
{
  for(auto v : adj[u])
  {
    if(v-p && vis[v]==0)
    {
      vis[v] = 1;
      dfs(v,u);
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
    v.pu(mp(a,b));
    adj[a].pu(mp(b,w));
    adj2[b].pu(mp(a,w)); // Reverse graph
  }

  path(n,s,parent1,dist1);
  path(n,s,parent2,dist2);

  ll cost = dist1[t];
  set<pair<pair<int,int>,ll>  > s;
  
  for(int i=0;i<v.size();i++)
  {
    int a = v[i].fi.fi, b = v[i].fi.se;
    ll w = v[i].se;
    if(dist1[a] + w + dist2[b] == cost) 
    {
      dag[a].pu(mp(b,w));
      s.insert(v[i]);
    }
  }

  dfs(s);
  // reverse(topo.begin(),topo.end());

  for(int i=0;i<topo.size();i++)
  {
    int u = topo[i];
    if(adj[u].size()==0) dp1[u] = dp2[u] = 1;
    for(auto v : adj[u]) 
    {
      dp1[u]+=dp1[v];
      dp2[u]+=dp2[v];
      dp1[u]%=MOD1;
      dp2[u]%=MOD2;
    }
  }

  s.clear();
  for(int i=0;i<n;i++)
  {
    if(dp1[s]==dp1[i] && dp2[s]==dp2[i] && adj[i].size()==1) 
    {
      s.insert(mp(mp(i,adj[i].fi),adj[i].se));
    }
  }


  for(int i=0;i<v.size();i++)
  {
    if(s.find(v[i])!=s.end())
    {
      cout<<"YES"<<endl;
    }
    else
    {
      int a = v[i].fi.fi, b = v[i].fi.se;
      ll w = v[i].se;
      ll costnow = dist1[a] + w + dist[b];
      if(costnow- (cost+1) > w)
      {
        cout<<"CAN "<<costnow-(cost+1)<<endl;
      }
      else cout<<"NO"<<endl;
    }
  }

  return 0;
}

