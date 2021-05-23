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

class PolygonalRegions
{
  public:
  const int N = 105;
  ll fact[N] = {0};
  ll inv[N] = {0};
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
    fact[0] = inv[0] = 1;
    for(int i=1;i<=100;i++)
    {
      fact[i] = (i*fact[i-1]) % MOD;
      inv[i] = power(fact[i],MOD-2,MOD);
    }
  }

  ll C(int n,int r)
  {
    return (((fact[n] * inv[n-r] ) % MOD ) * inv[r]) % MOD;
  }

  int expectedRegions(int n)
  {
    compute();
    vector<ll> regions(N);
    vector<ll> convex(N);
    regions[0] = 1;
    regions[1] = 1;
    regions[2] = 2;
    convex[3] = 1;
    for(int i=4;i<=100;i++)
    {
      convex[i] = convex[i-1] + C(i-1,3) + i;
      convex[i] %= MOD;
    }
    for(int i=3;i<=100;i++) 
    {
      convex[i] += 2;
      convex[i] %= MOD;
    }
    
    vector<vector<ll> > mat(101,vector<ll> (101));
    vector<ll> v(101);
    for(int i=0;i<n;i++)
    {
      v[i] = (i+1)*inv[n];
      v[i] %= MOD;
    }
    
  }
};

int main()
{
  __;

  return 0;
}
