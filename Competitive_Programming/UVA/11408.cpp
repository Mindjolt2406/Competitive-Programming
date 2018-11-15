#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>
#define sc(n) scanf("%d",&n);
// #define sc(a,b) scanf("%d %d",&a,&b);

using namespace std;

bitset<5000010> bs;
bitset<5000010> bs1;
ll l[5000010] = {0};
ll m[5000010] = {0};
int size = 5000010;

void sieve()
{
  bs.set();
  bs1.reset();
  bs.set(0,false);bs.set(1,false);
  for(ll i=2;i<size;i++)
  {
    if(bs[i])
    {
      l[i] = i;
      for(ll j=2*i;j<size;j+=i)
      {
        bs[j] = false;
        l[j]+=i;
      }
    }
  }
  for(int i=0;i<size;i++)
  {
    if(bs[l[i]]) bs1[i] = true;
  }
  for(int i=2;i<size;i++)
  {
    m[i]+=m[i-1];
    if(bs1[i]) m[i]++;
  }
}

int main()
{
  sieve();
  int a,b;
  sc(a);
  while(a)
  {
    sc(b);
    // for(int i=a;i<=b;i++ ) cout<<l[i]<<" ";cout<<endl;
    printf("%lld\n",m[b]-m[a-1]);
    sc(a);
  }
  return 0;
}
