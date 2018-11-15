#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;
  int l[n];
  vector < pair <int,int> >v1;
  vector <int> v;
  map <int,int> e,f;
  int d[n];
  int c[n];
  map <int,int> ::iterator it;
  for(int i=0;i<n;i++)
  {
    cin>>l[i];
    c[i] = l[i];
    v1.pu(m(l[i],i));
    if(e.find(l[i])==e.end()) {v.pu(l[i]); e[l[i]] = 1;}
  }
  sort(v.begin(),v.end());
  sort(c,c+n);
  for(int i=0;i<v.size();i++)
  {
    e[v[i]] = i;
    f[v[i]] = 0;
    // d[i] = e[v[i]];
    //
  }
  // for(it = f.begin();it!=f.end();it++) cout<<it->first<<" "<<it->second<<endl;
  // for(int i=0;i<n;i++) cout<<c[i]<<" ";
  // cout<<endl;
  for(int i=0;i<n;i++)
  {
    if(f[c[i]]==0) {e[c[i]] = i;f[c[i]] = 1;}
    // cout<<e[c[i]]<<" "<<c[i]<<endl;
  }
  for(int i=0;i<n;i++)
  {
    d[i] = e[l[i]];
  }
  // cout<<"D: "<<endl;
  // for(int i=0;i<n;i++) cout<<d[i]<<" ";
  // cout<<endl;
  for(int h=0;h<q;h++)
  {
    int a,b;
    cin>>a>>b;
    a-=1;b-=1;
    // cout<<l[a]<<" "<<e[l[a]]<<" "<<l[b]<<" "<<e[l[b]]<<endl;
    if (e[l[a]]==e[l[b]]) continue;
    else if(e[l[a]]>e[l[b]]) d[a]--;
    else d[b]--;
  }
  for(int i=0;i<n;i++) cout<<d[i]<<" ";
  cout<<endl;
  return 0;
}
