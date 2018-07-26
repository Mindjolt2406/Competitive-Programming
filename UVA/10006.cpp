#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>
#define sc(n) scanf("%d",&n);

using namespace std;

bitset<66000> bs;
int size = 65999;
vi prime;

void sieve()
{
  bs.set();
  bs.set(0,false);bs.set(1,false);
  for(ll i=0;i<size;i++)
  {
    if(bs[i])
    {
      for(ll j=i*i;j<size;j+=i)
      {
        bs[j] = false;
      }
      prime.pu((int)i);
    }
  }
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

int main()
{
  sieve();
  int n;
  sc(n);
  while(n)
  {
    // cout<<"n: "<<n<<endl;
    if(bs[n]) {printf("%d is normal.\n",n);sc(n);continue;}
    int boo = 1;
    // for(int i=0;prime[i]<n;i++)
    // {
    //   if(power(prime[i],n,n)==prime[i]) continue;
    //   else {boo = 0;break;}
    // }
    for(int i=2;i<n;i++)
    {
      if(power(i,n,n)==i) continue;
      else {boo = 0;break;}
    }
    if(!boo) printf("%d is normal.\n",n);
    else printf("The number %d is a Carmichael number.\n",n);
    sc(n);
  }
  // cout<<bs[430]<<endl;
  return 0;
}
