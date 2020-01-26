/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

bool check(ll mid, vector<ll> &v,ll k)
{
  ll cnt = 0; // Number of groups being made
  ll n = v.size();
  ll max1 = INF;
  ll sz = 1;
  ll cost = INF;
  
  for(ll i=0;i<n;i++)
  {
    max1 = max(max1,v[i]);
    sz++;
    cost = max1*sz;
    
    if(cost > mid) 
    {
      cnt++;
      cost = v[i];
      sz = 1;
      max1 = v[i];
    } 
    // t(i,max1,cost,cnt);
  }

  if(cnt > k) return false;
  return true; 
}

int32_t main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    ll max2 = 0;
    for(int i=0;i<n;i++) {cin >> v[i];max2 = max(max2,v[i]);}

    ll beg = max2, end = 1e15, ans = 1e15;
    while(beg<=end)
    {
      ll mid = (beg+end)>>1;
      bool boo = check(mid,v,k);
      // t(mid,boo);
      if(boo) {ans = mid; end = mid-1;}
      else beg = mid+1;
    }

    cout << ans << endl;

  }  
  return 0;
}

