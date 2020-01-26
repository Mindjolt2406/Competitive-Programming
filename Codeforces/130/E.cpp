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

const int N = 2e5+1, MAXLOG = 18;
int counter[N] = {0};
bool big[N] = {0};
int height[N] = {0};
int sz[N] = {0};
int ancestor[N][18] = {0};
vector<int> adj[N];
vector<vector<pair<int,int> > > d(N);
int ans[N] = {0};
int visited[N] = {0};


void add(int u,int par, int val)
{
  counter[height[u]] += val;
  for(auto v : adj[u])
  {
    if(!big[v] && par-v) add(v,u,val); 
  }
}

int dfs1(int u,int par = -1) // Gets the size of the subtree
{
  // t(u);
  int count = 1;
  for(auto v : adj[u]) if(u-v) count+=dfs1(v,u);
  sz[u] = count;
  return count;
}

int dfs2(int u,int depth, int par = -1) // Gets the height of each node
{
  height[u] = depth;
  for(auto v: adj[u]) if(v-u) dfs2(v,depth+1,u);
  return height[u];
}

void dfs3(int u,int par = -1) // Makes the table mat[i][j], which contains the 2^jth ancestor of i
{
  // The ancestor[i][j] = -1
  if(par+1) ancestor[u][0] = par;
  for(int i=1;i<=MAXLOG;i++)
  {
    if(ancestor[u][i-1]+1)
    {
      ancestor[u][i] = ancestor[ancestor[u][i-1]][i-1];
    }
  }
  for(auto v : adj[u]) if(u-v) dfs3(v,u);
}

int getAncestor(int u,int p)
{
  // We want the pth ancestor of u
  // It's given that the query is always possible
  int h = height[u]-p;
  if(h<0) return 0; 
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(ancestor[u][i]+1 && height[ancestor[u][i]]>=h)
    {
      u = ancestor[u][i];
    } 
  }
  return u;
}

void dfs(int u,int par, bool keep)
{
  // cout<<"u: "<<u<<endl;
  int bigChild = -1;
  int max1 = -1;
  for(auto v : adj[u])
  {
    if(sz[v]>max1 && v-par) {max1 = sz[v]; bigChild = v;}
  }

  // Clear from the global array
  for(auto v : adj[u]) if(par-v && v!=bigChild) dfs(v,u,0);

  // Add the bigchild to the array
  if(bigChild!=-1) {dfs(bigChild, u,1); big[bigChild] = 1;}

  // Compute the rest by doing a dfs down
  add(u,par,1);

  // Answer the queries here
  // t(u); 
  // for(int i=0;i<=2;i++) cout<<counter[i]<<" ";cout<<endl;
  if(!visited[u])
  {
    vector<pair<int,int> > &v = d[u];
    for(int i=0;i<v.size();i++)
    {
      int a = v[i].fi, b = v[i].se;
      int cur = height[u];
      int answer = counter[cur+a];
      if(u!=0) ans[b] = answer-1;
      else ans[b] = 0;
    }
  }
  visited[u] = 1;
  // Clear the bigChild first, because you're done with your work
  if(bigChild!=-1) big[bigChild] = 0;

  // If you're not a bigChild, you shouldn't keep your work
  if(keep==0) add(u,par,-1);
}



int main()
{
  __;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) 
  {
    int a;
    cin>>a;
    adj[a].push_back(i);
  }

  for(int i=0;i<=n;i++) for(int j=0;j<MAXLOG;j++) ancestor[i][j] = -1;
  
  dfs1(0);
  dfs2(0,0);
  dfs3(0);
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    int c = getAncestor(a,b);
    // t(a,b,c);
    d[c].push_back(mp(b,h));
    // ans.push_back(mp(c,b));
    // if(c==0) // The answer to this query is 0.
  }

  dfs(0,-1,0);
  for(int i=0;i<q;i++)
  {
    cout<<ans[i]<<" ";
  }
  cout<<endl;

  // for(int i=0;i<=n;i++) {for(int j=0;j<4;j++) cout<<ancestor[i][j]<<" "; cout<<endl;}
  return 0;
}

