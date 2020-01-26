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

int n;

bool check(int x,int y,vector<vector<int> > &v)
{
  if(x<=0 || y<=0 || x>=n-1 || y>=n-1) return false;

  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};
  if(v[x][y]==1) return false;
  for(int k=0;k<4;k++)
  {
    if(v[x+dx[k]][y+dy[k]]==1) return false; 
  }
  v[x][y] = 1;
  for(int k=0;k<4;k++)
  {
    v[x+dx[k]][y+dy[k]] = 1;
  }
  return true;
}

int main()
{
  __;
  cin>>n;
  vector<vector<int> > v(n,vector<int>(n));
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    for(int j=0;j<s.size();j++)
    {
      if(s[j]=='.') v[i][j] = 0;
      else v[i][j] = 1;
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      check(i,j,v);
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(v[i][j]==0) {cout<<"NO"<<endl;return 0;} 
    }
  }
  // for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cout<<v[i][j]<<" "; cout<<endl;}
  cout<<"YES"<<endl;
  return 0;
}

