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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6, t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll dp[1000][1000] = {0};

ll recur(int i,int j,int count,int r,int g,int max1)
{
  t(i,j,count,r,g);
  ll a = 0,b = 0;
  if(dp[i][j]!=-1) return dp[i][j];
  if(r<0 || g<0) {dp[i][j] = 0;return 0;}
  if(count==0) {dp[i][j] = 1;return 1;}
  dp[i][j] = 0;
  dp[i+1][j] = recur(i+1,j,count-1,r-count,g,max1);
  dp[i][j+1] = recur(i,j+1,count-1,r,g-count,max1);
  if(dp[i+1][j] >=0) dp[i][j]+=dp[i+1][j];dp[i][j]%=MOD;
  if(dp[i][j+1]>=0)dp[i][j]+=dp[i][j+1];dp[i][j]%=MOD;
  t(i,j,count,r,g,dp[i][j]);
  return dp[i][j];
}

int main()
{
  int r,g;
  sc(r);sc(g);
  int max1 = 1;
  for(int i=1;i<=1000;i++)
  {
    int c = i*i+i;
    if(c<2*(r+g)) {max1 = i;}
    else if(c==2*(r+g)) {max1 = i;break;}
    else break;
  }
  for(int i=0;i<=max1;i++)
  {
    for(int j=0;j<=max1;j++) dp[i][j] = -1;
  }
  ll c = recur(0,0,max1,r,g,max1);
  cout<<c<<endl;
  for(int i=0;i<=max1;i++) for(int j=0;j<=max1;j++) t(i,j,dp[i][j]);
  return 0;
}












