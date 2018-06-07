#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pu push_back
using namespace std;

int main()
{
  vector<int> v,v1;
  string s;
  cin>>s;
  int boo = s[0]-'a';
  int count = 0;
  int k = boo;
  for(int i=0;i<s.size();i++)
  {
    //cout<<boo<<" "<<s[i]-'a'<<" "<<count<<endl;
    if(boo==s[i]-'a'){count++;}
    else{v.pu(count);count=1;boo++;boo%=2;}
  }
  v.pu(count);
  // for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
  // cout<<endl;
  for(int i=0;i<v.size();i++)
  {
    v1.pu(k);
    k++;
    k%=2;
  }
  k = s[s.size()-1]-'a';
  int max1=0,max0=0;
  for(int i=v.size()-1;i>=0;i--)
  {
    if(v1[i]==1)v[i]+=max0;
    else if(v[i]>max0)max0 = v[i];
  }
  // for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
  // cout<<endl;
  for(int i=v.size()-1;i>=0;i--)
  {
    if(v1[i]==0)v[i]+=max1;
    else if(v[i]>max1)max1 = v[i];
  }
  for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
  cout<<endl;
  cout<<*max_element(v.begin(),v.end())<<endl;
  return 0;
}
