#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e17
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

ll min(ll x, ll y)
{
  if(x < y) return x;
  return y;
}

const int N = 1e6+10;
vector<vector<pair<int,int> > > adj(N);

int main()
{
  __; 
  int n,m,dist;
  cin >> n >> m >> dist;
  if(dist > n || dist > m)
  {
    cout << -1 << endl;
    return 0;
  }
  vector<vector<ll> > dp(n,vector<ll> (dist+1,INF));
  vector<vector<ll> > back(n,vector<ll> (dist+1,INF));

  map<pair<int,ll> , ll > d;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    ll c;
    cin >> c;
    d[mp(a,b)] = d[mp(b,a)] = c;
    adj[a].pu(mp(b,c));
    adj[b].pu(mp(a,c));
  } 

  dp[0][0] = 0;

  for(int k=1;k<=dist;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(auto p : adj[i])
      {
        int v = p.fi;
        int cost = p.se;
        // t(i,v,k,dp[v][k-1],d[mp(i,v)],dp[i][k]);
        if(back[v][k-1] != i) 
        {
          if(dp[i][k] > dp[v][k-1] + cost)
          {
             dp[i][k] = dp[v][k-1] + cost;
             back[i][k] = v;
          }
        }
        // t(i,v,k,dp[i][k]);
      }
    }
    if(k != dist) dp[n-1][k] = INF;
  }

  if(dp[n-1][dist] != INF) cout << dp[n-1][dist] << endl;
  else cout << -1 << endl;
  return 0;
}
