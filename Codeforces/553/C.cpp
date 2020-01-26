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

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int log2(ll n)
{
  int count = 0;
  while(n!=1)
  {
    n>>=1;
    count++;
  }
  return count;
}

ll f(ll n)
{
  if(n==0) return 0;
  // Bring it to the closest power of 2 please
  if(n+1==pow(2,log2(n+1)))
  {

    ll a = log2(n+1);
    ll b = a/2, c = a-a/2;
    // t(n,a,b,c);
    // c is for odd, b is for even
    ll sumc = (pow(4,c)-1)/3;
    ll sumb = 2*((pow(4,b)-1)/3);
    sumc%=MOD;sumb%=MOD;
    ll ansc = (sumc*sumc)%MOD;
    ll ansb = ((((sumb+1))%MOD)*(sumb))%MOD;
    return (ansc+ansb)%MOD;
  }
  ll a = log2(n);
  ll b = a/2, c = a-a/2;
  ll d = n-pow(2,a)+1;
  // t(a,b,c,d,n);
  // c is for odd, b is for even
  // ll sumc = (power(4,c,INF) -1 + INF)%INF*power(3,INF-2,INF);
  // sumc%=INF;
  // ll sumb = (2*((power(4,b,INF)-1)+INF))%INF*power(3,INF-2,INF);
  // sumb%=INF;
  ll sumc = (pow(4,c)-1)/3;
  ll sumb = 2*((pow(4,b)-1)/3);
  if(a%2==1) sumb+=d;
  else sumc+=d;
  sumc%=MOD;sumb%=MOD;
  ll ansc = (sumc*sumc)%MOD;
  ll ansb = (((sumb+1)%MOD)*(sumb))%MOD;
  return (ansc+ansb)%MOD;
}

int main()
{
  __;
  ll a,b;
  cin>>a>>b;
  ll c = f(b),d = f(a-1); 
  // t(f(b),f(a-1));
  // t(c,d);
  cout<<((c-d)%MOD+MOD)%MOD<<endl;
  return 0;
}

