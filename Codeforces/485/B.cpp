#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;
  cin>>a>>b;
  if(a==b || ((a==2 && b==4) || (a==4 && b==2))) cout<<"="<<endl;
  else if(a<b)
  {
    if(a==1) cout<<"<"<<endl;
    else if(a==2 && b==3) cout<<"<"<<endl;
    else cout<<">"<<endl;
  }
  else
  {
    if(b==1 || (a==3 && b==2)) cout<<">"<<endl;
    else cout<<"<"<<endl;
  }
}
