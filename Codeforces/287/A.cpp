#include<bits/stdc++.h>
#define mp make_pair
#define pu push_back
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  pair<int,int> *l = new pair<int,int>[n];
  for(int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    l[i] = mp(a,i);
  }
  sort(l,l+n);
  int i=0,count = 0;
  vector<int> v;
  while(k-l[i].first>=0 && i<n)
  {
    // cout<<"k: "<<k<<endl;
    count++;
    k-=l[i].first;
    v.pu(l[i].second);
    i++;
  }
  cout<<count<<endl;
  for(int i=0;i<count;i++) cout<<v[i]+1<<" ";
  if(count)cout<<endl;
  return 0;
}
