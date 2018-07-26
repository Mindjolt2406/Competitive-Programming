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
    int n,m;
    sc(n);sc(m);
    int**l = new int*[n];
    for(int i=0;i<n;i++) l[i] = new int[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) sc(l[i][j]);
    int**dp = new int*[n];
    for(int i=0;i<n;i++) dp[i] = new int[m];
    for(int i=0;i<m;i++) dp[n-1][i] = l[n-1][i];
    for(int i = n-2;i>=0;i--)
    {
      for(int j=0;j<m;j++)
      {
        int max1 = -1;
        if(j>0) max1 = max(max1,dp[i+1][j-1]);
        if(j<m-1) max1 = max(max1,dp[i+1][j+1]);
        max1 = max(max1,dp[i+1][j]);
        dp[i][j] = max1+l[i][j];
      }
    }
    int max2 = -1;
    for(int i=0;i<m;i++) max2 = max(max2,dp[0][i]);
    // cout<<endl;
    // for(int i=0;i<n;i++){for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";cout<<endl;}
    printf("%d\n",max2);
  }
  return 0;
}
