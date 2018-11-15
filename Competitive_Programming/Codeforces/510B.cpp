#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
#define pu push_back
#define m make_pair 
using namespace std;

int recur(char l[50][50],int,int,int,int,int,int,int);
int main()
{
  int n,m;
  cin>>n>>m;
  char l[50][50];
  for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin>>l[i][j];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int c = 1;
      int boo = recur(l,i,j,i,j,n,m,c);
      if(boo){cout<<"Yes";return 0;}
    }
  }
  cout<<"No";
  return 0;
}

int recur(char **l, int i,int j,int a,int b,int n,int m,int boo)
{
  if(i>=n || j>=m ||i<0 || j<0) return 0;
  if (l[i][j]=='*') return 0;
  if(i==a and j==b and boo>3)return 1;
  l[i][j]='*';
  if(recur(l,i-1,j,a,b,n,m,boo+1)) return 1;
  if(recur(l,i,j-1,a,b,n,m,boo+1)) return 1;
  if(recur(l,i+1,j,a,b,n,m,boo+1)) return 1;
  if(recur(l,i,j+1,a,b,n,m,boo+1)) return 1;
  return 0;
}
