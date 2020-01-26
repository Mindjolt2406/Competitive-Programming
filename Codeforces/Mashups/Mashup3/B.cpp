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
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

typedef struct BIT //ll
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

  vector<ll>& getBit() {return bit;}
} BIT;

int bsearch1(ll value, BIT &bit)
{
  int beg = 0, end = bit.n-1;
  int max1 =-1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(bit.sum(mid)<=value) {max1 = mid; beg = mid+1;}
    else end = mid-1;
  }
  // t(value,max1);
  return max1;
}

int main()
{
  typedef struct BIT BIT;
  int n;
  sc(n);
  ll k; scll(k);
  vector<ll> v;
  for(int i=0;i<n;i++) {ll a;scll(a);v.pu(a);}
  BIT bit;
  bit.init(v);
  int counter = n;
  ll count = 0;
  while(counter)
  {
    ll a = bit.getsum(0,n-1);
    if(a==0) break;
    if(k>=a) {count+=(k/a)*counter;k%=a;}
    // t(a,counter,k);
    // vector<int> keep;
    while(bit.sum(n-1)!=0)
    {
      // for(int i=0;i<n;i++) cout<<bit.sum(i)<<endl;
      int index = bsearch1(k,bit);
      // t(index);
      if(index==n-1) break;
      index++;
      bit.inc(index,-1*v[index]);
      counter--;
    }
  }
  cout<<count<<endl;
  // int q;
  // sc(q);
  // for(int h=0;h<q;h++)
  // {
  //   cout<<bit.getsum(0,4)<<endl;
  //   bit.inc(0,5);
  //   cout<<bit.getsum(0,4)<<endl;
  // }
  return 0;
}


