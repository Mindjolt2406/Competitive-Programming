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
  ll x1,y1,x2,y2;
  cin>>x1>>y1>>x2>>y2;
  if(x1==x2 && y1==y2) {cout<<0<<endl; return 0;}
  int n;
  cin>>n;
  string s;
  cin>>s;
  ll x = x1, y = y1;
  vector<ll> v;
  ll dist = abs(x-x2)+abs(y-y2);
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='U') y++;
    else if(s[i]=='D') y--;
    else if(s[i]=='R') x++;
    else x--;
    v.push_back(abs(x-x2)+abs(y-y2));
  }

  int boo = 0,index = -1;
  for(int i=0;i<v.size();i++)
  {
    if(v[i]-i-1<=0) {boo = 1; index = i;break;}
  }
  if(boo) cout<<index+1<<endl;
  else
  {
    ll a = v[v.size()-1]-n;
    a = dist - a;
    if(x2==1e9 && y2==1e9-1) cout<<"a: "<<a<<endl;
    if(a<=0) {cout<<-1<<endl; return 0;}
    else 
    {
      ll b = dist/a;
      ll c = dist%a;
      int index = -1;
      // t(dist,b);
      // pr(v);
      for(int i=0;i<v.size() && c>0;i++)
      {
        if(v[i]-i-1<=dist-c) {index = i; break;}
      }

      ll count = b*n;
      // if(index==-1 && c>0) cout<<-1<<endl;
      if(index>-1) count+=index+1;
      cout<<count<<endl;
    }
  }
  return 0;
}

