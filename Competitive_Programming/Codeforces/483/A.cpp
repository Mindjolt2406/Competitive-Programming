#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  sort(l,l+n);
  if(n%2==1) cout<<l[n/2]<<endl;
  else cout<<l[(n/2)-1]<<endl;
  return 0;
}
