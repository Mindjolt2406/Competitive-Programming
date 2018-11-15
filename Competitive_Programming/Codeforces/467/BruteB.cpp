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

bitset<100010> bs;
vll prime;
void sieve(int size)
{
  bs.set();
  bs[0] = bs[1] = false;
  for(ll i=2;i<=size;i++)
  {
    if(bs[i])
    {
      for(ll j=i*i;j<=size;j+=i) {bs[j] = false;}
      prime.pu(i);
    }
  }
}

int main()
{
  int n,p;
  sc(p);sc(n);
  sieve(p);
  bitset<1000010> bs1;
  bs1.set();
  // for(int i=0;i<prime.size();i++) cout<<prime[i]<<" ";cout<<endl;
  for(ll i=0;i<prime.size();i++)
  {
    for(ll j=prime[i]*prime[i];j<=n;j+=prime[i]) bs1[j] = false;
  }
  int max1 = -1;
  for(int i=n;i>p;i--)
  {
    if(bs1[i]==true) {max1 = i;break;}
  }
  cout<<max1<<endl;
  return 0;
}
