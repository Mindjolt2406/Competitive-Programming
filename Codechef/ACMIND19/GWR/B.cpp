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

const int N = 1e5;
vector<int> adj[N] = {};
vector<int> sz(N),ans(N);
int n;

void dfs1(int u = 0, int p = -1)
{
  sz[u] = 1;
  for(auto v : adj[u])
  {
    if(v-p) 
    {
      dfs1(v,u);
      sz[u] += sz[v];
    }
  }
}

void dfs2(int u = 0,int p = -1)
{
  if(sz[u] == 1)
  {
    ans[u] = 0;
    return;
  }

  int max1 = n-sz[u];
  for(auto v : adj[u])
  {
    if(v-p) 
    {
      dfs2(v,u);
      max1 = max(max1,sz[v]);
    }
  }

  int a = n-1-max1;

  n-max1 >= max1
  
  // 2*max1 >= n-1;

  // 2*max1 <= n;

  // if(max1 >= a)
  // {
  //   ans[u] = 0;
  // }
  // else
  // {
  //   if(n%2) ans[u] = 0;
  //   else ans[u] = 1;
  // }

  if(n%2==0 && max1 <= a) ans[u] = 1;
  else ans[u] = 0;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      adj[a].pu(b);
      adj[b].pu(a);
    }

    if(n==2)
    {
      cout << "11" << endl;
    }
    else if(n%2==1)
    {
      for(int i=0;i<n;i++) cout << 0;
      cout << endl;
    }
    else
    {
      dfs1();
      dfs2();

      for(int i=0;i<n;i++) cout << ans[i];
      cout << endl;
    }

    for(int i=0;i<n;i++) adj[i].clear();
    ans.clear();
    sz.clear();
  }
  return 0;
}