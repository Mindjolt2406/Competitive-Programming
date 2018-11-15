#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,d,h;
  cin>>n>>d>>h;
  int c = 1,e = 1;
  if((d>=h && 2*h>=d && n>=d+1)&& !(d==1 && h==1 && n>d+1))
  {
    for(int i=0;i<h;i++){cout<<c<<" "<<c+1<<endl;c++;} //Making the height
    if(d>h){c++;cout<<1<<" "<<c<<endl;}
    for(int i=1;i<d-h;i++){cout<<c<<" "<<c+1<<endl;c++;} // Making the diameter
    if(h<d) // All the other nodes
    {
      while(c+1<=n) {c++;cout<<1<<" "<<c<<endl;}
    }
    else
    {
      while(c+1<=n) {c++;cout<<2<<" "<<c<<endl;}
    }
  }
  else cout<<-1<<endl;
  return 0;
}
