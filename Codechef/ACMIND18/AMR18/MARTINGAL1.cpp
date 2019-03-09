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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

ld dp[2000010][30] = {0};
int orig;

ld recur(int n,int x)
{
  // t(n,x);
  if(n<=0 || x<0) return 0;
  else if(n>=2*orig) return 0;
  if(dp[n][x]!=INF) return dp[n][x];
  if(dp[n][x]==INF)
  {
    ld sum1 = 0,a=0,b=0;
    a = recur(n+(1<<x),0);
    b = recur(n-(1<<x),x+1);
    dp[n][x] = 1 + a*0.5 + b*0.5;
  }
  // t(n,x);
  return dp[n][x];
}

int main()
{
  __;
  for(int i=0;i<2000010;i++) for(int j=0;j<22;j++) dp[i][j] = INF;
  cin>>orig;
  cout<<setprecision(12);
  cout<<recur(orig,0)<<endl;
  return 0;
}

