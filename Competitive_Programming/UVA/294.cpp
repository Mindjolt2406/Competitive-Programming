#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);

using namespace std;

bitset<10000010> bs;
int size = 10000000;
vll prime;

void sieve()
{
  bs.set();bs[0] = false;bs[1] = false;
  for(ll i=2;i<size;i++)
  {
    if(bs[(size_t)i])
    {
      for(ll j=i*i;j<size;j+=i) bs[(size_t)j] = false;
      prime.pu(i);
    }
  }
}

ll max(ll a,ll b)
{
  if(a>b) return a;
  return b;
}

int main()
{
  sieve();
  int t;
  sc(t);
  while(t--)
  {
    ll a,b;
    scll(a);scll(b);
    ll max1 = 0,max2 = 0;
    for(ll i=a;i<=b;i++)
    {
      ll c = i;
      if(i<size && bs[i]) {if(max1<2){max2 = i;max1 = 2;}}
      else
      {
        ll prod = 1;
        int j=0;
        while(j<prime.size() && prime[j]<c)
        {
          if(c%prime[j]==0)
          {
            ll count = 0;
            while(c%prime[j]==0) {count++;c/=prime[j];}
            count++;
            prod*=count;
          }
          j++;
        }
        // cout<<"i: "<<i<<" prod: "<<prod<<endl;
        if(c>1) prod*=2;
        if(prod>max1) {max1 = prod;max2 = i;}
      }
    }
    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,max2,max1);
  }
  return 0;
}
