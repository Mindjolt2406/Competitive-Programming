#include<bits/stdc++.h>
#define pu push_back
#define mp make_pair
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    int l[a-1],m[b-1];
    vector< pair<int,int> >v;
    for(int i=0;i<a-1;i++) {int a;cin>>a;v.pu(mp(a,0));}
    for(int i=0;i<b-1;i++) {int b;cin>>b;v.pu(mp(b,1));}
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int count = 0;
    int countx = 0,county = 0;
    for(int i=0;i<v.size();i++)
    {
      pair<int,int> p = v[i];
      if(p.second) {count+=p.first*(countx+1);county++;}
      else {count+=p.first*(county+1);countx++;}
      // cout<<"first: "<<p.first<<" second: "<<p.second<<" count: "<<count<<endl;
    }
    cout<<count<<endl;
  }
  return 0;
}
