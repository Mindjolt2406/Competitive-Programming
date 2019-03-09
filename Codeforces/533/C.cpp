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

int main()
{
  __;
  ll l,r,n;
  cin>>n>>l>>r;
  ll a=0,b=0,c=0;
  a = (r/3 - (l-1)/3);
  int x = l%3,y =  r%3;
  if(x==y)
  {
    if(x==0)
    {
      b = a-1;
      c = a-1;
    }
    else if(x==1)
    {
      c = a;
      b = a+1;
    }
    else if(x==2)
    {
      c = a+1;
      b = a;
    }
  }
  else
  {
    if(x==1 && y==2)
    {
      b = a+1;
      c = a+1;
    }
    else if(x==2 && y==1)
    {
      b = a;
      c = a;
    }
    else if(x==0 && y==1)
    {
      b = a;
      c = a-1;
    }
    else if(x==0 && y==2)
    {
      b = a;
      c = a;
    }
    else if(x==1 && y==0)
    {
      b = a;
      c = a;
    }
    else if(x==2 && y==0)
    {
      b = a-1;
      c = a;
    }
  }

  // t(a,b,c);
  vector<vector<ll> > dp(n);
  for(int i=0;i<n;i++) dp[i] = {0,0,0};
  dp[0][0] = a;
  dp[0][1] = b;
  dp[0][2] = c;

  for(int i=1;i<n;i++)
  {
    dp[i][0] = ((dp[i-1][0]*a)%MOD + (dp[i-1][1]*c)%MOD + (dp[i-1][2]*b)%MOD)%MOD;
    dp[i][1] = ((dp[i-1][0]*b)%MOD + (dp[i-1][1]*a)%MOD + (dp[i-1][2]*c)%MOD)%MOD;
    dp[i][2] = ((dp[i-1][0]*c)%MOD + (dp[i-1][1]*b)%MOD + (dp[i-1][2]*a)%MOD)%MOD;
  }
  cout<<dp[n-1][0]<<endl;
  return 0;
}

