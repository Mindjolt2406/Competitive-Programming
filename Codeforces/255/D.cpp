/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18
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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  int n,m;
  ll k,p;
  cin>>n>>m>>k>>p;
  vector<vector<int> > v(n,vector<int>(m));
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>v[i][j];
  priority_queue<ll> a,b;

  for(int i=0;i<n;i++)
  {
    ll sum1 = 0;
    for(int j=0;j<m;j++) sum1+=v[i][j];
    a.push(sum1);
  }

  for(int j=0;j<m;j++)
  {
    ll sum1 = 0;
    for(int i=0;i<n;i++) sum1+=v[i][j];
    b.push(sum1);
  }

  ll subc = 0,subd = 0;
  ll count = 0;

  vector<ll> x(k+1), y(k+1);
  ll sum1 = 0, sum2 = 0;
  for(int i=1;i<=k;i++)
  {
    ll c = a.top();
    sum1+=c;
    c-=p*m;
    a.pop();
    a.push(c);
    x[i] = sum1;
  }

  for(int i=1;i<=k;i++)
  {
    ll d = b.top();
    b.pop();
    sum2+=d;
    y[i] = sum2;
    d-=p*n;
    b.push(d);
  }

  ll max1 = -INF;
  for(int i=0;i<=k;i++)
  {
    ll c = x[i], d = y[k-i];
    max1 = max(max1,c+d-(p*(k-i)*i));
  } 

  cout<<max1<<endl;
  return 0;
}

