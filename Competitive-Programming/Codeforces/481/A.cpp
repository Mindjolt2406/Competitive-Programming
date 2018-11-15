#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  reverse(l,l+n);
  map <int,int> d;
  vector<int> v;
  for(int i=0;i<n;i++)
  {
    if(d.find(l[i])==d.end()) {d[l[i]] = 1;v.pu(l[i]);}
  }
  reverse(v.begin(),v.end());
  cout<<v.size()<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
  cout<<endl;
  return 0;
}
