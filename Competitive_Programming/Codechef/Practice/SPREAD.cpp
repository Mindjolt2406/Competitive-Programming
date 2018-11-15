#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

struct BIT
{
  vector<ll> bit;
  int n;

  void init(int n)
  {
    this->n = n;
    bit.assign(n,0);
  }

  ll sum(int i)
  {
    ll res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i];
    }
    return res;
  }

  void inc(int i, int delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]+=delta;
    }
  }

  ll getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<ll> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
};

int main()
{
  typedef struct BIT BIT;
  int n,m;
  ll c;
  sc(n);sc(m);scll(c);
  vector <ll> v;
  v.assign(n+1,0);
  v[0] = c;
  BIT bit;
  bit.init(v);
  for(int h=0;h<m;h++)
  {
    string s;
    scr(s);
    if(s=="Q") 
    {
      int a;
      sc(a);
      a--;
      // cout<<"a-1: "<<bit.sum(a-1)<<" a: "<<bit.sum(a)<<endl;
      cout<<bit.sum(a)<<endl;
    }
    else
    {
      // for(int i=0;i<n;i++) cout<<bit.sum(i)<<" ";cout<<endl;
      int a,b,c;
      sc(a);sc(b);sc(c);
      a--;b--;
      bit.inc(a,c);
      bit.inc(b+1,-1*c);
      // for(int i=0;i<n;i++) cout<<bit.sum(i)<<" ";cout<<endl;
    }
  }
  return 0;
}

