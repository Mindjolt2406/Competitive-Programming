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
#define EPS 1e-6
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

ld max(ld x, ld y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int boo = 0;
    ld x1,x2,x3,t1,t2,t3;
    cin>>x1>>t1>>x2>>t2>>x3>>t3;
    if((x1+x2) < x3 || !(t1<=t3 && t3<=t2)) {cout<<"NO"<<endl; continue;}
    else if(abs(t3-t2)<EPS) 
    {
      if(x2>=x3) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
      continue;
    }
    else if(abs(t3-t1)<EPS)
    {
      if(x1>=x3) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
      continue;
    }

    ld beg = 0, end = x1, total = x3;
    ld t = ((t3-t1))/(t2-t3);
    while(beg<=end)
    {
      ld mid = (beg+end)/2;
      ld x = mid, y = x*t;
      if(x>x1 || y>x2) end = mid-0.001;
      else if(x+y>=x3) {boo = 1; break;}
      else beg = mid+0.001;
    }
    if(boo) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}

