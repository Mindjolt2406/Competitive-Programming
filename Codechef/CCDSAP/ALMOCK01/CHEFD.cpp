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

typedef struct BIT //int
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

  int getsum(int l,int r)
  {
    // If l==0, sum(-1) automatically returns the default calue of res, 0
    return sum(r)-sum(l-1);
  }

  void init(vector<int> v)
  {
    init(v.size());
    for(int i=0;i<v.size();i++) inc(i,v[i]);
  }
} BIT;

int main()
{
  __;
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];

  // vector<int> x(n+10),y(n+10),z(n+10);
  int q;
  cin>>q;

  BIT x,y,z;
  x.init(n+10); y.init(n+10); z.init(n+10);
  vector<int> w(n);
  while(q--)
  {
    // t(q);
    int a;
    cin>>a;
    if(a==1)
    {
      int l,r,d;
      cin>>l>>r>>d;
      l--;r--;
      if(d==2)
      {
        x.inc(l,1); x.inc(r+1,-1);
      }
      if(d==3)
      {
        y.inc(l,1); y.inc(r+1,-1);
      }
      if(d==5)
      {
        z.inc(l,1); z.inc(r+1,-1);
      }
    }
    else
    {
      int a,b;
      cin>>a>>b;
      a--;
      v[a] = b;
      // x.inc(a,-1*x.sum(a));
      // y.inc(a,-1*y.sum(a));
      // z.inc(a,-1*z.sum(a));
      // x[a] = y[a] = z[a] = 0;
    }
  }

  // pr(x);
  for(int i=0;i<n;i++)
  {
    // t(i,v[i],x[i]);
    int a = x.sum(i), b = y.sum(i), c = z.sum(i);
    // t(a,b,c);
    while(v[i]%2==0 && a>0)
    {
      a--;
      v[i]/=2;
    }
    while(v[i]%3==0 && b>0)
    {
      b--;
      v[i]/=3;
    }
    while(v[i]%5==0 && c>0)
    {
      c--;
      v[i]/=5;
    }
  }

  for(int i=0;i<n;i++) cout<<v[i]<<" "; cout<<endl;
  return 0;
}

