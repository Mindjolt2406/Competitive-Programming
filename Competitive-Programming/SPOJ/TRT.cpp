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

int recur(int**dp,int*l, int i,int j,int n)
{
  if(i==j) {dp[i][j] = (n-j+i)*l[i];return dp[i][j];}
  if(dp[i][j]!=0) return dp[i][j];
  dp[i+1][j] = recur(dp,l,i+1,j,n);
  dp[i][j-1] = recur(dp,l,i,j-1,n);
  dp[i][j] = max(dp[i+1][j]+(n-j+i)*l[i],dp[i][j-1]+(n-j+i)*l[j]);
  return dp[i][j];
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int**dp = new int*[n];
  for(int i=0;i<n;i++) dp[i] = new int[n];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = 0;
  printf("%d\n",recur(dp,l,0,n-1,n));
  // for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";cout<<endl;}
  return 0;
}
