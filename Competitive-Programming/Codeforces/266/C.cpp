#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  long long int n;
  cin>>n;
  long long int l[n];
  long long int sum1 = 0;
  for(long long int i=0;i<n;i++) {cin>>l[i];sum1+=l[i];}
  long long int k = sum1/3;
  if(sum1%3) {cout<<0<<endl;return 0;}
  long long int count=0,counter=0,sumi = 0;
  for(int i=0;i<n;i++)
  {
    sumi+=l[i];
    if(sumi==k) count++;
    else if(sumi==2*k) counter+=count;
  }
  if(k!=0)cout<<counter<<endl;
  else cout<<((count-1)*(count-2))/2<<endl;
}
