#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  string s;
  cin>>s;
  int count1=  0, count2 = 0;
  vector <int> v;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='-') count1++;
    else {v.pu(count1);count1= 0;count2++;}
  }
  if(count2==0){cout<<"YES"<<endl;return 0;}
  if(count1!=0) v[0]+=count1;
  int sum1 = 0;
  for(int i=0;i<v.size();i++)
  {
    sum1+=v[i];
  }
  if(sum1%count2==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
