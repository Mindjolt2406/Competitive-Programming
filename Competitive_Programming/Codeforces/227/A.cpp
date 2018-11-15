#include<bits/stdc++.h>
using namespace std;

int main()
{
  string a,b;
  cin>>a>>b;
  int h1,h2,m1,m2;
  h1 = stoi(a.substr(0,2));
  m1 = stoi(a.substr(3,2));
  h2 = stoi(b.substr(0,2));
  m2 = stoi(b.substr(3,2));
  int h3 = 0,m3 = 0,boo = 0;
  m3 = m1-m2;
  if(m3<0){m3+=60;boo = 1;}
  h3-=boo;
  h3 += (h1-h2);
  if(h3<0) h3+=24;
  if(h3==0) cout<<"00:";
  else if(h3/10==0) cout<<"0"<<h3<<":";
  else cout<<h3<<":";
  if(m3==0)cout<<"00"<<endl;
  else if(m3/10==0) cout<<"0"<<m3<<endl;
  else cout<<m3<<endl;
}
