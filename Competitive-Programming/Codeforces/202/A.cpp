#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  int count = 0,count2 = 0;
  for(int i=0;i<n;i++)
  {
    if(l[i]==25) count++;
    else if(l[i]==50){count--;count2++;}
    else
    {
      int boo = 0;
      if(count2>0 && count>0) {count--;count2--;}
      else if(count>2){count-=3;}
      else{cout<<"NO"<<endl;return 0;}
    }
    if(count<0){cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;
  return 0;
}
