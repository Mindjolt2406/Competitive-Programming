#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,a,b;
    cin>>n>>a>>b;
    long double  counta=0,countb = 0;
    int l[n];
    for(int i=0;i<n;i++)
    {
      cin>>l[i];
      if(l[i]==a)counta++;
      if(l[i]==b) countb++;
    }
    cout<<(counta/n)*(countb/n)<<endl;
  }
  return 0;
}
