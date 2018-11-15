#include<bits/stdc++.h>
using namespace std;

int main()
{
  char l[8][8];
  for(int i=0;i<8;i++) for(int j=0;j<8;j++) cin>>l[i][j];
  int counta=0, countb=0;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(l[i][j]=='.') continue;
      else if(l[i][j]=='Q') counta+=9;
      else if(l[i][j]=='q') countb+=9;
      else if(l[i][j]=='R') counta+=5;
      else if(l[i][j]=='r') countb+=5;
      else if(l[i][j]=='B') counta+=3;
      else if(l[i][j]=='b') countb+=3;
      else if(l[i][j]=='N') counta+=3;
      else if(l[i][j]=='n') countb+=3;
      else if(l[i][j]=='P') counta+=1;
      else if(l[i][j]=='p') countb+=1;
      else if(l[i][j]=='K') counta+=0;
      else if(l[i][j]=='k') countb+=0;
    }
  }
  if(counta>countb) cout<<"White"<<endl;
  else if(countb>counta) cout<<"Black"<<endl;
  else cout<<"Draw"<<endl;
  return 0;
}
