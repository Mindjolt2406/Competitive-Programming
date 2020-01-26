/*
Rathin Bhargava
IIIT Bangalore

*/
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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

const int N = 510;
ll dp[N][N] = {0};

int main()
{
  __;
  int n;
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = INF;
  for(int i=0;i<n;i++) dp[i][i] = 1;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j+i<n;j++)
    {
      int a = j;
      int b = i+j;
      int boo = 0;

      // Delete now
      dp[a][b] = min(dp[a][b],dp[a+1][b]+1);
      // Delete later
      for(int k=a+1;k<=b;k++)
      {
        if(s[a]==s[k])
        {
          if(k!=b) dp[a][b] = min(dp[a][b], dp[a][k-1] + dp[k+1][b]);
          else dp[a][b] = min(dp[a][b], dp[a][k-1]);
        }
      }
    }
  }
  cout<<dp[0][n-1]<<endl;

  // for(int i=0;i<n;i++) 
  // {
  //   for(int j=0;j<n;j++) { dp[i][j] == INF ? cout<<"INF " : cout<<dp[i][j]<<" "; }
  //   cout<<endl;
  // }
  return 0;
}

