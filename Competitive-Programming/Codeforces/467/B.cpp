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

bitset<1000010> bs;
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
  sieve(min(1000000,p));
  // sieve(min(abs(1000000-p),abs(1000000-int(sqrt(p)))));
  // if(p>60000) sieve(int(sqrt(p))+1);
  // else sieve(p);
  int k = (int)sqrt(n);
  // cout<<"k: "<<k<<endl;
  int max1 = 0;
  // for(int i=0;i<prime.size();i++) cout<<prime[i]<<" ";cout<<endl;
  for(int i=0;i<k;i++)
  {
    int*m = (int*)calloc(k,sizeof(int));
    for(int j=0;j<prime.size();j++)
    {
      // if(prime[j]==)
      for(int j1=((n-(i+1)*k)/prime[j])*prime[j];j1<=n-k*i;j1+=prime[j])
      {
        // cout<<"j1: "<<j1<<" "<<n-(i+1)*k<<endl;
        if(j1>n-(i+1)*k) m[j1-n+(i+1)*k-1] = 1;
      }
    }
    // for(int i=0;i<k;i++) cout<<m[i]<<" ";cout<<endl;
    for(int j=k-1;j>=0;j--)
    {
      // cout<<"m[j]: "<<m[j]<<" j: "<<j<<" real m[j]: "<<n-(i+1)*k+1+j<<endl;
      if(m[j]==0 && n-(i+1)*k+1+j>p) {max1 = n-(i+1)*k+1+j;break;}
      if(n-(i+1)*k+1+j<=p) {cout<<-1<<endl;return 0;}
    }
    free(m);
    if(max1) break;
  }
  if(!max1)
  {
    int i = n-k*k;
    int*m = (int*)calloc(n-k*k+1,sizeof(int));
    for(int j = 0;j<prime.size();j++)
    {
      for(int j1 = prime[j];j1<=i;j1+=prime[j]) m[j1] = 1;
    }
    while(i>=2)
    {
      if(m[i]==0 && i>p) {max1 = i;break;}
      i--;
    }
  }
  if(max1>1)cout<<max1<<endl;
  else cout<<-1<<endl;
  return 0;
}
