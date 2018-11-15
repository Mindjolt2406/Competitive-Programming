#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int l[26] = {0};
  for(int i=0;i<s.size();i++)
  {
    l[s[i]-'a']++;
  }
  int count = 0;
  for(int i=0;i<26;i++) if(l[i]%2==1) count++;
  if(count%2==0 && count==0) cout<<"First"<<endl;
  else if(count%2==0) cout<<"Second"<<endl;
  else cout<<"First"<<endl; 
  return 0;
}
