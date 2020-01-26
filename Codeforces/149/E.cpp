/*
Rathin Bhargava
IIIT Bangalore

*/

// Took 2 hints, by glancing at the editorial. First, consider the bits separately and 2, something about 2^j. 
// Putting 2 and 2 together I realised that by counting the number of 1s in the ith bit, the sum was n*2^i. 

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

const int N = 1e5+10, LOG = 25;

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
      res^=bit[i];
    }
    return res;
  }

  void inc(int i, ll delta)
  {
    for(;i<n;i = i|(i+1))
    {
      bit[i]^=delta;
    }
  }

  ll getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)^sum(l-1);
  }

  void init(vector<ll> v)
  {
    init(v.size());
  }
} BIT;

vector<BIT> v(LOG);

int main()
{
  __;
  int n;
  cin>>n;
  vector<int> l(n);
  for(int i=0;i<n;i++) cin>>l[i];

  for(int i=0;i<n;i++) v[i].init(n);
  for(int i=0;i<n;i++)
  {
    int a = l[i];
    int counter = 0;
    while(a)
    {
      if(a&1)
      { 
        v[counter].inc(i,1);
      }
      a>>=1;
      counter++;
    }
  }

  
  int q;
  cin>>q;
  while(q--)
  {
    t(q);
    int a;
    cin>>a;
    if(a==1)
    {
      int prod = 1;
      ll sum1 = 0;
      int l,r;
      cin>>l>>r;
      l--;r--;
      for(int i=0;i<LOG;i++)
      { 
        int a = v[i].getsum(l,r);
        sum1+=prod*a;
        prod<<=1;
      }
      cout<<sum1<<endl; 
    }
    else
    {
      int l,r,x;
      cin>>l>>r>>x;
      l--;r--;
      int counter = 0;
      while(x)
      {
        if(x&1) {v[counter].inc(l,1); v[counter].inc(r+1,1);}
        x>>=1;
        counter++;
      }
    }
  }
  return 0;
}

