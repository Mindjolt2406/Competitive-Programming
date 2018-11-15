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
  vector<ll*> bit;
  int n;

  void init(int n,int k)
  {
    this->n = n;
    for(int i=0;i<n;i++)
    {
      ll*l = (ll*)calloc(k+2,sizeof(ll));
      // int*l = new int[k+1];
      bit.pu(l);
    }
  }

  ll sum(int i,int j)
  {
    ll res = 0;
    for(;i>=0;i = (i&(i+1)) -1)
    {
      res+=bit[i][j];
    }
    return res;
  }

  void inc(int i, int j,ll delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i][j]+=delta;
    }
  }

  int getsum(int l,int r,int j)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r,j)-sum(l-1,j);
  }

  void init(vector<int> v,int k)
  {
    int*l = new int[k+2];
    // inc()
    // for(int i=0;i<v.size();i++) inc(v[i],1,1);
    for(int i=0;i<v.size();i++)
    {
      ll c = 0;
      this->inc(v[i],1,1);
      for(int j=1;j<=k;j++)
      { 
        c = sum(v[i]-1,j);
        inc(v[i],j+1,c);
      }
    }
  }
};

int main()
{
  typedef struct BIT fen;
  int n,k;
  sc(n);sc(k);
  vector<int> v1;
  v1.assign(n,0);
  for(int i=0;i<n;i++) sc(v1[i]);
  int max1 = -1;
  for(int i=0;i<n;i++) {max1 = max(max1,v1[i]);}
  fen bit;
  bit.init(max1+1,k);
  // bit.inc(min1,1,1);
  bit.init(v1,k);
  ll count = bit.sum(max1,k+1);
  cout<<count<<endl;
  return 0;
}