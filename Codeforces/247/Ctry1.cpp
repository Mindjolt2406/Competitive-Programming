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
  int n,k,d;
  sc(n);sc(k);sc(d);
  ll *l = (ll*)calloc(n+1,sizeof(ll));
  l[0] = 1;
  for(int i=1;i<=min(n,k);i++) l[i] = 1;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=k;j++)  {if(i>j){l[i]+=l[i-j];l[i]%=MOD;}}
  }
  for(int i=0;i<=n;i++) cout<<l[i]<<" ";cout<<endl;
  ll sum1 = 0;
  // for(int i=1;i<d && i<=n;i++) {sum1-=l[i];sum1+=MOD;sum1%=MOD;}
  for(int i=1;i<=n;i++)
  {
    for(int j=d;j<=k;j++)
    {
      if(i>=j) {sum1+=l[i-j];sum1%=MOD;}
    }
  }
  printf("%lld\n",sum1);
  return 0;
}
