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

int count2(int a)
{
  int count = 0;
  while(a%2==0) {count++;a/=2;}
  return count;
}

int count5(int a)
{
  int count = 0;
  while(a%5==0) {count++;a/=5;}
  return count;
}

int main()
{
  int n;
  sc(n);
  int**l = new int*[n];
  for(int i=0;i<n;i++) l[i] = new int[n];
  for(int i=0;i<n;i++)  for(int j=0;j<n;j++) sc(l[i][j]);
  pair<int,int>**dp = new pair<int,int>*[n];
  for(int i=0;i<n;i++) dp[i] = new pair<int,int>[n];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = mp(0,0);
  dp[0][0].first = count2(l[0][0]);
  dp[0][0].second = count5(l[0][0]);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==0 && j==0) continue;
      int min2a = INF,min5a = INF,min2b = INF,min5b = INF,mina=INF,minb=INF;
      if(i>0) {min2a = dp[i-1][j].first + count2(l[i][j]);min5a = dp[i-1][j].second + count5(l[i][j]);mina = min(min2a,min5a);}
      if(j>0) {min2b = dp[i][j-1].first + count2(l[i][j]);min5b = dp[i][j-1].second + count5(l[i][j]);minb = min(min2b,min5b);}
      if(mina<minb) {dp[i][j].first = min2a;dp[i][j].second = min5a;}
      else if(mina==minb)
      {
        if(min2a<=min2b && min5a<=min5b) {dp[i][j].first = min2a;dp[i][j].second = min5a;}
        else {dp[i][j].first = min2b;dp[i][j].second = min5b;}
      }
      else {dp[i][j].first = min2b;dp[i][j].second = min5b;}
    }
  }
  string s;
  int i=n-1,j=n-1;
  while(i>=0 && j>=0)
  {
    // cout<<"i: "<<i<<" j: "<<j<<endl;
    char c;
    if(i==0 && j==0) break;
    if(i>0)
    {
      // for(int i=0;i<n;i++) for(int j=0;j<n;j++)
      if(dp[i][j].first-count2(l[i][j])==dp[i-1][j].first && dp[i][j].second-count5(l[i][j])==dp[i-1][j].second)c='D';
      else c='R';
    }
    else if(j>0) c='R';
    s+=c;
    if(c=='D') i--;
    else j--;
  }
  reverse(s.begin(),s.end());
  cout<<min(dp[n-1][n-1].first,dp[n-1][n-1].second)<<endl;
  cout<<s<<endl;
  if(n==40)for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(min(dp[i][j].first,dp[i][j].second)==2) cout<<"i: "<<i<<" j: "<<j<<" first: "<<dp[i][j].first<<" second: "<<dp[i][j].second<<endl;
  return 0;
}
