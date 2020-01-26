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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

ll f(vector<ll> &a,ll m)
{
  vector<ll> v(a.size());
  for(int i=0;i<a.size();i++) v[i] = a[i];
  vector<ll> w(v.size());
  for(int i=0;i<v.size();i++) w[i] = v[i];
  for(int i=1;i<w.size();i++)
  {
    if(w[i]<w[i-1]+w[i]) w[i] = w[i-1]+w[i];
  }

  // v is pref, w is the dp array
  for(int i=1;i<v.size();i++) v[i]+=v[i-1];

  set<pair<ll,ll> > s;
  for(int i=1;i<v.size();i++) s.insert(mp(v[i],i));

  ll error = 0;
  ll max1 = 0;
  for(int i=0;i<v.size();i++)
  {
    ll a;
    if(i>0) a = w[i-1];
    else a = 0;
    // t(a,i);
    if(m<0)
    {
      ll c = a;
      ll b = (*s.begin()).fi;
      // t(b,error);
      b+=error;
      b*=m; // b*m is hopefully positive
      a = max(a,a+b);
      // t(a,b);
      b = (*s.rbegin()).fi;
      b+=error;
      a = max(a,c+b);
      // t(a);
    } 
    else if(m!=0)
    {
      ll c = a;
      ll b = (*s.begin()).fi;
      b+=error;
      a = max(a,a+b);
      b = (*s.rbegin()).fi;
      b+=error;
      b*=m;
      a = max(a,c+b);
    }
    error = -1*v[i];
    s.erase(mp(v[i],i));
    max1 = max(max1,a);
    // t(max1);
  }

  for(int i=0;i<w.size();i++) max1 = max(max1,w[i]);


  return max1;
}

pair<ll,ll> g(vector<ll> a)
{
  vector<ll> v(a.size());
  for(int i=0;i<a.size();i++) v[i] = a[i];
  ll max1 = max(v[0],0);
  for(int i=1;i<v.size();i++)
  {
    if(v[i]<v[i-1]+v[i]) v[i] = v[i-1]+v[i];
  }

  int max2 = -1;
  for(int i=0;i<v.size();i++) {max1 = max(max1,v[i]);if(max1==v[i]) max2 = i;}

  return mp(max1,max2);
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<ll> v(n);
  vector<ll> w(n);
  for(int i=0;i<n;i++) {cin>>v[i];w[i] = -1*v[i];}
  if(m!=0)
  {
    ll a = f(v,m);
    reverse(v.begin(),v.end());
    a = max(a,f(v,m));
    cout<<a<<endl;;
  }
  else
  {
    ll a = f(v,m);
    reverse(v.begin(),v.end());
    a = max(a,f(v,m));
    reverse(v.begin(),v.end());
    pair<ll,ll> p = g(w);
    ll b = p.fi*(-1);
    ll sum1 = p.fi, left = -1,right = p.se;
    b = b*m;
    if(p.se!=-1)
    {
      for(int i=right;i>=0 && sum1!=0;i--)
      {
        sum1-=w[i];
        if(sum1==0) left = i;
      }
      t(left,right);
      if(left!=-1 && right!=-1)
      {
        for(int i=left;i<=right;i++) v[i]*=m;
        a = max(a,g(v).fi); 
      }
    }
    cout<<max(a,b)<<endl;
  }
  return 0;
}

