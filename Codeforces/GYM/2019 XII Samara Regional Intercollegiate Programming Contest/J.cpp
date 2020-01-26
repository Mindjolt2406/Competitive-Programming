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

int bsearch(vector<ll> &x,ll val)
{
  int beg = 0, end = x.size()-1,ans = -1;
  while(beg<=end)
  {
    int mid = (beg+end)>>1;
    if(x[mid]<=val) {ans = mid; beg = mid+1;}
    else end = mid-1;
  }
  return ans+1; // Number of elements
}

int main()
{
  __;
  int n;
  cin>>n;
  vector<ll> v(n),w(n),x(n);
  for(int i=0;i<n;i++)
  {
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll> x = {a,b,c};
    sort(x.begin(),x.end());
    w[i] = x[0]+x[1];
    v[i] = a+b+c;
  }

  for(int i=0;i<n;i++) x[i] = w[i];
  sort(x.begin(),x.end());
  
  for(int i=0;i<n;i++)
  {
    ll val = v[i];
    val-=2;
    int rank = bsearch(x,val);
    if(w[i]<=val) rank--;
    cout<<rank<<" ";
  }
  cout<<endl;
  return 0;
}

