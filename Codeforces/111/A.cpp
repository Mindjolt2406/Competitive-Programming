#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n];
  int sum1 = 0;
  for(int i=0;i<n;i++) {cin>>l[i];sum1+=l[i];}
  sort(l,l+n);
  reverse(l,l+n);
  int sum2 = 0;
  int count = 0;
  for(int i=0;i<n;i++)
  {
    sum2+=l[i];
    count++;
    if(sum2>sum1/2) break;
  }
  cout<<count<<endl;
  return 0;
}
