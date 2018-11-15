#include<iostream>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  n%=6;
  if(k==0)
  {
    if(n==5 || n==0) cout<<0<<endl;
    else if(n==1 || n==2) cout<<1<<endl;
    else cout<<2<<endl;
  }
  else if(k==1)
  {
    if(n==1 || n==4) cout<<0<<endl;
    else if(n==3||n==0) cout<<1<<endl;
    else cout<<2<<endl;
  }
  else
  {
    if(n==2||n==3) cout<<0<<endl;
    else if(n==4||n==5) cout<<1<<endl;
    else cout<<2<<endl;
  }
}
