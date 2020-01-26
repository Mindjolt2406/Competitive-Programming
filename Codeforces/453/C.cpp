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
  int h;
  cin>>h;
  int n = 0;
  vector<int> v(h+1);
  for(int i=0;i<=h;i++)
  { 
    cin>>v[i];
    n+=v[i];
  }

  int index = -1,index2 = -1;
  vector<int> w(h+1),ans(n),height(n);
  for(int i=0;i<v.size();i++) 
  {
    if(v[i]>1) index = i;
    w[i] = i;
  }

  for(int i=0;i<=h;i++) ans[i] = i;
  if(index==-1) {cout<<"perfect"<<endl;return 0;}
  else
  {
    int count = h+1;
    for(int i=1;i<v.size();i++)
    {
      for(int j=1;j<v[i];j++)
      {
        t(count,i);
        ans[count] = i-1;
        height[count] = i;
        count++;
      }
    }
  }

  cout<<"ambiguous"<<endl;
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<" "; cout<<endl;
  int a = index, b = -1;
  for(int i=0;i<height.size();i++) if(height[i]==index) b = i;
  for(int i=0;i<ans.size();i++) 
  {
    if(ans[i]==a) ans[i] = b;
    else if(ans[i]==b) ans[i] = a;
  }
  for(int i=0;i<ans.size();i++) cout<<ans[i]<<" "; cout<<endl;

  return 0;
}

