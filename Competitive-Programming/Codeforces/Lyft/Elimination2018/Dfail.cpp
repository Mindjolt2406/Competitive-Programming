#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 998244353
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

long long int size;
bitset<10000010> bs;
vi prime;

void sieve(ll upperbound)
{
  size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i = 2;i< size;i++)
  {
    if(bs[i])
    {
      for(ll j = i*i;j<size;j+=i) bs[j] = false;
    }
    prime.pu((int)i);
  }
}

int main()
{
  sieve(3000001);
  int n;
  sc(n);
  map<ll,int> d;
  map<ll,int> ::iterator it;
  for(int i=0;i<n;i++)
  {
    ll k;
    scll(k);
    while(k!=1)
    {
      int boo = 0;
      for(int j=0;j<prime.size();j++)
      {
        while(k%prime[j]==0) 
        {
          boo = 1;
          k/=prime[j];
          if(d.find(prime[j])==d.end()) d[prime[j]] = 1;
          else d[prime[j]]++;
          continue;
        }
      }
      if(!boo)
      {
        if(d.find(k)!=d.end()) d[k]++;
        else d[k] = 1;
        break;
      }
    }
  }
  ll count = 1;
  for(it=d.begin();it!=d.end();it++)
  {
    cout<<it->first<<endl;
    count*=(it->second+1);
    count%=MOD;
  }
  cout<<count<<endl;
  return 0;
}

