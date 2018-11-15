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

ll compute(int a,int b,ll*fact)
{
  ll c1 = fact[a+b];
  ll c2 = (fact[a]*fact[b])%MOD;
  return (c1*power(c2,MOD-2,MOD))%MOD;
}

int main()
{
  int a,b,k;
  sc(a);sc(b);sc(k);
  ll*fact = new ll[200010];
  fact[0] = 1;
  for(int i=1;i<200001;i++) fact[i] = (fact[i-1]*(i))%MOD;
  if(k==1)
  {
    int a1,b1;
    sc(a1);sc(b1);
    if((a1==1 && b1==1) || (a1==a && b1==b)) cout<<0<<endl;
    else cout<<(compute(a-1,b-1,fact)-(compute(a1-1,b1-1,fact)*compute(a-a1,b-b1,fact))%MOD + MOD)%MOD<<endl;
  }
  else
  {
    cout<<compute(a-1,b-1,fact)<<endl;
  }
  return 0;
}
