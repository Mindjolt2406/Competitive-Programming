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

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

pair<int,int> mul(pair<int,int> p1,pair<int,int> p2)
{
  int a = p1.first,b = p1.second,c = p2.first,d = p2.second;
  int g = gcd(a*c,b*d);
  return mp((a*c)/g,(b*d)/g);
}

pair<int,int> add(pair<int,int> p1,pair<int,int> p2)
{
  int a = p1.first,b = p1.second,c = p2.first,d = p2.second;
  int p = a*d + b*c, q = b*d;
  int g = gcd(p,q);
  return mp(p/g,q/g);
}

pair<int,int> recur(int i,int j,pair<int,int>**dp)
{
  // cout<<"i: "<<i<<" j: "<<j<<endl;
  if(dp[i][j]!=mp(-1,-1)) return dp[i][j];
  // if(i==0) return 0;
  // if(j==0) return 1;
  int w = i,b = j;
  int c = w+b;
  pair<int,int> prod1 = mp(0,1),prod2 = mp(0,1);
  if(b>=3) prod1 = mul(mp(b-2,c-2),dp[i][j-3]);
  else prod1 = mp(0,1);
  if(b>=2) prod2 = mul(mp(w-1,c-2),dp[i-1][j-2]);
  dp[i][j] = mul(add(mp(w,1),mul(mp(b,1),mul(mp(b-1,c-1),add(prod1,prod2)))),mp(1,c));
  // cout<<"dp: "<<dp[i][j].fir st<<" "<<dp[i][j].second<<endl;
  return dp[i][j];
}

int main()
{
  int n,m;
  sc(n);sc(m);
  // dp[i][j] i white and j black mice left
  pair<int,int> **dp = new pair<int,int> *[n+1];
  for(int i=0;i<=n;i++) dp[i] = new pair<int,int> [m+1];
  for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) dp[i][j] = mp(-1,-1);
  for(int i=1;i<=n;i++) dp[i][0] = mp(1,1);
  for(int i=0;i<=m;i++) dp[0][i] = mp(0,1);
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=m;j++) recur(i,j,dp);
  }
  // for(int i=0;i<=n;i++) {for(int j=0;j<=m;j++) printf("%.10Lf ",(ld)dp[i][j].first/dp[i][j].second);cout<<endl;}
  printf("%.10LF\n",(ld)dp[n][m].first/dp[n][m].second);
  return 0;
}

