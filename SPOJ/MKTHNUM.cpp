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
  int n,q;
  cin>>n>>q;
  vector<int> v(n);
  set<int> s;
  map<int,int> d,e;
  for(int i=0;i<n;i++) {cin>>v[i];s.insert(v[i]);}
  vector<pair<pair<int,int>,int > > w(q);
  for(int i=0;i<q;i++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    w[i].fi = mp(a-1,b-1);
    w[i].se = c;
    // s.insert(c);
  }
  // Give ranks
  int counter = 1;
  for(auto it : s) 
  {
    d[it] = counter;
    e[counter] = it;
    counter++;
  }

  // Change all the numbers to their compressed values
  for(int i=0;i<n;i++) v[i] = d[v[i]];
  // for(int i=0;i<q;i++) w[i].se = d[w[i].se];

  BIT bit;
  bit.init(2e5);

  for(int i=0;i<n;i++) bit.inc(v[i],1);
  pr(v);
  for(int i=1;i<=n;i++) cout<<bit.sum(i)<<" ";cout<<endl;

  for(int i=0;i<q;i++)
  {
    int l = w[i].fi.fi, r = w[i].fi.se, c = w[i].se;
    int a = bit.sum(l), b = bit.sum(l-1);
    int val;
    if(a!=b)
    {
      val = a+c-1;
    }
    else
    {
      val = a+c;
    }
    int beg = l, end = r,ans = -1;
    while(beg<=end)
    {
      int mid = (beg+end)>>1;
      if(bit.sum(mid)>=val) {ans = mid; end = mid-1;}
      else beg = mid+1;
    }
    t(i,val,ans);
    cout<<e[ans]<<endl;
  }
  return 0;
}

