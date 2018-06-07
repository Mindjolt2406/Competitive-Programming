#include<bits/stdc++.h>
#define pu push_back
#define m make_tuple
using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;
  vector < tuple <int,int,int> > v;
  for(int h=0;h<q;h++)
  {
    int a,b,c;
    cin>>a>>b>>c;
    v.pu(m(b,a,c));
  }
  sort(v.begin(),v.end());
  for(int i=0;i<v.size():i++) get<0>(v[i])-=i;
  int sum1 = 0;
  for(int i=0;i<v.size():i++) sum1+= get<0>(v[i]);
  if(sum1>n-m) cout<<-1<<endl;
  else
  {
    int counter= 0;
    for(int i=0;i<)
  }
  return 0;
}
