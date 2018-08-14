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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

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

ll gcd(ll a, ll b)
{
  if(a==0) return b;
  if(b==0) return a;
  while(b)
  {
    if(a==0) return b;
    if(b==0) return a;
    ll c = a%b;
    a = b;
    b = c;
  }
  return a;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    ll n,a,b;
    scll(a);scll(b);scll(n);
    // cout<<"here"<<endl;
    if(a<b) swap(a,b);
    if(a==b) {cout<<(power(a,n,MOD)+power(b,n,MOD))%MOD<<endl;continue;}
    ll c1 = (power(a,n,abs(a-b)) + power(b,n,abs(a-b)))%(abs(a-b));
    // cout<<"here"<<endl;
    cout<<gcd(c1,abs(a-b))%MOD<<endl;
  }
  return 0;
}
