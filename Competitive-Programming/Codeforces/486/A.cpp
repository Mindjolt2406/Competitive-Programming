#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pu push_back
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int l[n];
  set<int> s;
  map<int,int> d;
  for(int i=0;i<n;i++) {cin>>l[i];s.insert(l[i]);d[l[i]] = i;}
  // int a,b;
  // cin>>a>>b;
  if(s.size()>=k)
  {
    set<int> :: iterator it;
    int count = 0;
    cout<<"YES"<<endl;
    for(it=s.begin();it!=s.end() && count<k;it++)
    {
      cout<<d[*it]+1<<" ";
      count++;
    }
    cout<<endl;
  }
  else cout<<"NO"<<endl;
  return 0;
}
