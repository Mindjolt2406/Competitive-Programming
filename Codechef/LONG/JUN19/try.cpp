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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int MAXN = 2.5e5+1,MAXLOG = 25;
vector<int> adj[MAXN] = {};
int parent[MAXN][25] = {0};
vector<vector<ll> > dp(MAXN,vector<ll>(MAXLOG));
int height[MAXN] = {0};
ll sz[MAXN] = {0};

// Counter1 is the total number of paths, not including the parent passing, through the current node
// Counter2 is the total number of paths from root -> children. Any path coming from the parent goes from here

ll counter1[MAXN] = {0};

int dfs1(int u = 0,int p = -1)
{
  sz[u] = 1;
  for(auto v : adj[u]) if(v-p) sz[u]+=dfs1(v,u);
  return sz[u];
}

void dfs2(int u = 0,int p = -1)
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

  ll a = sz[u]-1; // Root -> children
  ll cnt = 0; // Children -> Children + Root -> children
  for(auto v : adj[u]) if(v-p) cnt+=sz[v]*(a-sz[v]);
  cnt>>=1;
  cnt+=a;

  counter1[u] = cnt;

  // if(sz[u]==1) counter1[u] = counter2[u] = 1;

  if(p+1) 
  {
    dp[u][0] = counter1[p] - (sz[p]-sz[u])*sz[u];
  }

  for(int i=1;i<MAXLOG;i++)
  {
    if(parent[u][i-1]+1 && parent[u][i]+1)
    {
      dp[u][i] += dp[parent[u][i-1]][i-1] + dp[u][i-1];
    }
  }

  for(auto v : adj[u]) if(v-p) dfs2(v,u);
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

ll find(int u,int lca,int n,int v = -1)
{
  int u1 = u, v1 = v;
  if(v!=-1 && height[v]>height[u]) swap(u,v);

  // t(u,lca,v);
  // Get the nodes to the height of lca-1
  ll cntu = 0, cntv = 0;
  for(int i=MAXLOG-1;i>=0;i--)
  {
    if(parent[u][i]+1 && height[parent[u][i]]>=height[lca]+1) 
    {
      cntu+=dp[u][i];
      u = parent[u][i];
    }
    if(v+1 && parent[v][i]+1 && height[parent[v][i]]>=height[lca]+1) 
    {
      cntv+=dp[v][i];
      v = parent[v][i];
    }
  }

  // t(u,v);
  ll cnt = 0;
  // Both u and v, if there, are the height of LCA - 1
  // There are 2 nodes in the chain which we haven't taken care of. The LCA and the original nodes, u1 and v1
  if(v==-1)
  {
    cntu+=dp[u][0];
    cnt+=cntu;
     // Anybody from the parent can intersect with the lca and can go anywhere apart from the subtree of u
    cnt += (n-sz[lca])*(sz[lca]-sz[u]);
    cnt+=counter1[u1];
    cnt+=height[u1]-height[lca]+1; // My system never allowed (u,u) to be called a valid path, will try adding it in the dp
  }
  else
  {
    // cntu+=dp[u][0];
    // cntv+=dp[v][0];
    // t(dp[u][0],dp[v][0]);
    
    // Parent -> lca -> a node not in the subtree of u or v
    cnt += (n-sz[lca])*(sz[lca]-sz[u]-sz[v]);
    // A path involving the lca and not the parent should originate from a node which should not be in the subtree or u or v
    // Or, all the paths involving the lca i.e. counter1[lca] and remove the paths which originate somewhere and go to subtree of either u or v
    

    ll a = sz[lca] - sz[u] - sz[v];
    cnt+= counter1[lca] - a*(sz[u]+sz[v]) -sz[u]*sz[v];

    cnt+=cntu+cntv;
    // Correct stuff, pls don't touch this
    cnt+=counter1[u1]+counter1[v1];
    cnt+=height[u1]+height[v1]-2*height[lca]+1;
  }
  return cnt;
}

int main()
{
  // __;
  int t;
  // cin>>t;
  scanf("%d",&t);
  while(t--)
  {
    int n,q;
    // cin>>n>>q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++) for(int j=0;j<MAXLOG;j++) parent[i][j] = -1;
    for(int i=0;i<n-1;i++)
    {
      int a,b;
      // cin>>a>>b;
      scanf("%d %d",&a,&b);
      a--;b--;
      adj[a].pu(b);
      adj[b].pu(a);
    }
    dfs1();
    dfs2();
    // for(int i=0;i<n;i++) t(i,sz[i],counter1[i]);
    // for(int i=0;i<n;i++)
    // {
    //   for(int j=0;j<5;j++)
    //   {
    //     t(i,j,dp[i][j],parent[i][j]);
    //   }
    // }
    while(q--)
    {
      int a,b;
      // cin>>a>>b;
      scanf("%d %d",&a,&b);
      a--;b--;
      int lca = LCA(a,b);
      if(lca==a) {a = b; b = lca;}

      // if(lca!=a && lca!=b) cout<<find(a,lca,n,b)<<endl;
      // else cout<<find(a,b,n)<<endl;
      if(lca!=a && lca!=b) printf("%lld\n",find(a,lca,n,b));
      else if(a==b) printf("%lld\n",(n-sz[a])*(sz[a])+counter1[a]+1);
      else printf("%lld\n",find(a,b,n));
    }

    for(int i=0;i<n;i++) for(int j=0;j<MAXLOG;j++) dp[i][j] = 0;
    memset(height,0,sizeof(height));
    memset(sz,0,sizeof(sz));  
    memset(counter1,0,sizeof(counter1));
    for(int i=0;i<n;i++) adj[i] = {};
  }
  return 0;
}

/*
2
8 8
1 2
2 5
2 6
1 3
3 7
1 4
4 8
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
6 2
1 2
1 3
1 4
2 5
2 6
4 5
1 3

*/