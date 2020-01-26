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

ll convert(vector<int> &v)
{
  ll prod = 1;
  ll cnt = 0;
  for(int i=0;i<v.size();i++)
  {
    if(v[i]) cnt+=prod;
    prod<<=1;
  }
  return cnt;
}

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  ll n,m;
  cin>>n>>m;
  vector<int> v(61),w(61),x(61),y(61);
  ll a=n,b=m;
  int cnt1 = 0, cnt2 = 0;
  while(a)
  {
    v[cnt1] = a&1;
    a>>=1;
    cnt1++;
  }

  while(b)
  {
    w[cnt2] = b&1;
    b>>=1;
    cnt2++;
  }

  reverse(v.begin(),v.end());
  reverse(w.begin(),w.end());

  // b>a
  int boo1 = 0,boo2 = 0;
  for(int i=0;i<v.size();i++)
  {
    if(!boo1) // Till now they are same
    {
      if(v[i]==w[i]) continue;
      else if(v[i]==0 && w[i]==1) {x[i] = 1;boo1 = 1;}
    }
    else if(!boo2) // Now, b > a, but we still haven't changed b at all
    {
      if(w[i]==0) x[i] = v[i];
      else if(v[i]==0) x[i] = 1;
      else
      {
        x[i] = 1;
        boo2 = 1;
      }
    }
    else
    {
      x[i] = 1;
    }
  }

  reverse(x.begin(),x.end());
  ll max1 = convert(x);

  boo1 = 0, boo2 = 0;
  for(int i=0;i<v.size();i++)
  {
    if(!boo1)
    {
      if(v[i]==w[i]) continue;
      else if(v[i]==0 && w[i]==1){y[i] = 1;boo1 = 1;}
    }
    else if(!boo2)
    {
      // t(i,v[i],w[i]);
      if(v[i]==1 && w[i]==0) y[i] = 1;
      else if(v[i]==1 && w[i]==1) y[i] = 0;
      else if(v[i]==0 && w[i]==1) y[i] = 1;
      else
      {
        boo2 = 1;
        y[i] = 1;
      } 
    }
    else
    {
      y[i] = 1;
    }
  }

  // pr(y);
  reverse(y.begin(),y.end());
  ll max2 = convert(y);

  // t(max1,max2);
  cout<<max(max1,max2)<<endl;
  return 0;
}

