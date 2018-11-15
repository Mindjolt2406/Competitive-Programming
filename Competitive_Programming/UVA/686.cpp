#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

bitset <1000010> bs;
vi prime;

void sieve()
{
  bs.set();bs.set(0,false);bs.set(1,false);
  for(ll i=2;i<1000001;i++)
  {
    if(bs.test((size_t)i))
    {
      for(ll j=i*i;j<1000001;j+=i) bs.set((size_t)j,false);
      prime.pu((int)i);
    }
  }
}

int main()
{
  sieve();
  int n;
  // for(int i=0;i<100;i++)cout<<prime[i]<<" ";cout<<endl;
  scanf("%d",&n);
  while(n)
  {
    int count = 0;
    for(int i=0;prime[i]<=n/2;i++)
    {
      if(bs[n-prime[i]]) {count++;}
    }
    printf("%d\n",count);
    scanf("%d",&n);
  }
  return 0;
}
