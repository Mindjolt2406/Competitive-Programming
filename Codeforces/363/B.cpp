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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

int dx[4] = {-1,+1,1,-1};
int dy[4] = {-1,-1,1,1};

bool check(int i,int j,int n,int m)
{
  if(i>=n || j>=m || i<0 || j<0) return false;
  return true;
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<string> v(n);

  vector<vector<int> > dp1(n,vector<int> (m)); // Left Up
  vector<vector<int> > dp2(n,vector<int> (m)); // Left down
  vector<vector<int> > dp3(n,vector<int> (m)); // Right up
  vector<vector<int> > dp4(n,vector<int> (m)); // Right down

  for(int i=0;i<n;i++) cin>>v[i];

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j]=='*') dp1[i][j] = dp2[i][j] = dp3[i][j] = dp4[i][j] = 1;
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(i>0) dp1[i][j]+=dp1[i-1][j];
      if(j>0) dp1[i][j]+=dp1[i][j-1];
      if(i>0 && j>0) dp1[i][j]-=dp1[i-1][j-1];
    }
  }

  for(int i=n-1;i>=0;i--)
  {
    for(int j=0;j<m;j++)
    {
      if(check(i+1,j,n,m)) dp2[i][j]+=dp2[i+1][j];
      if(check(i,j-1,n,m)) dp2[i][j]+=dp2[i][j-1];
      if(check(i+1,j-1,n,m)) dp2[i][j]-=dp2[i+1][j-1];
    }
  }

  for(int i=n-1;i>=0;i--)
  {
    for(int j=m-1;j>=0;j--)
    {
      if(check(i+1,j,n,m)) dp3[i][j]+=dp3[i+1][j];
      if(check(i,j+1,n,m)) dp3[i][j]+=dp3[i][j+1];
      if(check(i+1,j+1,n,m)) dp3[i][j]-=dp3[i+1][j+1];
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=m-1;j>=0;j--)
    {
      if(check(i-1,j,n,m)) dp4[i][j]+=dp4[i-1][j];
      if(check(i,j+1,n,m)) dp4[i][j]+=dp4[i][j+1];
      if(check(i-1,j+1,n,m)) dp4[i][j]-=dp4[i-1][j+1];
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int cnt = 0;
      for(int k=0;k<4;k++)
      {
        int x = i+dx[k], y = j+dy[k];
        if(check(x,y,n,m))
        {
          if(k==0) cnt+=dp1[x][y];
          if(k==1) cnt+=dp2[x][y];
          if(k==2) cnt+=dp3[x][y];
          if(k==3) cnt+=dp4[x][y];
        }
      }
      
      if(cnt==0)
      {
        cout<<"YES"<<endl;
        cout<<i+1<<" "<<j+1<<endl;
        return 0;
      } 
    }
  }
  cout<<"NO"<<endl;
  return 0;
}

