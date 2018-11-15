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
      prime.pu((int)i);
    }
  }
}

int main()
{
  sieve(1000);
  vector<int> v;
  for(int i=0;prime[i]<200;i++)
  {
    for(int j=i+1;prime[j]<200;j++)
    {
      // cout<<prime[i]<<" "<<prime[j]<<endl;
      if(prime[i]*prime[j]<200) v.pu(prime[i]*prime[j]); 
    }
  }
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int boo1 = 1;
    // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
    for(int i=0;i<v.size();i++)
    {
      int boo = 0;
      for(int j=0;j<v.size();j++)
      {
        if(v[i]+v[j]==n) {boo = 1;cout<<"YES"<<endl;break;}
      }
      if(boo) {boo1 = 0;break;}
    }
    if(boo1) cout<<"NO"<<endl;
  }
  return 0;
}

