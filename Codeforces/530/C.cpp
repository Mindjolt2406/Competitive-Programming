#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  string s;
  cin>>s;
  int k;
  cin>>k;
  int count = 0,mincount = 0,boo = 0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='?') {mincount--;count++;}
    if(s[i]=='*') {boo = 1;count++;mincount--;}
  }
  int maxcount = s.size() - count;
  if(boo) maxcount = INF;
  mincount = s.size()+mincount-count;
  for(int i=1;i<s.size();i++)
  {
    if(s[i]=='?' || s[i]=='*') swap(s[i],s[i-1]);
  }
  
  // t(s);
  if(mincount<=k && k<=maxcount)
  {
    string s1;
    if(k>s.size()-count)
    {
      int boo = 0;
      for(int i=0;i<s.size();i++)
      {
        if(s[i]=='*' && boo==0) boo = 1;
        else if(s[i]=='*') continue;
        else if(boo==1)
        {
          // t(k-s.size()+count);
          for(int j=0;j<=k-s.size()+count;j++) s1+=s[i];
          boo = 2;
        }
        else if(s[i]=='?') continue;
        else s1+=s[i];
      }
    }
    else
    {
      int i=0;
      k = s.size()-count-k;
      while(i<s.size())
      {
        if(k>0 && (s[i]=='?' || s[i]=='*')) {i+=2;k--;continue;}
        else if(s[i]=='?' || s[i]=='*') {i++;continue;}
        s1+=s[i];
        i++;
      }
    }
    cout<<s1<<endl;
  }
  else cout<<"Impossible"<<endl;
  return 0;
}

