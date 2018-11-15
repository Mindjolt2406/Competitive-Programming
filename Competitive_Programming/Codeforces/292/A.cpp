#include<iostream>
using namespace std;

int main()
{
  int a,b,s;
  cin>>a>>b>>s;
  if(s%2 !=(abs(a)+abs(b))%2 || s<abs(a)+abs(b)) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}
