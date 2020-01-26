/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+2
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

ll min(ll x, ll y)
{
  if(x>y) return y;
  return x;
}

int main()
{
  __;
  int n;
  cin>>n;
  vector<ll> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int q;
  cin>>q;
  cin.ignore();
  while(q--)
  {
    char t[100];
    cin.getline(t,100);
    string s = t;
    istringstream is(s);
    int k;
    vector<ll> w;
    while( is >> k ) w.pu(k);
    // pr(v);
    if(w.size()==3)
    {
      int b = w[0], c = w[1];
      ll d = w[2];
      if(b>c) 
      {
        for(int i=0;i<=c;i++) v[i]+=d;
        for(int i=b;i<n;i++) v[i]+=d;
      }
      else for(int i=b;i<=c;i++) v[i]+=d;
    }
    else
    {
      int b = w[0], c = w[1];
      ll min1 = INF;
      if(b>c)
      {
        for(int i=0;i<=c;i++) min1 = min(min1,v[i]);
        for(int i=b;i<n;i++) min1 = min(min1,v[i]);
      }
      else for(int i=b;i<=c;i++) min1 = min(min1,v[i]);
      cout<<min1<<endl;
    }
  }
  return 0;
}

