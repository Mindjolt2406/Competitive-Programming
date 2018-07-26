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
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int* l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    int**dp = new int*[n];
    for(int i=0;i<n;i++) dp[i] = new int[2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i=1;i<n;i++)
    {
      dp[i][0] = max(abs(l[i-1]-1)+dp[i-1][1],dp[i-1][0]);
      dp[i][1] = max(abs(l[i]-l[i-1])+dp[i-1][1],abs(1-l[i])+dp[i-1][0]);
    }
    // for(int i=1;i<n;i++) cout<<dp[i][0]<<" ";cout<<endl;
    // for(int i=1;i<n;i++) cout<<dp[i][1]<<" ";cout<<endl;
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
  }
  return 0;
}
