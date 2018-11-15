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

bitset<110> bs;
int size = 102;
vi prime;

void sieve()
{
  bs.set();
  bs[0] = false;bs[1] = bs[0];
  for(int i=2;i<size;i++)
  {
    if(bs[i])
    {
      for(int j=i*i;j<size;j+=i) bs[j] = false;
      prime.pu(i);
    }
  }
}

int main()
{
  sieve();
  int n;
  sc(n);
  // for(int i=0;i<prime.size();i++) cout<<prime[i]<<" ";cout<<endl;
  while(n)
  {
    map<int,int> d;
    for(int i=0;i<prime.size();i++) d[prime[i]] = 0;
    int k = n;
    for(int i=0;i<prime.size();i++)
    {
      // for(int j=2;j<=n;j++)
      // {
      //   int prod = prime[i];
      //   while(j/prod && j%prod==0){d[prime[i]]+= j/prod;prod*=prime[i];}
      // }
      int prod = prime[i];
      while(n/prod) {d[prime[i]]+=n/prod;prod*=prime[i];}
    }
    map<int,int> :: iterator it;
    printf("%3d! =",n);
    int count = 0;
    for(it = d.begin();it!=d.end();it++)
    {
      // cout<<it->first<<" "<<it->second<<endl;
      if(count>=15 && it->second){count-=15;printf("\n");printf("      ");}
      if(it->second) {printf("%3d",it->second);count++;}
      else break;
    }
    printf("\n");
    d.clear();
    sc(n);
  }
  return 0;
}
