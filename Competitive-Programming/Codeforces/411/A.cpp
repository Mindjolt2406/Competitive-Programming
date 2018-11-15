#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int c = n%4;
  int d = n/4;
  string s;
  for(int i=0;i<d;i++) s+="baab";
  if(c==1) s+="b";
  else if(c==2) s+="ba";
  else if(c==3) s+="baa";
  cout<<s<<endl;
  return 0;
}
