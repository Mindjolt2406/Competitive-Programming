#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
#define mt make_tuple
using namespace std;

void print(vector <tuple <int,int,int> > v)
{
  for(int i=0;i<v.size();i++)
  {
    cout<<"1: "<<get<0>(v[i])<<" 2: "<<get<1>(v[i])<<" 3: "<<get<2>(v[i])<<endl;
  }
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    vector < pair <int,int> > v1;
    vector < pair <int,int> > v2;
    vector < int> v;
    int n,k;
    cin>>n>>k;
    int l[n];
    for(int i=0;i<n;i++) cin>>l[i];
    for(int i=0;i<n;i++)
    {
      if(i%2==0) v1.pu(m(l[i],i));
      else v2.pu(m(l[i],i));
    }
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    // for(int i=0;i<v1.size();i++) cout<<v1[i].first<<" ";
    // cout<<endl;
    sort(v2.begin(),v2.end());
    // for(int i=0;i<v2.size();i++) cout<<v2[i].first<<" ";
    // cout<<endl;
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
      if(i%2==0)sum1+=l[i];
      else sum2+=l[i];
    }
    int boo = 1;
    int count = 0;
    int i = 0;
    // print(v);
    for(int i=0;i<min(v1.size(),v2.size());i++)
    {
      if(v1[i].first-v2[i].first>0) v.pu(v1[i].first-v2[i].first);
      else break;
    }
    // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
    // cout<<endl;
    while(sum2<=sum1 && count<k && i<v.size())
    {
      count++;
      sum2+=v[i];
      sum1-=v[i];
      i++;
    }
    // cout<<"sum1: "<<sum1<<" sum2: "<<sum2<<endl;
    if(count<=k && sum2>sum1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
