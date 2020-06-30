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

vector<vector<ll> > dp(15,vector<ll>(10));
vector<ll> dp_sum(15);

ll power(ll x, ll y)
{
	ll res = 1;      // Initialize result
	x = x;  // Update x if it is more than or
	while (y > 0)
	{
			if (y & 1)
					res = (res*x);
			y = y>>1; // y = y/2
			x = (x*x);
	}
	return res;
}

ll brute(ll n)
{
  string s = to_string(n);
  ll cnt = 0;
  for(int i=0;i<s.size();i++)
  {
    for(int j=i+1;j<s.size();j++)
    {
      if(s[j] > s[i]) cnt++;
    }
  }
  return cnt;
}
// ll f(ll n)
// {

// }

ll C(int n,int r)
{
  ld a = 1;
  for(int i=1;i<=r;i++) 
  {
    a *= (n-i+1);
    a /= i;
  }
  t(n,r,a);
  return a;
}

int main()
{
  __; 
  
  ll cnt = 0;
  for(int i=0;i<=1000;i++) cnt += brute(i);
  t(cnt);
  for(int i=1;i<15;i++)
  {
    ll cnt = dp_sum[i-1];
    // ll cnt = 0;
    for(int j=0;j<10;j++)
    {
      for(int k=1;k<=i;k++)
      {
        dp[i][j] += power(j,k) * power((10-j),(i-k)) * k ;
      }
      cnt += dp[i][j];
    }
    dp_sum[i] += cnt;
  }

  t(dp);
  t(dp_sum);

  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    ll a,b;
    cin >> a >> b;
    a--;

  }
  return 0;
}
