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
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) {sc(l[i]);l[i]--;}
  int*time1 = (int*)calloc(n,sizeof(int));
  bitset<1010>*adj = new bitset<1010>[n];
  for(int i=0;i<n;i++)
  {
    int k = i;
    adj[i].reset();
    while(l[k]!=k)
    {
      k = l[k];
      adj[i][k] = true;
      // adj[i].pu(k);
      time1[i]+=2;
    }
    // if(l[k]==k) {adj[i][k] = true;}
  }
  ll*dp = (ll*)calloc(n,sizeof(ll));
  dp[0] = 2;
  for(int i=0;i<n;i++) if(l[i]==i) dp[i] = 2;
  for(int i=1;i<n;i++)
  {
    if(dp[i]!=0) continue;
    dp[i]+=dp[l[i]];
    dp[i]%=MOD;
    for(int j=l[i]+1;j<i;j++) {dp[i]+=dp[j];dp[i]%=MOD;}
    dp[i]+=2;
  }
  ll sum1 = 0;
  for(int i=0;i<n;i++) {sum1+=dp[i];sum1%=MOD;}
  cout<<sum1<<endl;
  return 0;
}
