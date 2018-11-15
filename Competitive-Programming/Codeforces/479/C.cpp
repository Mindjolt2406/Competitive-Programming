#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  sort(l,l+n);
  if(k==0 && l[0]==1) cout<<-1<<endl;
  else if(k==0) cout<<1<<endl;
  else if(k!=n && l[k]!=l[k-1]) cout<<l[k-1]<<endl;
  else if(k==n) cout<<l[n-1]<<endl;
  else cout<<-1<<endl;
  return 0;
}
