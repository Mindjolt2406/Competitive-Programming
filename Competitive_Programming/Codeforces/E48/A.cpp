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
  ll n,k;
  scll(n);
  scll(k);
  ll *l = new ll[n];
  for(int i=0;i<n;i++) scll(l[i]);
  ll sum1 = 0;
  vector<ll> v;
  v.pu(0);
  for(int i=0;i<n;i++)
  {
    ll k1 = sum1;
    sum1+=l[i];
    // cout<<(i+1)*k<<" "<<sum1<<endl;
    v.pu(sum1/k- k1/k);
  }
  for(int i=1;i<=n;i++) printf("%lld ",v[i]);
  printf("\n");
  return 0;
}
