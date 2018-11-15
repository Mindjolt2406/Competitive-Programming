#include<bits/stdc++.h>
#define pu push_back
using namespace std;

int main()
{
  int n;
  string s;
  cin>>n>>s;
  int i=0;
  int count = 0;
  int counter = 0;
  while(i<n)
  {
    if(s[i]=='x')
    {
      while(s[i]=='x')
      {
        count++;
        if(count>=3) counter++;
        i++;
      }
      count = 0;
    }
    else i++;
  }
  cout<<counter<<endl;
  return 0;
}
