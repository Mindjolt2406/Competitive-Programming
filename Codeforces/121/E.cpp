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

const int N = 1e5+10, MAXLOG = 25;
vector<int> adj[N];
int parent[N][MAXLOG] = {0};
int height[N] = {0}, val[N] = {0};
map<pair<int,int>,int > dict,ans;

void dfs1(int u,int p = -1)
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
  // t(u);
  int count = 0;
  for(auto v : adj[u])
  {
    if(!(v-p)) continue;
    int a = dfs2(v,u);
    int b;
    if(dict.find(mp(u,v))!=dict.end()) 
    {
      b = dict[mp(u,v)];
      ans[mp(u,v)] = a+b;
    }
    else
    {
      b = dict[mp(v,u)];
      ans[mp(v,u)] = a+b;
    }
    count+=a+b;
    // t(u,v,a,val[u],b+a);
  }
  count+=val[u];
  // t(u,count);
  return count;
}

int LCA(int u,int v)
{
  if(height[v]>height[u]) swap(v,u);

  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[v]) u = parent[u][i];
  }

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


int main()
{
  __;
  int n;
  cin>>n;
  for(int i=0;i<n;i++) for(int j=0;j<MAXLOG;j++) parent[i][j] = -1;
  vector<pair<int,int> > v;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    v.push_back(mp(a,b));
    dict[mp(a,b)] = 0;
    ans[mp(a,b)] = 0;
  }

  dfs1(0);
  
  int q;
  cin>>q;
  for(int i=0;i<q;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    int c = LCA(a,b),d,e;
    // t(a,b,c);
    // int boo1 = 0, boo2 = 0;
    // for(auto v : adj[c]) 
    // {
    //   if(!boo1) d = LCA(v,a);
    //   if(!boo2) e = LCA(v,b);
    //   if(d==v) boo1 = 1;
    //   if(e==v) boo2 = 1;
    //   t(c,v,d,e);
    // }

    d = parent[a][0];
    e = parent[b][0];

    if(c!=a)
    {
      // cout<<"1"<<endl;
      if(dict.find(mp(a,d))!=dict.end()) dict[mp(a,d)]++;
      else dict[mp(d,a)]++;
      val[c]--;
    }

    if(c!=b)
    {
      // cout<<"2"<<endl;
      if(dict.find(mp(b,e))!=dict.end()) dict[mp(b,e)]++;
      else dict[mp(e,b)]++;
      val[c]--;
    }
    // t(d,e);
  }
  
  dfs2(0);
  for(int i=0;i<v.size();i++) cout<<ans[v[i]]<<" ";
  cout<<endl;
  return 0;
}

