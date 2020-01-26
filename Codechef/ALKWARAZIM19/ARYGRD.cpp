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

int f(vector<string> &v,vector<vector<pair<int,int> > > &p,int n,int m,int x)
{
  vector<vector<vector<int> > > dp(n,vector<vector<int> >(m,vector<int>(6)));
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int k=0;k<6;k++) dp[i][j][k] = -1;

  if(v[0][0]=='.') dp[0][0][0] = 0;
  else if(v[0][0]=='*') dp[0][0][0] = 1;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int a;
      if(v[i][j]=='.') a = 0;
      else if(v[i][j]=='*') a = 1;
      else a = -1;

      if(a<0) continue;

      for(int k=1;k<=x;k++)
      {
        if(j>0 && dp[i][j-1][k-1] !=-1) 
        {
          dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1]+a);
          t(dp[i][j][k],dp[i][j-1][k-1]+a,i,j,k);
          if(dp[i][j-1][k-1]+a==dp[i][j][k]) 
          {
            p[i][j] = mp(i,j-1);
            if(i==n-1 && j==m-1) t(dp[i][j][k],dp[i][j-1][k-1],k-1);
          }
        }
      }

      for(int k1=0;k1<=x;k1++)
      {
        for(int k2=0;k2<=x;k2++)
        {
          if(i>0 && dp[i-1][j][k2]!=-1) 
          {
            if(i==n-1 && j==m-1) t(dp[i][j][k1],k1);
            dp[i][j][k1] = max(dp[i][j][k1],dp[i-1][j][k2]+a);
            if(dp[i][j][k1]==dp[i-1][j][k2]+a) p[i][j] = mp(i-1,j);
            if(i==n-1 && j==m-1) {t(dp[i][j][k1],dp[i-1][j][k2],k1,k2,a);}
          }
        }
      }
    }
  }

  int max1 = -1;
  for(int i=0;i<=x;i++) max1 = max(max1,dp[n-1][m-1][i]);

  for(int i=0;i<n;i++) 
  {
    for(int j=0;j<m;j++) 
    {
      int max1 = -1;
      for(int k=0;k<=x;k++) max1 = max(max1,dp[i][j][k]);
      cout<<max1<<" ";
    }
    cout<<endl;
  }
  return max1;
}

int main()
{
  __;
  int n,m,x;
  cin>>n>>m>>x;
  vector<string> v(n);
  vector<vector<pair<int,int> > > p(n,vector<pair<int,int> >(m));
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) p[i][j] = mp(-1,-1);

  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }


  int a = f(v,p,n,m,x);
  t(a);
  if(a==-1) {cout<<-1<<endl;return 0;}
  pair<int,int> temp = p[n-1][m-1];
  _;
  while(temp!=mp(0,0))
  {
    t(temp.fi,temp.se);
    v[temp.fi][temp.se] = '.';
    temp = p[temp.fi][temp.se];
  }

  for(int i=0;i<n;i++) cout<<v[i]<<endl;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) p[i][j] = mp(-1,-1);

  a+=f(v,p,n,m,x);
  cout<<a<<endl;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cout<<"("<<p[i][j].fi<<" "<<p[i][j].se<<") ";
    }
    cout<<endl;
  }
  return 0;
}

