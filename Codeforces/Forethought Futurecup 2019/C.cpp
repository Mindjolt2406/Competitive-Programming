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
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    cout<<1<<" "<<n-1<<" ";
    cout<<1<<" ";
    for(int i=2;i<=n;i++) cout<<i<<" "; cout<<endl;
    int max1;
    cin>>max1;
    if(max1==-1) break;
    int beg = 2, end = n;
    while(beg<=end)
    {
      int mid = (beg+end)/2;
      // [beg,mid] (mid+1,end)
      cout<<1<<" "<<mid-beg+1<<" ";
      cout<<1<<" ";
      for(int i=beg;i<=mid;i++) cout<<i<<" ";
      cout<<endl;
      int max3;
      cin>>max3;
      if(max3==-1) return 0;
      if(max3<max1) beg = mid+1;
      else end = mid-1;
    }
    int a = beg;
    cout<<1<<" "<<n-1<<" ";
    cout<<a<<" ";
    for(int i=1;i<=n;i++) if(i!=a) cout<<i<<" "; cout<<endl;
    int max2;
    cin>>max2;
    if(max2==-1) break;
    cout<<-1<<" "<<max2<<endl;
  }
  return 0;
}

