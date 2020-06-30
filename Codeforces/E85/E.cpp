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

void primeFactors(ll n,vector<pair<ll,ll> > &v) 
{ 
  int cnt2 = 0;
  while (n%2 == 0) 
  { 
    n = n/2; 
    cnt2++;
  }
  if(cnt2) v.pu(mp(cnt2,2));

  for (int i = 3; i <= sqrt(n); i = i+2) 
  { 
    int cnt = 0;
    while (n%i == 0) 
    { 
      n = n/i; 
      cnt++;
    } 
    if(cnt) v.pu(mp(cnt,i));
  } 
  
  if (n > 2) 
  {
    v.pu(mp(1,n));
  }
}

map<ll,vector<pair<ll,ll> > > d;
set<ll> taken;

void recur(vector<pair<ll,ll> > v, vector<pair<ll,ll> > &w, ll prod)
{
  d[prod] = v;
  taken.insert(prod);
  for(int i=0;i<w.size();i++)
  {
    if(v[i].fi < w[i].fi)
    {
      vector<pair<ll,ll> > temp = v;
      temp[i] = mp(v[i].fi+1,v[i].se);
      if(taken.count(prod*v[i].se)) continue;
      recur(temp,w,prod*v[i].se);
    }
  } 
}

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

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

const int N = 1e5+10;
vector<ll> fact(N),inv(N);

void compute()
{
  fact[0] = inv[0] = 1;
  for(int i=1;i<N;i++) 
  {
    fact[i] = (fact[i-1]*i) % MOD;
    inv[i] = power(fact[i],MOD-2,MOD);
  }
}

int main()
{
  __;
  compute();
  ll n;
  cin >> n;
  vector<pair<ll,ll> > v;
  primeFactors(n,v);
  vector<pair<ll,ll> > w(v.size());
  for(int i=0;i<v.size();i++) w[i].se = v[i].se;
  recur(w,v,1);

  // for(auto it : d) t(it.fi,it.se);

  int q;
  cin >> q;
  while(q--)
  {
    ll a,b;
    cin >> a >> b;
    ll g = gcd(a,b);
    vector<pair<ll,ll> > x,y,z;
    x = d[g];
    y = d[a];
    z = d[b];
    // t(x,y,z);

    ll prod = 1;
    ll sum1 = 0;
    for(int i=0;i<x.size();i++)
    {
      prod *= inv[y[i].fi-x[i].fi];
      prod %= MOD;
      sum1 += y[i].fi-x[i].fi;
      sum1 %= MOD;
      // t(prod,sum1);
    }
    prod *= fact[sum1];
    prod %= MOD;

    ll sum2 = 0;
    for(int i=0;i<v.size();i++)
    {
      prod *= inv[z[i].fi-x[i].fi];
      prod %= MOD;
      sum2 += z[i].fi-x[i].fi;
      sum2 %= MOD;
    }
    prod *= fact[sum2];
    prod %= MOD;

    cout << prod << endl;
  }
  return 0;
}
