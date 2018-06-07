#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

int count(char** l,int i,int j,int a, int b,int c)
{
  int count = 0;
  if(i>0 && j>0) if(l[i-1][j-1]=='*') count++;
  if(i>0) if(l[i-1][j]=='*') count++;
  if(i>0 && j<b-1) if(l[i-1][j+1]=='*') count++;
  if(j>0) if(l[i][j-1]=='*') count++;
  if(j<b-1) if(l[i][j+1]=='*') count++;
  if(i<a-1 && j>0) if(l[i+1][j-1]=='*') count++;
  if(i<a-1) if(l[i+1][j]=='*') count++;
  if(i<a-1 && j<b-1) if(l[i+1][j+1]=='*') count++;
  // cout<<"i: "<<i<<" j: "<<j<<" count: "<<count<<endl;
  if(count==c) return 1;
  else return 0;
}
int main()
{
  int a,b;
  cin>>a>>b;
  char **l = new char*[a];
  for(int i=0;i<a;i++) l[i] = new char[b];
  for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin>>l[i][j];
  for(int i=0;i<a;i++)
  {
    for(int j=0;j<b;j++)
    {
      if(l[i][j]>=49 && l[i][j]<=56)
      {
        int c = count(l,i,j,a,b,l[i][j]-'0');
        if(c==0)  {cout<<"NO"<<endl;return 0;}
      }
      else if(l[i][j]=='.')
      {
        int c = count(l,i,j,a,b,0);
        if(c==0) {cout<<"NO"<<endl;return 0;}
      }
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
