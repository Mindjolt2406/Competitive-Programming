#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  int n,w;
  cin>>n>>w;
  int l[n];
  for(int i=0;i<n;i++) cin>>l[i];
  int min1,max1;
  min1 = -1*(min(l[0],0));
  max1 = w-l[0];
  int min2 = min1;
  int max2 = max1;
  if(max2>w) {max1-=(max2-w);max2 = w;}
  int boo = 1;
  for(int i=0;i<n;i++)
  {
    // cout<<"Entered"<<endl;
    min2+=l[i];
    max2+=l[i];
    // cout<<"min2: "<<min2<<" max2: "<<max2<<endl;
    if(max2>w) {max1-=(max2-w);max2 = w;}
    if(min2<0) {min1-=min2;min2 = 0;}
    if(max2<min2) {boo = 0;break;}
    else if(max2<0 || min2 >w) {boo = 0;break;}
  }
  // cout<<"max1: "<<max1<<" min1: "<<min1<<endl;
  if(boo)cout<<max1-min1+1<<endl;
  else cout<<0<<endl;
  return 0;
}
