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
#define vi vector<int>
#define vll vector<long long int>
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

const int N = 1e5+10, MAXLOG = 25;;
vector<int> adj[N];
int parent[N][MAXLOG];
int height[N] = {0}, sz[N] = {0};

void dfs1(int u, int p = -1)
{
  if(p+1) height[u] = height[p]+1;
  parent[u][0] = p;
  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }

  for(auto v : adj[u]) if(p-v) dfs1(v,u);
}

int dfs2(int u,int p = -1)
{
  int count = 1;
  for(auto v : adj[u]) if(v-p) count+=dfs2(v,u);
  sz[u] = count;
  return count;
}

pair<int,int> LCA(int u,int v)
{
  if(height[v]>height[u]) swap(u,v);

  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[v]) u = parent[u][i];
  }

  // height[u]==height[v]
  if(u==v) return mp(u,-1);
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]!=parent[v][i]) 
    {
      u = parent[u][i];
      v = parent[v][i];
    }
  }

  return mp(u,v);
}

pair<int,int> LCA2(int u,int v,int h)
{
  if(height[u]<height[v]) swap(u,v);

  int k = u;
  h++;
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=h)
    {
      u = parent[u][i];
    }
  }

  int child1 = u;
  u = parent[u][0];

  int child2 = -1;
  // t(h,height[u], u,k);

  // t(u,v);
  // for(auto v : adj[u])
  // {
  //   // t(v);
  //   if(parent[u][0]==v) continue;
  //   if(LCA(v,k)==v) {child1 = v; break;}
  // }

  // for(auto v1 :  adj[u])
  // {
  //   if(parent[u][0]==v1) continue;
  //   if(LCA(v1,v)==v1) {child2 = v1; break;}
  // }
  // t(child1,child2);
  return mp(u,child1);
}

int main()
{
  __;
  int n,q;
  cin>>n;

  for(int i=0;i<n;i++) for(int j=0;j<MAXLOG;j++) parent[i][j] = -1;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs1(0);
  // cout<<"PARENT"<<" "<<parent[2][0]<<endl;
  dfs2(0);

  cin>>q;
  while(q--)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    if(height[a]%2!=height[b]%2) cout<<0<<endl;
    else
    {
      int h1 = max(height[a], height[b]);
      int h2 = min(height[a], height[b]);
      pair<int,int> p = LCA(a,b);
      int f;
      if(p.se!=-1) f = parent[p.fi][0];
      else f = p.fi;
      int h = height[f];
      int hfinal = (h1-h2 + 2*h + 1) /2;
      // t(h1,h2,h,hfinal);
      // t(h);
      if(height[a]!=height[b])
      {
        pair<int,int> p = LCA2(a,b,hfinal);
        int c = p.fi, d = p.se;
        // t(c,d);
        // t(c,d);
        cout<<sz[c]-sz[d]<<endl;
      }
      else
      {
        pair<int,int> p = LCA(a,b);
        int d = p.fi, e = p.se;
        // t(d,e,f);
        // t(c,f,d,e);
        if(a==b) cout<<1<<endl;
        else cout<<n-sz[d]-sz[e]<<endl;
      }
    }
  }

  // for(int i=0;i<n;i++)
  // {
  //   for(int  j=0;j<3;j++) cout<<parent[i][j]<<" ";
  //   cout<<endl;
  // }
  return 0;
}

