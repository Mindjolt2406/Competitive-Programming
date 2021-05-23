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

void solve()
{
  int n,m;
  cin >> n >> m;
  vector<ll> cost(n),dp(n,INF);
  dp[0] = 0;

  for(int i=0;i<n;i++) cin >> cost[i];

  multiset<ll> last;
  last.insert(0);
  ll ans = 0;

  for(int i=1;i<n;i++)
  {
    if(!last.empty())
    {
      ans = *last.begin();
      if(cost[i] && ans != INF) dp[i] = ans+cost[i];
      if(ans == INF) last.insert(ans);
      else last.insert(dp[i]);
    }
    else ans = INF;

    if(i>=m) last.erase(last.find(dp[i-m]));
  }

  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
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
1
5 5
0
20
30
0
10
5 2
0
20
30
0
10
5 1
0
20
30
0
10
4 1
99
88
77
66
4 4
99
88
77
66
6 2
0
0
20
30
0
10
12 3
0
1
4
7
0
5
9
8
0
3
0
6


*/
