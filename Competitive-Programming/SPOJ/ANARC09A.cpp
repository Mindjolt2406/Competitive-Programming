#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int t = 1;
  while(s[0]!='-')
  {
    int sum1 = 0;
    int count = 0;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='{') sum1++;
      else sum1--;
      if(sum1<0) {sum1+=2;count++;}
    }
    count+=(sum1/2);
    cout<<t<<". "<<count<<endl;
    t++;
    cin>>s;
  }
  return 0;
}
