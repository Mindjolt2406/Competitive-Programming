#include<bits/stdc++.h>
#define pu push_back
#define m make_pair
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector < pair <int,int> > v;
  for(int i=0;i<n;i++)
  {
    int a,b;
    cin>>a>>b;
    v.pu(m(a,b));
  }
  int maxr = -1,maxw = -1;
  int boo = 1,ten = 0;
  for(int i=0;i<n;i++)
  {
    if(v[i].first<maxr){boo = 0;break;}
    else if(v[i].second<maxw || v[i].second>10){boo = 0;break;}
    else if(v[i].second==10){ten = 1;}
    else if(ten==1){boo = 0;break;}
    if(v[i].first>maxr) maxr = v[i].first;
    if(v[i].second>maxw) maxw = v[i].second;
  }
  if(boo == 0) cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
}
