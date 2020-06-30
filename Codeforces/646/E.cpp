#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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

const int N = 2e5+100;
vector<int> adj[N] = {};
vector< pair<int,int> > bin_digit(N);
vector<ll> cost(N);

ll ans = 0;

ll min(ll x, ll y)
{
  return (x<y) ? x : y;
}

pair<int,int>  dfs(int u = 0,int p = -1, ll par_cost = INF)
{
  cost[u] = min(cost[u],par_cost);
  pair<int,int> digit;
  if(bin_digit[u] == mp(0,0) || bin_digit[u] == mp(1,1)) digit = mp(0,0);
  else if(bin_digit[u].fi == 0) digit = mp(1,0);
  else digit = mp(0,1);

  for(auto v : adj[u])
  {
    if(v-p) 
    {
      pair<int,int> p = dfs(v,u,cost[u]);
      digit.fi += p.fi;
      digit.se += p.se;
    }
  }

  if(digit.fi >= digit.se) 
  {
    digit.fi -= digit.se;
    ans += digit.se * cost[u];
    digit.se = 0;
  }
  else
  {
    digit.se -= digit.fi;
    ans += digit.fi * cost[u];
    digit.fi = 0;
  }

  // t(u,ans,digit);

  return digit;
}

int main()
{
  __;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    ll node_cost;
    pair<int,int> digit;
    cin >> node_cost >> digit.fi >> digit.se;
    cost[i] = node_cost;
    bin_digit[i] = digit;
  }

  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  pair<int,int> p = dfs();
  if(p.fi == 0 && p.se == 0) cout << ans*2 << endl;
  else cout << -1 << endl;
  return 0;
}
