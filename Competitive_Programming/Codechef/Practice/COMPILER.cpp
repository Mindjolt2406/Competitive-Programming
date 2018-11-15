#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int sum1 = 0;
    int count = 0;
    int max1 = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='<') sum1++;
      else if(s[i]=='>' && sum1>0){sum1--;}
      else if(s[i]=='>')break;
      if(sum1==0) max1 = i+1;
    }
    cout<<max1<<endl;
  }
}
