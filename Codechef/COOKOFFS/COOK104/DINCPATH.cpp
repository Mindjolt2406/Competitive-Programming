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
#define int long long int
// #define ll long long int
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

const int N = 1e5+10;
vector<int> adj[N] = {},par[N] = {};
int vis[N] = {0}, ans[N] = {0};
vector<int> v;

int max(int a, int b)
{
  if(a>b) return a;
  return b;
}

int dfs(int u = 0,int p = -1)
{
  if(vis[u]==2) return ans[u];
  else if(vis[u]==1) return -1; // COndition not needed

  int flag = 0; // To check whether there's a child or not
  vis[u] = 1;
  set<pair<int,int> > s; // Set of all children adges, first being the difference, and the second being the ans for the child
  for(auto v1 : adj[u]) 
  {
    if(v1-p)
    {
      flag = 1;
      int a = dfs(v1,u);
      s.insert(mp(v[v1]-v[u],a));
    }
  }

  vis[u] = 2;
  if(flag) ans[u] = max(ans[u],2); // If there's a child, the min ans is 2
  else {ans[u] = 1; vis[u] = 2; return ans[u];} // Leaf node

  vector<pair<int,int> > w; // Sorted vector wrt to differences
  for(auto a : s) w.pu(a); 

  int max2 = -1; // Taking the cumulative sum backwards
  for(int i=(int)w.size()-1;i>=0;i--) 
  {
    max2 = max(max2,w[i].se);
    w[i].se = max2;
  }



  if(!par[u].empty())
  {
    // Now, for every parent, parent-> u -> child is a valid path only when parent-> u < u->child
    for(auto v1 : par[u])
    {
      int a = v[u] - v[v1];
      
      // Binary searching for that edge
      int beg = 0, end = (int)w.size()-1, ans2 = -1;
      while(beg<=end)
      {
        int mid = (beg+end)/2;
        if(w[mid].fi>a) {end = mid-1;ans2 = mid;}
        else {beg=mid+1;} 
      }

      // All edges from [ans2,w.size()-1] are valid edges. Since we're taking cumulative max from the back, we don't need to 
      // check all the adges
      if(ans2!=-1) ans[v1] = max(w[ans2].se+2,ans[v1]); 
    }
  }

  return ans[u];
}

int32_t main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) v.pu(0);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<m;i++)
    {
      int a,b;
      cin>>a>>b;
      a--;b--;
      if(v[a]<v[b]) {adj[a].pu(b);par[b].pu(a);}
      else if(v[b]>v[a]) {adj[b].pu(a);par[a].pu(b);}
    }

    int max1 = -1;
    for(int i=0;i<n;i++)
    {
      if(!vis[i]) max1 = max(max1,dfs(i));
    }

    cout<<max1<<endl;

    memset(adj,0,sizeof(adj));
    memset(par,0,sizeof(par));
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    v.clear();
  }
  return 0;
}

/*
1
5 4
1 2 3 4 5
2 4
1 5
1 3
3 5

*/