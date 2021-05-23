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

const int N = 5e5+100;
vector<vector<int> >  parent(N,vector<int>(20,-1));
vector<vector<int> > adj(N);
vector<ll> depth(N,-1);

void dfs(int dep = 0,int u = 0,int p = -1)
{
  depth[u] = dep;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      dfs(dep+1,v,u);
    }
  }
}

void dfsLCA(int u = 0,int p = -1)
{
  // t(u);
  if(p+1) depth[u] = depth[p]+1;
  parent[u][0] = p;
  for(int i=1;i<20;i++)
  {
    if(parent[u][i-1]+1)
    {
      parent[u][i] = parent[parent[u][i-1]][i-1];
    }
  }
  for(auto v : adj[u]) if(p-v) dfsLCA(v,u);
}

int getAncestor(int u,int A)
{
  if(A > depth[u]) return -1;
  int final_dep = depth[u]-A;

  for(int i=19;i>=0;i--)
  {
    if(parent[u][i]+1 && depth[parent[u][i]]>=final_dep) u = parent[u][i];
  }

  return u;
}

void makeDFS(vector<ll> &depA,vector<ll> &depB,int A,int B,int u = 0,int p = -1)
{
  for(auto v : adj[u])
  {
    if(v-p)
    {
      makeDFS(depA,depB,A,B,v,u);
    }
  }

  int ancesA = -1, ancesB = -1;
  ancesA = getAncestor(u,A);
  ancesB = getAncestor(u,B);
  if(ancesA>= 0 && ancesA < adj.size()) depA[ancesA]+= depA[u];
  if(ancesB>= 0 && ancesB < adj.size()) depB[ancesB]+= depB[u];
}

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

ll ceil(int depth,int A)
{
  if(depth%A == 0) return depth/A;
  else return depth/A+1;
}

void solve()
{
  int n;
  cin >> n;
  ll A,B;
  cin >> A >> B;

  for(int i=1;i<n;i++)
  {
    int par;
    cin >> par;
    par--;
    adj[i].pu(par);
    adj[par].pu(i);
  }

  vector<ll> depA(n,1),depB(n,1);

  dfs();

  dfsLCA();
  makeDFS(depA,depB,A,B);

  ll sum1 = 0, sum2 = 0, sum3 = 0;
  for(int i=0;i<n;i++)
  {
    sum1 += depA[i];
    sum2 += depB[i];
    sum3 += (1LL*depA[i])*depB[i];
  }

  ld ans = sum1 + sum2 - sum3/(ld)n;
  ans /= n;
  cout << fixed << setprecision(12);
  cout << ans << endl;
  for(int i=0;i<n;i++) for(int j=0;j<20;j++) parent[i][j] = -1;
  for(int i=0;i<n;i++) adj[i].clear();
  for(int i=0;i<n;i++) depth[i] = 0;
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}

/*
3
8 2 3
1 1 3 4 4 3 4
10 3 4
1 1 1 1 1 1 1 1 1
4 3 1
1 2 3

1
8 2 3
1 1 3 4 4 3 4

*/
