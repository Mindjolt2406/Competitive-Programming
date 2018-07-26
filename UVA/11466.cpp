#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define sci(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);

using namespace std;

bitset<10000010> bs;
int size = 10000002;
vll prime;

void sieve()
{
  bs.set();
  bs.set(0,false);bs.set(1,false);
  for(ll i=2;i<size;i++)
  {
    if(bs[i])
    {
      for(ll j=i*i;j<size;j+=i) bs[j] = false;
      prime.pu(i);
    }
  }
}

ll max2(ll a,ll b)
{
  if(a>b) return a;
  return b;
}

int main()
{
  sieve();
  ll n;
  scll(n);
  while(n)
  {
    int boo = 1;
    if(n<0){n*=-1;boo = -1;}
    ll count = 0,max1 = 0,i=0;
    while(prime[i]*prime[i]<=n)
    {
      // cout<<"prime[i]: "<<prime[i]<<endl;
      if(n%prime[i]==0)
      {
        count++;
        max1 = max2(max1,prime[i]);
        // cout<<n<<" "<<prime[i]<<endl;
        while(n%prime[i]==0) n/=prime[i];
      }
      i++;
      // if(n%(n/prime[i])==0 && n/prime[i]<=size && bs[n/prime[i]]) {count++;max1 = max(max1,(int)(n/prime[i]));}
    }
    if(n<=size && bs[n]) {count++; max1=max2(max1,n);}
    else if(n>size) {max1 = max2(max1,n);count++;}
    // cout<<"count: "<<count<<endl;
    if(count>1)printf("%lld\n",max1);
    else printf("-1\n");
    scll(n);
  }
  return 0;
}
