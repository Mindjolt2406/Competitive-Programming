#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  long long int n;
  cin>>n;
  long long int l[n];
  for(long long int i=0;i<n;i++)
  {
    cin>>l[i];
    if(i!=0) l[i]+=l[i-1];
  }
  vector<long long int> v;
  long long int q;
  cin>>q;
  for(long long int h=0;h<q;h++)
  {
    long long int a;
    cin>>a;
    if(a==1)
    {
      long long int b,c;
      cin>>b>>c;
      b--;c--;
      b-=v.size();c-=v.size();
      // cout<<"b: "<<b<<" c: "<<c<<endl;
      if(b>=0&&c>=0)
      {
        if(b==0) cout<<l[c]<<endl;
        else cout<<l[c]-l[b-1]<<endl;
      }
      else if(b<0 && c>=0)
      {
        b*=-1;
        b--;
        cout<<v[b]+l[c]<<endl;
      }
      else if(c<0)
      {
        b*=-1;
        c*=-1;
        b--;c--;
        if(c==0) cout<<v[b]<<endl;
        else cout<<v[b]-v[c-1]<<endl;
      }
    }
    else
    {
      long long int b;
      cin>>b;
      if(v.empty()) v.pu(b);
      else v.pu(v.back()+b);
    }
  }
  return 0;
}
