/*
Rathin Bhargava
IIIT Bangalore

*/
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

bool sorter(const pair<int,int> p1, const pair<int,int> p2)
{
  if(p1.fi + p1.se < p2.fi + p2.se) return true;
  else if(p1.fi + p1.se == p2.fi + p2.se && p1.fi > p2.fi) return true;
  return false;
}

bool check(pair<int,int> p1, pair<int,int> p2)
{
  // Given p1, does p2 exist inside p1 or no?
  return (p2.fi >= p1.fi && p2.se >= p1.se);
}

ll f(pair<int,int> p1, pair<int,int> p2)
{
  int x = abs(p2.fi-p1.fi);
  int y = abs(p2.se-p1.se);
  int ans =  ((fact[x+y] * inv[x]) % MOD * inv[y]) % MOD;
  // t(x,y,fact[x+y]);
  t(p1,p2,ans);
  return ans;
}

void compute()
{
  fact[0] = 1;
  inv[0] = 1;
  for(int i=1;i<=2e5;i++)
  {
    fact[i] = (fact[i-1]*i) % MOD;
    inv[i] = power(fact[i],MOD-2,MOD);
  }
}
int main()
{
  __;
  compute();
  int n,m,k;
  cin >> n >> m >> k;
  vector<pair<int,int> > sq;
  bool zero = false;
  for(int i=0;i<k;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    sq.pu(mp(a,b));
    if(a==0 && b==0) zero = true;
  }

  if(!zero) sq.pu(mp(0,0));

  sort(sq.begin(),sq.end(),sorter);
  reverse(sq.begin(),sq.end());
  
  vector<bool> active(sq.size());
  vector<int> ans(sq.size());
  t(sq);

  for(int i=0;i<sq.size();i++)
  {
    // Computing for the ith pair
    ll cnt = f(sq[i],mp(n-1,m-1));

    for(int j=0;j<sq.size();j++)
    {
      if(active[j] && check(sq[i],sq[j]))
      {
        cnt -= (f(sq[i],sq[j])*f(sq[j],mp(n-1,m-1))) % MOD;
        // cnt -= (f(sq[i],sq[j])*ans[j]) % MOD;
        cnt %= MOD;
        cnt += MOD;
        cnt %= MOD;
        active[j] = false;
      }
    }
    active[i] = true;
    ans[i] = cnt;
  }

  cout << ans[sq.size()-1] << endl;
  return 0;
}

