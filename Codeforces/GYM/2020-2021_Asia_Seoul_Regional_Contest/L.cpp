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

ll max(ll x, ll y) {return x > y ? x : y;}

ll C(vector<int> &v, ll l, ll r) {
  return (v[l] + v[r]) * (r - l);
}

void DP(vector<int> &v, vector<ll> &dp, int l, int r, int optl, int optr) {
  if(r < l) return;
  int mid = (l + r) >> 1;

  ll &res = dp[mid];
  int optMid = -1;

  for(int i=optl;i<=min(optr, mid);i++) {
    ll tempMid = C(v, i, mid);
    if(tempMid > res) {
      res = tempMid;
      optMid = i;
    }
  }

  DP(v, dp, l, mid - 1, optl, optMid);
  DP(v, dp, mid + 1, r, optMid, optr);
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n);
  vector<ll> dp(n, -1);

  for(int i=0;i<n;i++) cin >> v[i];

  DP(v, dp, 0, n-1, 0, n-1);

  ll ans = 0;
  for(auto it : dp) {
    ans = max(ans, it);
  }

  cout << ans << endl;
  return 0;
}

/*
  '''
  i < j

  (h[i] + h[j]) * (j - i);
  j -> i

  For any j'' > j
  Let i'' < i

  (h[i''] + h[j'']) * (j'' - i'') > (h[i] + h[j'']) * (j'' - i)  - (1)
  And
  (h[i''] + h[j]) * (j - i'') < (h[i] + h[j]) * (j - i)    - (2)

  If eqn 2 is true: 
    (h[i''] + h[j]) * (j - i) < (h[i''] + h[j]) * (j - i'') < (h[i] + h[j]) * (j - i)
    => h[i''] < h[i]
    => diffIndex * h[j] + h[i] * i - h[i''] * i'' < j * diffHeight

    

    (h[i''] + h[j'']) * (j'' - i'') > (h[i] + h[j'']) * (j'' - i)

    0 > j'' * (diffHeight) + h[j''] * diffIndex + h[i''] * i'' - h[i] * i 
      > (diffIndex * h[j] + h[i] * i - h[i''] * i'') + (h[j''] * diffIndex + h[i''] * i'' - h[i] * i )
      => diffIndex * (h[j] + h[j'']) > 0 a contradiction. 

  '''
  */