#include<bits/stdc++.h>
#define INF 1000000001
using namespace std;

int main()
{
  int n;
  cin>>n;
  int l[n],m[n];
  for(int i=0;i<n;i++) cin>>l[i];
  for(int i=0;i<n;i++) cin>>m[i];
  int beg,mid,end;
  int min1 = INF;
  for(int i=1;i<n-1;i++)
  {
    int minbeg = INF,minend = INF;
    for(int j=0;j<i;j++)
    {
      if(l[j]<l[i]) minbeg = min(minbeg,m[j]);
    }
    for(int j=i+1;j<n;j++)
    {
      if(l[j]>l[i]) minend = min(minend,m[j]);
    }
    if(minbeg!=INF && minend!= INF) min1 = min(min1,minbeg+m[i]+minend);
    // cout<<"i: "<<i<<" min1: "<<min1<<" minbeg: "<<minbeg<<" minend: "<<minend<<endl;
  }
  if(min1!=INF) cout<<min1<<endl;
  else cout<<-1<<endl;
}
