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
#define ll long long int
#define ld long double
#define fi first
#define se second
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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 2e5+5000;

typedef struct BIT //ll
{
  vector<int> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  int sum(int i)
  {
    int res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
      if(res>=MOD) res-=MOD;
    }
    return res;
  }

  void inc(int i, ll delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
      if(bit[i]>=MOD) bit[i]-=MOD;
    }
  }

  ll getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    int a = sum(r)-sum(l-1);
    a+=MOD;
    if(a>=MOD) a-=MOD; 
    return a;
  }
} BIT;

int main()
{
  __;
  int a,b,k,t;
  cin>>a>>b>>k>>t;

  BIT bit1,bit2;
  // vector<ll> vec1(N),vec2(N);
  int zero = 1e5+1100;
  int min_index = zero - k-1;
  int max_index = zero + 102 +k;
  bit1.init(N);
  bit2.init(N);

  bit1.inc(zero+a,1);
  bit2.inc(zero+b,1);

  ll x[N] = {0}, y[N] = {0};

  while(t--)
  {
    // for(int i=k;i<N-k-1;i++)
    for(int i=min_index;i<max_index;i++)
    {
      x[i] = bit1.getsum(i-k,i+k);
      y[i] = bit2.getsum(i-k,i+k);
    }

    int z = -1;
    // for(int i=zero-k*t-1;i<zero+k*t+1;i++)
    // for(int i=k;i<N-k+1;i++) 
    for(int i=min_index;i<max_index;i++)
    {
      int a = bit1.sum(i)-bit1.sum(i-1);
      a+=MOD;
      if(a>=MOD) a-=MOD;
      a = x[i] - a;
      a+=MOD;
      if(a>=MOD) a-=MOD;
      bit1.inc(i,a);

      int b = bit2.sum(i)-bit2.sum(i-1) + MOD;
      if(b>=MOD) b-=MOD;
      b = y[i] - b + MOD;
      if(b>=MOD) b-=MOD;
      bit2.inc(i,b);
    }
    min_index-=k;
    max_index+=k;

    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
  }

  ll cnt = 0;
  // for(int i=zero-k*t-1;i<zero+k*t+1;i++)
  // for(int i=k;i<max_index;i++)
  for(int i=k;i<N-k-1;i++)
  {
    // t(i);
    ll a = (bit1.sum(i)-bit1.sum(i-1)+MOD);
    if(a>=MOD) a-=MOD;
    cnt+= (a*bit2.sum(i-1)) % MOD;
    if(cnt>=MOD) cnt-=MOD;
  }

  cout<<cnt<<endl;
  return 0;
}

/*
1 100 1000 100 

42 42 42 42

*/