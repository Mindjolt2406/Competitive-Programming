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

int main()
{
  int n,k,x;
  sc(n);sc(k);sc(x);
  ll prod = 1;
  vector<int> v;
  if(x!=1)v.pu(1);
  else v.pu(0);
  for(int i=1;i<=n-2;i++)
  {
    prod*=(k-1);
    prod%=MOD;
    v.pu((prod-v[i-1] + MOD)%MOD);
  }
  cout<<v[v.size()-1]<<endl;
  return 0;
}
