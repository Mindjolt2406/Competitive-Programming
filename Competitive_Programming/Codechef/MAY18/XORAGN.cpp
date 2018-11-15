#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int l[n];
    int xor1 = 0;
    for(int i=0;i<n;i++) {cin>>l[i];xor1 = xor1^(2*l[i]);}
    cout<<xor1<<endl;
  }
  return 0;
}
