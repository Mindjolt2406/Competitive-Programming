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
  ll**dp1 = new ll*[2001];
  for(int i=0;i<2001;i++) dp1[i] = new ll[2001];
  for(int i=0;i<2001;i++) for(int j=0;j<2001;j++) dp1[i][j] = -1;
  ll**dp2 = new ll*[2001];
  for(int i=0;i<2001;i++) dp2[i] = new ll[2001];
  for(int i=0;i<2001;i++) for(int j=0;j<2001;j++) dp2[i][j] = -1;
  for(int i=0;i<2001;i++) {dp2[0][i] = 1;dp2[i][0] = 1;}
  dp2[0][0] = 0;
  for(int i=0;i<2001;i++) dp1[i][i] = 0;
  for(int i=0;i<2001;i++) {dp1[i][0] = 1;}
  dp1[0][0] = 0;
  dp1[1][0] = 1;
  for(int i=1;i<2001;i++)
  {
    for(int j=1;j<i;j++)
    {
      if(i==j) continue;
      dp1[i][j] = (dp1[i-1][j]+dp1[i][j-1])%MOD;
    }
  }
  for(int i=1;i<2001;i++)
  {
    for(int j=i;j<2001;j++) 
    {
      if(i==j) {dp2[i][j] = dp2[i-1][j];continue;}
      dp2[i][j] = (dp2[i-1][j]+dp2[i][j-1])%MOD;
    }
  }
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int a,b;
    string s;
    cin>>s;
    string k1,k2;
    int boo = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='-') {boo++;continue;}
      if(!boo) k1+=s[i];
      else k2+=s[i];
    }
    a = stoi(k1);
    b = stoi(k2);
    if(b==0)
    {
      printf("Case #%d: %lld 1\n",h,dp1[a][b]);
    }
    else
    {
    ll c1 = dp1[a][b],c2 = dp2[b-1][b];
    printf("Case #%d: %lld %lld\n",h,c1,c2);
    }
  }
  return 0;
}
