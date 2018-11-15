#include<bits/stdc++.h>
using namespace std;

int main()
{
  int l[2000001] = {0};
  l[1] = 4;
  for(int i=1;i<1001;i++)
  {
    l[i*i + 1] = 2;
    l[i*i+i+1] = 2;
  }
  // for(int i=1;i<=10;i++) cout<<l[i]<<" ";
  // cout<<endl;
  // for(int i=1;i<2000;i++) if(l[i]) cout<<i<<" "<<l[i]<<endl;
  // cout<<endl;
  int sum = 0;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) sum+=l[i];
  cout<<sum<<endl;
  return 0;
}
