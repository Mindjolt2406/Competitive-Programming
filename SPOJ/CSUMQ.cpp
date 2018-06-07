#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  for(int i=1;i<n;i++) l[i]+=l[i-1];
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    if(a!=0) cout<<l[b]-l[a-1]<<endl;
    else cout<<l[b]<<endl;
  }
}
