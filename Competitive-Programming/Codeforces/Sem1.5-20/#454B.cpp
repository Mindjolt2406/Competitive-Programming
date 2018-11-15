#include<iostream>
#include<string>
using namespace std;

int main()
{
  char l[9][3][3];
    for(int i=0;i<9;i++){
    int j = i%3;
    char s;
    for(int k=0;k<9;k++)
      {
        cin>>s;
        l[(i/3) + (i%3)][j][k%3]=s;
      }
    }

    int a,b;
    cin>>a>>b;

    for(int i=0;i<9;i++)
    {
      int j = i%3;
      for(int k=0;k<9;k++)
      {
        cout<<l[(i/3)+(i%3)][j][k%3];
      }
      cout<<" ";
      if(j==2){cout<<endl;
      if(i==2||i==5)cout<<endl;}
    }

  a-=1;b-=1;
  int c = (a/3)*3 + b%3;
  cout<<c<<endl;
  int countc = 0;
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      cout<<l[c][i][j]<<" "<<(l[c][i][j]=='.')<<endl;
      if(l[c][i][j]!='.')continue;
      else countc++;
    }
  }
  cout<<countc<<endl;
  if(countc>0)
  {
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        if(l[c][i][j]=='.')l[c][i][j] = '!';
      }
    }
    for(int i=0;i<9;i++)
    {
      for(int j=0;j<3;j++)
      {
        for(int k=0;k<3;k++)
        {
          cout<<l[i/3+i%3][j][k];
        }
        cout<<" ";
      }
      cout<<endl;
      if(i==2||i==5)cout<<endl;
    }
  }
  else
  {
    for(int i=0;i<9;i++)
    {
      for(int j=0;j<3;j++)
      {
        for(int k=0;k<3;k++)
        {
          if(l[i/3+i%3][j][k]=='.')l[i/3+i%3][j][k]='!';
          cout<<l[i/3+i%3][j][k];
        }
        cout<<" ";
      }
      cout<<endl;
      if(i==2||i==5)cout<<endl;
    }
  }
  return 0;
}
