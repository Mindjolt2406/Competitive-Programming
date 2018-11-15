#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 100
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int pref(int*m,int a,int b)
{
  if(a>0) return (m[b]-m[a-1] + MOD)%MOD;
  return m[b];
}

int recur(int**dp,int*m,int*l,int a,int b)
{
  // cout<<a<<" "<<b<<endl;
  if(dp[a][b]!=INF) return dp[a][b];
  if(a==b) {dp[a][b] = 0;return 0;}
  for(int i=a;i<b;i++)
  {
    dp[a][i] = recur(dp,m,l,a,i);
    dp[i+1][b] = recur(dp,m,l,i+1,b);
    dp[a][b] = min(dp[a][i]+dp[i+1][b]+pref(m,a,i)*pref(m,i+1,b),dp[a][b]);
  }
  return dp[a][b];
}

int main()
{
  int n;
  while(scanf("%d",&n)!=EOF)
  {
    int* l = new int[n];
    int* m = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    m[0] = l[0];
    for(int i=1;i<n;i++) m[i] = (m[i-1]+l[i])%MOD;
    int **dp = new int*[100];
    for(int i=0;i<100;i++) dp[i] = new int[100];
    for(int i=0;i<100;i++) for(int j=0;j<100;j++) dp[i][j] = INF;
    printf("%d\n",recur(dp,m,l,0,n-1));
    // for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cout<<dp[i][j]<<" ";cout<<endl;}
  }
  return 0;
}
