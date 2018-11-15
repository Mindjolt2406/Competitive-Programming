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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

struct BIT //ll
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

  void inc(int i, ll delta)
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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int bsearch1(BIT bit1,BIT bit2,int start,int n, ll value)
{
  int beg=  start,end = n-1,mid;
  int max1 = -1;
  while(beg<=end)
  {
    mid = (beg+end)/2;
    if(bit1.getsum(mid,end)<=value) {max1 = max(max1,mid);beg = mid+1;}
    else end = mid-1;
  }
  return max1;
}

int main()
{ 
  typedef struct BIT BIT;
  BIT bit1,bit2;
  int n;
  ll total,sum1 =0, count = 0;
  sc(n);scll(total);
  ll counter = n;
  vector<ll> v,v2;
  v.assign(n,0);
  v2.assign(n,1);
  for(int i=0;i<n;i++) {scll(v[i]);sum1+=v[i];}
  if(sum1>=total)
  { 
    count+=(total/sum1)*n;
    total-=n*sum1;
  } 
  bit1.init(v);
  bit2.init(v2);
  cout<<bit2.sum(2)<<endl;
  int top = 0;
  while(counter)
  {
    ll sum2 = bit1.sum(n-1);
    if(sum2>=total)
    { 
      count+=(total/sum2)*bit2.sum(n-1);
      total-=bit2.sum(n-1)*sum2;
    }
    int prevc = top;
    top = bsearch1(bit1,bit2,top,n,total);
    int c = top;
    top++;
    if(top>=n) top = 0;
    else
    {
      if(c!=-1)
      {
        total-=bit1.getsum(prevc,c);
        count+=bit2.getsum(prevc,c);
      }
      bit1.inc(top,v[top]*(-1));
      bit2.inc(top,-1);
      counter--;
    }
  }
  cout<<count<<endl;
  return 0;
}

