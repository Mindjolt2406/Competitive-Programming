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

pair<int,int> getRoot(vector<vector<int> > &adj,int u = 0,int p = -1,int depth = 0)
{
  pair<int,int> temp = mp(depth,u);
  for(auto v : adj[u])
  {
    if(v-p)
    {
      temp = max(temp,getRoot(adj,v,u,depth+1));
    }
  }

  return temp;
}

void findHeight(vector<vector<int> > &adj,vector<int> &height,int u = 0,int p = -1,int dep = 0)
{
  int max1 = 0;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      findHeight(adj,height,v,u,dep+1);
      max1 = max(max1,height[v]);
    }
  }

  height[u] = max1+1;
}

void findDepth(vector<vector<int> > &adj,vector<int> &depth,int u = 0,int p = -1,int dep = 1)
{
  depth[u] = dep;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      findDepth(adj,depth,v,u,dep+1);
    }
  }
}


void mark(vector<vector<int> > &adj,vector<ll> &ans,vector<int> &height,int u = 0,int p = -1, bool big = true)
{
  int bigChild = -1;

  if(big)
  {
    ans[u] = height[u];
    for(auto v : adj[u])
    {
      if(v-p)
      {
        if(height[v]+1 == height[u]) bigChild = v;
      }
    }
  }
  else ans[u] = 13082761331670030;

  for(auto v : adj[u])
  {
    if(v-p)
    {
      if(big && bigChild == v) 
      {
        mark(adj,ans,height,v,u,true);
      }
      else mark(adj,ans,height,v,u,false);
    }
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<vector<int> > adj(n);
    for(int i=0;i<n-1;i++)
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      adj[a].pu(b);
      adj[b].pu(a);
    }

    vector<ll> ans(n);
    vector<int> height(n),depth(n);
    pair<int,int> root = getRoot(adj);

    // t(root);

    findHeight(adj,height,root.se);
    findDepth(adj,depth,root.se);
    // t(height);
    mark(adj,ans,height,root.se);

    // for(int i=0;i<n;i++) if(ans[i] == 13082761331670030) ans[i] *= depth[i];

    for(int i=0;i<n;i++) 
    {
      if(depth[i] < 50) cout << 614889782588491410 << " ";
      else cout << (1LL*depth[i])*13082761331670030 << " "; cout << endl;
    }
  }
  return 0;
}
