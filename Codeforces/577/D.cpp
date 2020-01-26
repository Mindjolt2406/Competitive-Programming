/*
Rathin Bhargava
IIIT Bangalore
 
*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e15
#define MOD 1000000007
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
 
ll bsearch1(vector<ll> &w,ll val) // Left value
{
  ll beg = 0, end = w.size()-1, ans = -1;
  while(beg<=end)
  {
    ll mid = (beg+end) >> 1;
    if(w[mid] <= val) {ans = mid; beg = mid+1;}
    else end = mid-1;
  }
  if(ans==-1) return -INF;
  else return w[ans];
}
 
ll bsearch2(vector<ll> &w,ll val) // Right value
{
  ll beg = 0, end = w.size()-1, ans = w.size();
  while(beg<=end)
  {
    ll mid = (beg+end) >> 1;
    if(w[mid] >= val) {ans = mid; end = mid-1;}
    else beg = mid+1;
  } 
  if(ans == w.size()) return INF;
  else return w[ans];
}
 
ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}
 
ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

ll f(ll l, ll r, ll col, bool boo)
{
  if(boo) // End at r
  {
    if(col < l) return abs(r-col);
    else if(l <= col && col < r) return 2*abs(col-l) + abs(r-l);
    else return 2*abs(r-l) + abs(col-r);
  }
  else // End at l
  {
    if(col < l) return abs(col-l) + abs(l-r)*2;
    else if(l <= col && col < r) return 2*abs(r-col) + abs(col-l);
    else return abs(l-col);
  }
}
 
int main()
{
  __;
  ll n,m,k,q;
  cin >> n >> m >> k >> q;
  set<ll> yval,xval;
  map<ll,ll> dmin,dmax; // Maps y -> (minx, maxx)
  map<ll,pair<ll,ll> > dx;
  vector<ll> safe(q);
 
  for(int i=0;i<k;i++)
  {
    ll a,b;
    cin >> b >> a;
    if(dmin.find(b)==dmin.end()) dmin[b] = a;
    else dmin[b] = min(dmin[b],a);
 
    if(dmax.find(b)==dmax.end()) dmax[b] = a;
    else dmax[b] = max(dmax[b],a);
 
    yval.insert(b);
    xval.insert(a);
  }

  yval.insert(1);
  xval.insert(1);

  if(dmin.find(1)==dmin.end()) dmin[1] = 1;
  else dmin[1] = min(dmin[1],1);

  if(dmax.find(1)==dmax.end()) dmax[1] = 1;
  else dmax[1] = max(dmax[1],1);
 
 
  for(int i=0;i<q;i++) cin >> safe[i];
 
  vector<ll> w;
  for(auto it : yval) w.pu(it);
  // t(w);
 
  vector<ll> dist;
 
  for(auto it : xval)
  {
    dx[it] = mp(bsearch1(safe,it),bsearch2(safe,it));
  }
 
  for(int i=0;i<w.size();i++) 
  {
    dist.pu(dmax[w[i]]-dmin[w[i]]);
  }
 
  vector<vector<ll> > dp(w.size(),vector<ll>(2,INF));
 
  // We start at (1,1)
  dp[0][0] = dmin[w[0]] + 2*dist[0] - 1;
  dp[0][1] = dmax[w[0]] - 1;
 
  int i = 0;
  // t(i,dp[i][0],dp[i][1]);
  for(int i=1;i<w.size();i++)
  {
    ll x1 = dmin[w[i]], x2 = dmax[w[i]];
    ll xp1 = dmin[w[i-1]], xp2 = dmax[w[i-1]];
 
    pair<ll,ll> p1 = dx[x1], p2 = dx[x2];
 
    // t(i,p1,p2);
 
    dp[i][1] = min(dp[i][1],f(x1,x2,p1.fi,1) + abs(p1.fi - xp1) + dp[i-1][0]);
    dp[i][1] = min(dp[i][1],f(x1,x2,p1.fi,1) + abs(p1.fi - xp2) + dp[i-1][1]);
    dp[i][1] = min(dp[i][1],f(x1,x2,p1.se,1) + abs(p1.se - xp1) + dp[i-1][0]);
    dp[i][1] = min(dp[i][1],f(x1,x2,p1.se,1) + abs(p1.se - xp2) + dp[i-1][1]);
    dp[i][1] = min(dp[i][1],f(x1,x2,p2.fi,1) + abs(p2.fi - xp1) + dp[i-1][0]);
    dp[i][1] = min(dp[i][1],f(x1,x2,p2.fi,1) + abs(p2.fi - xp2) + dp[i-1][1]);
    dp[i][1] = min(dp[i][1],f(x1,x2,p2.se,1) + abs(p2.se - xp1) + dp[i-1][0]);
    dp[i][1] = min(dp[i][1],f(x1,x2,p2.se,1) + abs(p2.se - xp2) + dp[i-1][1]);
 
    dp[i][0] = min(dp[i][0],f(x1,x2,p1.fi,0) + abs(p1.fi - xp1) + dp[i-1][0]);
    dp[i][0] = min(dp[i][0],f(x1,x2,p1.fi,0) + abs(p1.fi - xp2) + dp[i-1][1]);
    dp[i][0] = min(dp[i][0],f(x1,x2,p1.se,0) + abs(p1.se - xp1) + dp[i-1][0]);
    dp[i][0] = min(dp[i][0],f(x1,x2,p1.se,0) + abs(p1.se - xp2) + dp[i-1][1]);
    dp[i][0] = min(dp[i][0],f(x1,x2,p2.fi,0) + abs(p2.fi - xp1) + dp[i-1][0]);
    dp[i][0] = min(dp[i][0],f(x1,x2,p2.fi,0) + abs(p2.fi - xp2) + dp[i-1][1]);
    dp[i][0] = min(dp[i][0],f(x1,x2,p2.se,0) + abs(p2.se - xp1) + dp[i-1][0]);
    dp[i][0] = min(dp[i][0],f(x1,x2,p2.se,0) + abs(p2.se - xp2) + dp[i-1][1]);
 
    dp[i][0] += w[i]-w[i-1];
    dp[i][1] += w[i]-w[i-1];
 
    // t(i,dp[i][0],dp[i][1]);
  }
 
  cout << min(dp[w.size()-1][0],dp[w.size()-1][1]) << endl;
 
 
  return 0;
}
 
