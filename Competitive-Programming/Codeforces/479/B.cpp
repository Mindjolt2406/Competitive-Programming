#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;
  cin>>n>>s;
  map <string, int> d;
  map <string,int> :: iterator it;
  for(int i=0;i<n-1;i++)
  {
    if(d.find(s.substr(i,2))==d.end()) d[s.substr(i,2)] = 1;
    else d[s.substr(i,2)]++;
  }
  int max1 = 0;
  for(it = d.begin();it!=d.end();it++)
  {
    max1 = max(it->second,max1);
  }
  for(it = d.begin();it!=d.end();it++)
  {
    if(max1==it->second){cout<<it->first<<endl;break;}
  }
  return 0;
}
