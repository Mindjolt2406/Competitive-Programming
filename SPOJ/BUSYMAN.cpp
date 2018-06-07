#include<bits/stdc++.h>
#define pu push_back
#define mt make_tuple
#define mp make_pair
using namespace std;

// Driver function to sort the vector elements
// by second element of pairs
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int check(pair<int,int> p,vector < pair<int,int> > v)
{
  if(v.size()==0) return 1;
  else if(p.first>=v.back().second) return 1;
  return 0;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int q;
    cin>>q;
    vector < pair<int,int> >  v,v1;
    for(int h=0;h<q;h++)
    {
      int a,b;
      cin>>a>>b;
      v.pu(mp(a,b));
    }
    sort(v.begin(),v.end(),sortbysec);
    // cout<<endl;
    // for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    int l[1000001] = {0};
    int count = 0;
    for(int i=0;i<v.size();i++)
    {
      pair<int,int> p = v[i];
      int a = p.first, b = p.second;
      if(check(p,v1)) v1.pu(p);
    }
    cout<<v1.size()<<endl;
  }
}
