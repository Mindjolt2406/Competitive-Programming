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
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll solve(ll a)
{
  if(a<=0) return 0;
  string s = to_string(a);
  ll dp[16][2] = {0};
  int pos = 0,check = 0;
  for(int i=0;i<=s[0]-'0';i++) dp[0][0]+=i;
  dp[0][1] = 0;
  for(int pos =1;pos<s.size();pos++)
  {
    // dp[pos][0]
    for(int i=0;i<=s[i]-'0';i++)
    {
      dp[pos][0]+=dp[pos-1][0]+i;
    }
    // dp[pos][1]
    ll a = 0;
    for(int i=0;i<=9;i++)
    {
      a+=dp[pos-1][1]+i;
    }
    a*=s[pos-1]-'0';
    ll b = ((s[pos-1]-'0')*(s[pos-1]-'0'-1))/2;
    dp[pos][1] +=a+b*9;
  }
  int n = s.size();
  for(int i=0;i<s.size();i++) {for(int j=0;j<2;j++) cout<<dp[i][j]<<" ";cout<<endl;}
  return dp[n-1][0]+dp[n-1][1];
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    ll a,b;
    scll(a);scll(b);
    printf("%lld\n",solve(b)-solve(a-1));
  }
  return 0;
}

