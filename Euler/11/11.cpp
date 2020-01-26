#include<iostream>
using namespace std;

int main()
{
  int l[20][20];
  for(int i=0;i<20;i++) for(int j=0;j<20;j++) cin>>l[i][j];
  int max = 0;
  for(int i=0;i<16;i++)
  {
    for(int j=0;j<16;j++)
    {
      int k = l[i][j]+l[i+1][j+1]+l[i+2][j+2]+l[i+3][j+3];
      if(max<k)max = k;
    }
  }
  cout<<max<<endl;
  return 0;
}
