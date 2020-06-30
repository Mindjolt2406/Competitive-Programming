#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
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

const int N = 2e5+10;
vector<ll> fact(N);
vector<ll> inv(N);

ll power(ll x, ll y, ll p)
{
	ll res = 1;      // Initialize result
	x = x % p;  // Update x if it is more than or
	while (y > 0)
	{
			if (y & 1)
					res = (res*x) % p;
			y = y>>1; // y = y/2
			x = (x*x) % p;
	}
	return res;
}

void compute()
{
  fact[0] = 1;
  inv[0] = 1;
  for(int i=1;i<N;i++)
  {
    fact[i] = i*fact[i-1];
    fact[i] %= MOD;
    inv[i] = power(fact[i],MOD-2,MOD);
  }
}

ll C(ll n, ll r)
{
  if(n<0) return 0;
  if(r>n) return 0;
  // t(n,r);
  ll a =fact[n];
  ll b = (inv[r]*inv[n-r]) % MOD;
  // t(a,b);
  return (a*b) % MOD;
}

int main()
{
  __;
  compute();
  int n,m;
  cin >> n >> m;
  // cout << C(m,n-1) << endl;
  ll sum1 = 0;
  for(int i=n-1;i<=m;i++)
  {
    sum1 += C(i-1,n-2);
    sum1 %= MOD;
    // t(i,sum1);
  }

  // t(sum1);
  // sum1 *= (n-2);
  // sum1 %= MOD;
  sum1 *= (power(2,n-2,MOD));
  sum1 %= MOD;

  sum1 *= (n-2);
  sum1 %= MOD;

  sum1 *= power(2,MOD-2,MOD);
  sum1 %= MOD;
  // sum1 *= power(n-2,MOD-2,MOD);
  // sum1 %= MOD;
  // for(int k=1;k<=m;k++)
  // {
  //   // t(k);
  //   for(int i=1;i<=n-2;i++)
  //   {
  //     // t(i);
  //     int left = i;
  //     // t(k-1,i);
  //     ll a = C(k-1,i);
  //     // t(a);
  //     ll b = i;
  //     ll c = C(k-1-i,n-i-2);
  //     // t(a,b,c);
  //     sum1 += (((a*b) % MOD) * c) % MOD;
  //     sum1 %= MOD;
  //   }
  // }

  cout << sum1 << endl;
  return 0;
}
