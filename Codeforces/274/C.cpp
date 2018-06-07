#include<bits/stdc++.h>
#define pu push_back
#define mp make_pair
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<pair<int,int> > v;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    v.pu(mp(a,b));
  }
  sort(v.begin(),v.end());
  int c = -1;
  for(int i=0;i<n;i++)
  {
    int a = v[i].first, b = v[i].second;
    if(b>=c) c = b;
    else c = a;
  }
  cout<<c<<endl;
}
