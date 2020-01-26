/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  string s;
  cin>>s;
  int n = s.size();
  char c1,c2;
  c1 = s[0],c2 = s[n-1];

  int cnt = 0;
  int boo1 = 1, boo2 = 0;
  for(int i=0;i<s.size();i++) if(s[i]==s[0]) cnt++;

  if(s[0]!=s[n-1])
  {
    for(int i=0;i<s.size();i++)
    {
      if(s[i]==s[0]) cnt--;
      else if(s[i]==c2) boo2 = 1;
      else
      {
        // t(c2,i,boo1,boo2);
        if(boo1==0 || boo2==0) continue;
        else {cout<<"NO"<<endl; return 0;}
      }
      if(cnt==0) boo1 = 0;
    }
    cout<<"YES"<<endl;
  }
  else
  {
    set<char> d;
    for(int i=0;i<s.size();i++) d.insert(s[i]);
    if(d.size()<=2) cout<<"YES"<<endl;
    else
    {
      char c1,c2;
      int i=0;
      while(s[0]==s[i]) i++;
      c1 = s[i];
      i=n-1;
      while(s[n-1]==s[i]) i--;
      c2 = s[i];

      int cnt = 0;
      for(int i=0;i<s.size();i++) if(s[i]==c1) cnt++;
      int boo1 = 0, boo2 = 0;
      int k = cnt;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]==c1) {cnt--;boo1 = 1;}
        else if(s[i]==c2) boo2 = 1;
        else
        {
          if(boo1==0 || boo2==0) continue;
          else {cout<<"NO"<<endl; return 0;}
        }
        if(cnt==0) boo1 = 0;
      }
      cout<<"YES"<<endl;
    }
  }
  return 0; 
}

