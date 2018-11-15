#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  if(n<=2) cout<<-1<<endl;
  else
  {
    cout<<2<<" "<<3<<" "<<1<<" ";
    for(int i=0;i<n-3;i++) cout<<i+4<<" ";cout<<endl;
  }
}
