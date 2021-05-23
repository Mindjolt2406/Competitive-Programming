#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 1e5+10;
vector<int> adj[N] = {};
vector<ll> ans(N);
vector<int> w(N);

bool sorter(const pair<ll,ll> p1, const pair<ll,ll> p2)
{
  return p1.se*p2.fi < p1.fi*p2.se;
}

pair<ll,ll> dfs(int u = 0, int par = -1)
{ 
  pair<ll,ll> p = mp(0,0);

  vector<pair<ll,ll> > keep;
  for(auto v : adj[u])
  {
    if(v-par)
    {
      pair<ll,ll> temp = dfs(v,u);
      p.fi += temp.fi; p.se += temp.se;
      keep.pu(temp);
    }
  }

  sort(keep.begin(), keep.end(), sorter);
  int tempZero = p.fi;
  ll ansU = 0;
  for(auto p : keep)
  {
    ansU += (tempZero-p.fi)*p.se;
    tempZero -= p.fi;
  }

  ans[u] = ansU + (w[u] ? p.fi : 0);

  p.fi += (w[u] == 0);
  p.se += (w[u] == 1);
  return p;
}

void solve()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> w[i];
  for(int i=0;i<n-1;i++)
  {
    int x,y;
    cin >> x >> y;
    x--; y--;
    adj[x].pu(y);
    adj[y].pu(x);
  }

  dfs();

  ll answer = 0;
  for(int i=0;i<n;i++) answer += ans[i];

  cout << answer << endl;

  for(int i=0;i<n;i++) w[i] = ans[i] = 0;
  for(int i=0;i<n;i++) adj[i].clear();
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
  return 0;
}

/*
2
3
1 0 1
1 2
1 3
7
0 1 0 1 0 0 1
1 2
1 3
2 4
2 5
3 6
3 7

*/