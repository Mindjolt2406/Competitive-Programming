#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  n = 2*n-2;
  string s;
  cin>>s;
  int l[26]={0};
  int count = 0;
  for(int i=0;i<n;i++)
  {
    int c = s[i]-'a';
    if(c>=0 && c<26) l[c]++;
    else if(l[s[i]-'A']>0) {l[s[i]-'A']--;}
    else {count++;}
    // cout<<"i: "<<i<<" count: "<<count<<" c: "<<c<<endl;
    // for(int i=0;i<26;i++) cout<<l[i]<<" ";
    // cout<<endl;
  }
  cout<<count<<endl;
  return 0;
}
