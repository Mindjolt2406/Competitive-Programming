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

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);
    int max1 = -1;
    for(int i=0;i<n;i++) 
    {
      cin >> v[i];
      max1 = max(max1,v[i]);
    }

    const int N = 1e6;
    vector<ll> d(N),e(N);

    for(int i=0;i<n;i++) d[v[i]]++;

    for(int i=1;i<=max1;i++)
    {
      for(int j=i;j<=max1;j+=i)
      {
        e[i] += d[j];
        e[i] %= MOD;
      }
    }

    for(int i=max1;i>=1;i--)
    {
      if(!e[i]) continue;
      e[i] *= e[i];
      e[i] %= MOD;
      for(int j=2*i;j<=max1;j+=i)
      {
        e[i] -= e[j];
        e[i] = (e[i] + MOD) % MOD;
      }
    }

    ll sum1 = 0;
    // for(int i=0;i<e.size();i++) if(e[i]) t(i,e[i]);
    for(int i=0;i<e.size();i++)
    {
      sum1 += (1LL*i*e[i]) % MOD;
      sum1 %= MOD;
    }

    // cout << sum1 << endl;
    sum1 *= power(n,MOD-2,MOD);
    sum1 %= MOD;
    sum1 *= power(n,MOD-2,MOD);
    sum1 %= MOD;
    // cout << sum1 << endl;

    ll k = (1LL*(n+1))*(2*n+1);
    k %= MOD;
    k *= power(6,MOD-2,MOD);
    k %= MOD;
    sum1 *= k;
    sum1 %= MOD;
    cout << sum1 << endl;
  }
  return 0;
}
