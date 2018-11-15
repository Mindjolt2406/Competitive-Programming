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

ll *fact;
ll *prod;

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

ll comb(int a)
{
  a = (ll)a;
  return ((a*(a-1))/2)%MOD;
}

ll calculate(int a)
{
  ll pr = 1,boo = 0;
  if(a%2==1) {a--;boo = 1;}
  ll c = power(fact[a/2],MOD-2,MOD);
  pr = (prod[a]*c)%MOD;
  if(boo) {pr*=(a+1);pr%=MOD;}
  // cout<<a<<" "<<pr<<endl;
  return pr;
}

int main()
{
  fact = (ll*)calloc(1000001,sizeof(ll));
  prod = (ll*)calloc(1000001,sizeof(ll));
  fact[0] = 1;
  prod[2] = 1;
  prod[0] = 1;
  // cout<<prod[1000000]<<endl;
  for(int i=4;i<=1000000;i+=2) {prod[i] = comb(i);prod[i]*=prod[i-2];prod[i]%=MOD;}
  for(int i=1;i<=1000000;i++) {fact[i] = i*fact[i-1];fact[i]%=MOD;}
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    map<int,int> :: iterator it;
    map<int,int> d;
    for(int i=0;i<n;i++) 
    {
      sc(l[i]);
      if(d.find(l[i])!=d.end()) d[l[i]]++;
      else d[l[i]] = 1;
    }
    vector<int> v;
    for(it = d.begin();it!=d.end();it++)
    {
      v.pu(it->first);
    }
    int i = v.size()-1;
    ll count2 = 1;
    int boo = 1;

    while(i>=0)
    {
      // cout<<"i: "<<i<<" count: "<<count<<endl;
      int a = d[v[i]];
      count2*=calculate(a);
      count2%=MOD;
      i--;
      // if(a%2==0) 
      // {
      //   count2*=calculate(a);
      //   count2%=MOD;
      // }
      // else 
      // {
      //   if(i>0) i--;
      //   else {boo = 0;break;}
      //   int b = d[v[i]];
      //   if(b%2==1)
      //   {
      //     // Odd and Odd
      //     if(a!=1) count2*=calculate(a); count2%=MOD;
      //     if(b!=1) count2*=calculate(b); count2%=MOD;
      //   }
      //   else if(b%2==0) {boo = 0;break;}
      // }
      // i--;
      // count2*=count;
    }
    // if(!boo) cout<<0<<endl;
    cout<<count2<<endl;
  }
  return 0;
}

