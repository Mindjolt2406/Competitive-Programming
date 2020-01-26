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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;
  int n,m;
  cin>>n>>m;
  vector<int> v(n);
  for(int i=0;i<n;i++) v[i] = 4999-i;
  vector<pair<int,int> > w(n);
  for(int i=0;i<n;i++) w[i] = mp(-1,-1);
  vector<pair<int,int> > un;

  while(m--)
  {
    int a,b,c;
    cin>>a>>b>>c;
    b--;c--;
    if(a==0) un.pu(mp(b,c));
    else
    {
      int left = w[b].fi, right = w[c].se;
      if(left==-1) left = b;
      if(right==-1) right = c;

      for(int i=left;i<=right;i++) 
      {
        w[i] = mp(left,right);
        v[i] = 4999-left;
      }
    }
  }

  sort(un.begin(),un.end());
  for(int i=0;i<un.size();i++)
  {
    pair<int,int> p = un[i];
    if(w[p.fi]==w[p.se] && w[p.fi]!=mp(-1,-1)) {cout<<"NO"<<endl; return 0;}
    else if(w[p.fi]==mp(-1,-1)) continue;
    else
    {
      // _;
      int a = v[w[p.fi].fi];
      // v[p.se] = a-1;
      int c = w[p.se].fi, d = w[p.se].se;
      if(w[p.se]==mp(-1,-1)) v[p.se] = a-1;
      else for(int i=c;i<=d;i++) v[i] = a-1;
    }
  }

  cout<<"YES"<<endl;
  pr(v);
  return 0;
}

