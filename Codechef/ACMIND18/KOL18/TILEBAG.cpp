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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


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

ll f(ll u, ll v)
{
  return (power(u,MOD-2,MOD)*v)%MOD;
}

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    ll a,b,s;
    scll(a);scll(b);scll(s);
    ll u,v;
    scll(u);scll(v);
    ll d,x;
    set<ll> se;
    ll prod = 1;
    for(int i=0;i<62;i++) {se.insert(prod);prod*=2;}
    if(s%a==0 && se.find(s/a)!=se.end()) 
    {
      d = s/a;
      x = f(u,v);
    }
    else if(s%b==0)
    {
      d = s/b;
      ll x1 = v-u, y = v;
      ll g = gcd(x1,y);
      x1/=g;y/=g;
      // t(x1,y,g);
      x = f(x1,y);
    }
    else {cout<<0<<endl;continue;}
    d%=MOD;
    cout<<(d*x)%MOD<<endl;
  }
  return 0;
}
