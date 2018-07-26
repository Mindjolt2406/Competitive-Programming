#include<bits/stdc++.h>
#define mp make_pair
#define pu push_back
#define mt make_tuple
#define INF 1000000001
using namespace std;

int check(string s)
{
  if(s[0]!='R') return 0;
  int boo = 0;
  for(int i=0;i<s.size();i++)
  {
    if(65<=s[i] && s[i]<=90 && boo == 1) return 1;
    else if(s[i]-'0'<11) boo = 1;
  }
  return 0;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    if(check(s))
    {
      // cout<<"here"<<endl;
      int i = 1;
      string k;
      for(i=1;i<s.size() && s[i]!='C';i++)
      {
        k+=s[i];
      }
      // cout<<k<<endl;
      if(s[i]=='C')i++;
      string k1;
      for(;i<s.size();i++)
      {
        k1+=s[i];
      }
      stringstream geek(k1);
      long long int a = 0;
      geek >> a;
      int prod = 26;
      string k2;
      while(a)
      {
        int c = a%prod;
        cout<<"c: "<<c<<endl;
        k2 = (char)(c + 'A') + k2;
        a/=prod;
      }
      cout<<k2<<k<<endl;
    }
    else
    {
      string k,k1;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]<65) k1+=s[i];
        else k+=s[i];
      }
      long long int prod = 1;
      long long int count = 0;
      for(int i=k.size()-1;i>=0;i--)
      {
        count+=prod*(s[i]-'A'+1);
        prod*=26;
        // cout<<"count: "<<count<<endl;
      }
      cout<<"R"<<k1<<"C"<<count<<endl;
    }
  }
  return 0;
}
