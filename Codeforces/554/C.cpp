/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
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

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

ll lcm(ll a, ll b)
{
  return (a*b)/(gcd(a,b));
}

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  __;
  ll a,b;
  cin>>a>>b;
  ll c = abs(a-b);
  if(a==b) {cout<<0<<endl;return 0;}
  ll min1 = INF,min2 = INF;
  for(int i=1;i<=sqrt(c);i++)
  {
    if(c%i==0)
    {
      ll d = a%i;
      // t(a,i,d);
      if(d==0) 
      {
        min1 = min(min1,lcm(a,b)); 
        if(min1==lcm(a,b)) min2 = 0;
      }
      else 
      {
        min1 = min(min1,lcm(a+i-d,b+i-d)); 
        if(min1==lcm(a+i-d,b+i-d)) min2 = i-d;
      }
      // t(d,i,min1,min2);
      d = a%(c/i);
      if(d==0) 
      {
        min1 = min(min1,lcm(a,b)); 
        if(min1==lcm(a,b)) min2 = 0;
      }
      else 
      {
        min1 = min(min1,lcm(a+(c/i)-d,b+(c/i)-d)); 
        if(min1==lcm(a+(c/i)-d,b+(c/i)-d)) min2 = c/i - d;
      }
      // t(d,c/i,min1,min2);
    }
  }

  cout<<min2<<endl;
  return 0;
}

