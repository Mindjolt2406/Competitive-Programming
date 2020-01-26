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
  int n,m;
  ll k;
  cin>>n>>m>>k;
  vector<int> v(n+m+10);
  k = n*m+1-k;
  // t(k);
  for(int i=1;i<=n+m;i++)
  {
    int k = i;
    int xmax = min(k-1,n);
    int ymin = k-xmax;
    int ymax = min(k-1,m);
    int y = ymax-ymin+1;
    int x = xmax;
    int min1 = min(x,y);
    v[i] = min1;
  }

  // for(int i=1;i<=n+m;i++) t(i,v[i]);

  int min1 = INF;
  for(int i=n+m;i>=1;i--)
  {
    k-=v[i];
    if(k<=0) {min1 = i;k+=v[i];break;}
  }

  // t(min1);

  vector<ll> w;
  for(int i=1;i<min1;i++)
  {
    if(i<=n && min1-i <=m) w.pu(i*(min1-i));
  }
  sort(w.begin(),w.end());
  reverse(w.begin(),w.end());

  cout<<w[k-1]<<endl;
  return 0;
}

