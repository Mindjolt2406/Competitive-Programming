#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int h,a;
    cin>>h>>a;
    int timer= 0;
    while(h>0&&a>0)
    {
      if(h>2&&a>8) {h-=2;a-=8;timer+=2;}
      else if(h>17){h-=17;a+=7;timer+=2;}
      else {timer++;break;}
    }
    cout<<timer<<endl;
  }
}
