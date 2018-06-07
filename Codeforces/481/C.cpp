#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  long long int n,m;
  cin>>n>>m;
  long long int l[n];
  long long int b[m];
  long long int p[n];
  for(long long int i=0;i<n;i++) cin>>l[i];
  for(long long int i=0;i<m;i++) cin>>b[i];
  long long int index = 0;
  p[0] = l[0];
  for(long long int i=1;i<n;i++) p[i] = l[i] + p[i-1];
  for(long long int i = 0;i<m;i++)
  {
    if(b[i]>p[index])
    {
      while(b[i]>p[index]) {index++;}
    }
    cout<<index+1<<" ";
    if(index==0) cout<<b[i]<<endl;
    else cout<<b[i]-p[index-1]<<endl;
  }
  return 0;
}
