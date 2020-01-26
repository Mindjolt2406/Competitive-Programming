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

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<vector<ll> > a(n,vector<ll>(m));
  vector<vector<ll> > b(n,vector<ll>(m));
  vector<vector<ll> > c(n,vector<ll>(m));
  vector<vector<ll> > d(n,vector<ll>(m));
  vector<vector<ll> > v(n,vector<ll>(m));

  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];

  // a[n-1][m-1] = v[n-1][m-1];
  // b[n-1][0] = v[n-1][0];
  // c[0][m-1] = v[0][m-1];
  // d[0][0] = v[0][0];

  for(int i=n-1;i>=0;i--) 
  {
    for(int j=m-1;j>=0;j--) 
    {
      if(i+1<n) a[i][j] = max(a[i][j],a[i+1][j]);
      if(j+1<m) a[i][j] = max(a[i][j],a[i][j+1]);
      a[i][j]+=v[i][j];
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(i>0) d[i][j] = max(d[i][j],d[i-1][j]);
      if(j>0) d[i][j] = max(d[i][j],d[i][j-1]);  
      d[i][j]+=v[i][j];
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=m-1;j>=0;j--)
    {
      if(i>0) c[i][j] = max(c[i][j],c[i-1][j]);
      if(j+1<m) c[i][j] = max(c[i][j],c[i][j+1]);
      c[i][j]+=v[i][j];
    }
  }

  for(int i=n-1;i>=0;i--)
  {
    for(int j=0;j<m;j++)
    {
      if(i+1<n) b[i][j] = max(b[i][j],b[i+1][j]);
      if(j>0) b[i][j] = max(b[i][j],b[i][j-1]);
      b[i][j]+=v[i][j];
    }
  }

  ll max1 = -1;
  for(int i=1;i<n-1;i++)
  {
    for(int j=1;j<m-1;j++)
    {
      ll k = max1;
      // A comes from the left
      max1 = max(max1,d[i][j-1]+a[i][j+1]+b[i+1][j]+c[i-1][j]);
      // B comes from the left
      max1 = max(max1,b[i][j-1]+c[i][j+1]+a[i+1][j]+d[i-1][j]);
    }
  }

  cout<<max1<<endl;
  return 0;
}

