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

int dp[1100000] = {0};
int dp2[1100000] = {0};
int pref[100010][20] = {0};
int n;

int get(int i,int j,int k)
{
  if(i>=n || j>=n) return 0;
  int a = 0;
  if(i==0) a =  pref[j][k];
  else a = pref[j][k] - pref[i-1][k];
  // if(a<0) t(i,j,k,pref[j][k],pref[i-1][k]);
  return a;
}

int getcount(int i)
{
  return pref[n-1][i];
}

int main()
{
  __;
  int m;
  cin>>n>>m;
  vector<int> v(n);
  for(int i=0;i<n;i++) {cin>>v[i];v[i]--;}
  pref[0][v[0]] = 1;
  for(int i=1;i<n;i++)
  {
    pref[i][v[i]] = 1;
    for(int j=0;j<m;j++) pref[i][j]+=pref[i-1][j];
  }  

  // for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<pref[i][j]<<" "; cout<<endl;} 

  for(int i=0;i<pow(2,m);i++) dp[i] = INF;
  dp[0] = 0;
  for(int mask=0;mask<pow(2,m);mask++)
  {
    for(int j=0;j<m;j++)
    {
      // If the jth bit is not set
      if(~(mask&(1<<j)))
      {
        int a = getcount(j);
        int b = dp2[mask];
        int c = get(b,b+a-1,j);
        // if(c<0) t(c,b,b+a-1,j);
        if(dp[mask|1<<j] > dp[mask]+a-c)
        {
          dp[mask|1<<j] = dp[mask]+a-c;
          dp2[mask|1<<j] = dp2[mask] + a;
        }
        // t(b,c,mask,(mask|1<<j),dp[mask|1<<j]);
      }
      // dp[mask|1<<j] =  min(dp[mask] + c,dp[mask|1<<j]);
      // dp2[mask|1<<j] += dp[mask]
    }
  }

  // for(int i=0;i<pow(2,m);i++)
  // {
  //   t(i,dp[i],dp2[i]);
  // }
  cout<<dp[(int)pow(2,m)-1]<<endl;
  return 0;
}

