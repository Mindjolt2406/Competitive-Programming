#include<bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    long long int a,b;
    cin>>a>>b;
    if(a==b) {cout<<0<<endl;return 0;}
    if(b==1 || b==0) {cout<<-1<<endl; return 0;}
    string sa,sb;
    // cin>>sa>>sb;
    int counta = 0, countb = 0;
    // for(int i=0;i<sa.size();i++) if(sa[i]=='1') counta++;
    // for(int i=0;i<sb.size();i++) if(sb[i]=='1') countb++;
    while(a)
    {
      if(a&1) {sa ='1'+sa;counta++;}
      else sa ='0'+sa;
      a = a>>1;
    }
    while(b)
    {
      if(b&1) {sb ='1'+sb;countb++;}
      else sb ='0'+sb;
      b = b>>1;
    }
    int countc = 0,count = 0,countd = 0;
    int c = abs(counta-countb);
    int a1 = counta, b1 = countb;
    for(int i=0;i<sa.size();i++)
    {
      if(counta==0) {countc = sa.size()-i;break;}
      else if(sa[i]=='1')counta--;
    }
    for(int i=0;i<sb.size();i++)
    {
      if(countb==0) {countd = sb.size()-i;break;}
      else if(sb[i]=='1')countb--;
    }
    if(b1<=a1)
    {
      cout<<c+1+countd<<endl;
    }
    else cout<<c + countd<<endl;
  }
  return 0;
}
