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

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n+1];
  int*visited = (int*)calloc(n+1,sizeof(int));
  for(int i=1;i<=n;i++) sc(l[i]);
  vector<ll> v;
  for(int i=1;i<n+1;i++)
  {
    if(visited[i]) continue;
    visited[i] = 1;
    ll count = 1;
    int k = l[i];
    int c = l[l[i]];
    visited[c] = 1;
    // cout<<l[i]<<endl;
    while(c!=l[i]) 
    {
      // cout<<"c: "<<c<<endl;
      count++;
      c = l[c];
      visited[c] = 1;
    }
    // for(int i=1;i<=n;i++) cout<<visited[i]<<" ";cout<<endl;
    v.pu(count);
  }
  ll g = v[0];
  ll prod = g;
//   for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  for(int i=1;i<v.size();i++)
  {
    ll c = (g*v[i])%MOD;
    g = gcd(max(g,v[i]),min(g,v[i]));
    // cout<<"c: "<<c<<" g: "<<g<<endl;
    prod*= (c*power(g,MOD-2,MOD))%MOD;
    prod%=MOD;
  }
  cout<<prod<<endl;
  return 0;
}

