#include<bits/stdc++.h>
#define pu push_back
#define mp make_pair
using namespace std;

bool mysort(const pair<int,int> &a,const pair<int,int> &b)
{
  if(a.first!=b.first) return a.first<b.first;
  else return a.second>=b.second;
}
int main()
{
  int n;
  cin>>n;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  map<int,int> d;
  map<int,int> :: iterator it;
  for(int i=0;i<n;i++)
  {
    if(d.find(l[i])==d.end()) d[l[i]] = 1;
    else d[l[i]]++;
  }
  vector<pair<int,int> > v;
  for(it=d.begin();it!=d.end();it++)
  {
    int a=0,b = 0,c = 0;
    if(d.find(it->first+1)!=d.end()) a = d[it->first+1];
    if(d.find(it->first-1)!=d.end()) b = d[it->first-1];
    if(a!=0) c+=a*(it->first+1);
    if(b!=0) c+=b*(it->first-1);
    v.pu(mp(c-it->second*it->first,it->first));
  }
  sort(v.begin(),v.end(),mysort);
  // reverse(v.begin(),v.end());
  int count = 0;
  for(int i=0;i<v.size();i++)
  {
    if(d[v[i].second])
    {
      // cout<<v[i].first<<" "<<v[i].second<<endl;
      count+=d[v[i].second]*v[i].second;
      d[v[i].second-1] = 0;
      d[v[i].second+1] = 0;
    }
  }
  cout<<count<<endl;
}
