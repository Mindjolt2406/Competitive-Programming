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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}


ll f(ll k)
{
  int n = 0;
  ll k1 = k;
  while(k1) {n++;k1/=10;}

  ll cnt = 0;
  for(int i=1;i<n;i++)
  {
    cnt+=(pow(10,i)-pow(10,i-1))*i;
  }

  cnt += (k-pow(10,n-1)+1)*n;
  return cnt;
}

int main()
{
  __;
  ll k;
  cin>>k;

  ll beg = 1, end = pow(10,12),ans = 0;
  while(beg<=end)
  {
    ll mid = (beg+end)>>1;
    ll a = f(mid);
    if(a>=k) {ans = mid; end = mid-1;}
    else beg = mid+1;
  }

  int n = 0;
  ll k1 = ans;
  while(k1) {n++;k1/=10;}
  ll a = f(ans);
  a-=n;
  string s = to_string(ans);
  // t(s);
  // t(a,k);
  cout<<s[k-a-1]<<endl;
  return 0;
}

