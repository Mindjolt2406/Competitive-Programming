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
bitset<1000001> bs;
int size = 1000000;
vi prime;

void sieve()
{
  bs.set();
  bs[0] = false;
  bs[1] = bs[0];
  for(ll i=2;i<size;i++)
  {
    if(bs[(int)i])
    {
      for(ll j=i*i;j<size;j+=i) bs[(int)j] = false;
    }
  }
}

int main()
{
  sieve();
  vector<int> v,v1;
  v1.pu(0);v1.pu(1);v1.pu(1);v1.pu(1);v1.pu(2);
  for(int i=5;i<41;i++) v1.pu(v1[i-1]+v1[i-4]);
  int sum1 = 0;
  for(int i=0;i<size;i++) {sum1+=(int)bs[i];v.pu(sum1);}
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int i = v1[n];
    printf("%d\n",v[i]);
  }
  return 0;
}
