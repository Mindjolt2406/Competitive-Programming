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
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int main()
{
  int n;
  sc(n);
  ll*l = new ll[n];
  for(int i=0;i<n;i++) scll(l[i]);
  vector<string> v;
  for(int i=0;i<n;i++)
  {
    string s;
    scr(s);
    v.pu(s);
  }
  int boo = 0;
  vector<int> dp;
  dp.assign(0,n);
  for(int i=1;i<v.size();i++)
  {
    if(v[i].size()>v[i-1].size())
    {
      string a = v[i],b = v[i-1];
      string c = a,d = b;
      reverse(c.begin(),c.end());
      reverse(d.begin(),d.end());
      if(a==b.substr(0,a.size()))
      {
        
      }
      else if(a==d.substr(0,a.size()))
      {

      }
      else if(c==b.substr(0,c.size()))
      {

      }
      else if(c==d.substr(0,c.size()))
      {

      }
    }
    else if(v[i].size()==v[i-1].size())
    {

    }
    else
    {
      boo = 1;
      break;
    }
  }
  return 0;
}

