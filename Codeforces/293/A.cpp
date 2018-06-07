#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s,t,k;
  cin>>s>>t;
  int c = s.size()-1;
  while(c>=0) {if(s[c]=='z')c--;else break;}
  for(int i=0;i<=c;i++) k+=s[i];
  k[c]++;
  for(int i=c+1;i<s.size();i++) k+='a';
  int boo = 0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]<t[i]){boo = 1;break;}
    else if(s[i]==t[i]) continue;
    else {boo = -1;break;}
  }
  if(k==t || boo<1) cout<<"No such string"<<endl;
  else cout<<k<<endl;
  return 0;
}
