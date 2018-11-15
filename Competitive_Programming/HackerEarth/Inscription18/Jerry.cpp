#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 0.000000001
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

ll f(ld a,ld k)
{
  ld b = pow(a,1/k);
  if(b-(ll)b<EPS) return (ll)round(b);
  return (ll)b;
}

int main()
{
  int n;
  sc(n);
  sieve(100);
  while(n--)
  {
    ld a,b;
    scld(a);scld(b);
    if(a!=1) a--;
    ll count = 0;
    for(ld i=2;i<60;i++)
    {
      if(bs[i]) {count+=f(b,i)-f(a,i); cout<<"i: "<<i<<" count: "<<count<<endl;}
    }
    cout<<count<<endl;
  }
  return 0;
}

