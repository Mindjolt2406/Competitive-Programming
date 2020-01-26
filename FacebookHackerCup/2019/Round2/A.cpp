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

int dist(pair<int,int> p1, pair<int,int> p2)
{
  return (abs(p1.fi-p2.fi)+abs(p1.se-p2.se))%2;
}

bool check(pair<int,int> &p1, pair<int,int> &p2,pair<int,int> &p,int n,int m)
{
  // Corner 1,1
  // t(p,p1,p2);
  if(dist(p1,p2)==1) return false;
  // _;
  if(dist(p,mp(1,1))==dist(p1,mp(1,1)) && dist(p,mp(1,1))==dist(p2,mp(1,1))) return true;
  if(dist(p,mp(n,m))==dist(p1,mp(n,m)) && dist(p,mp(n,m))==dist(p2,mp(n,m))) return true;
  if(dist(p,mp(n,1))==dist(p1,mp(n,1)) && dist(p,mp(n,1))==dist(p2,mp(n,1))) return true;
  if(dist(p,mp(1,m))==dist(p1,mp(1,m)) && dist(p,mp(1,m))==dist(p2,mp(1,m))) return true;
  return false;
}

int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int> > v;
    int x,y;
    cin>>x>>y;
    pair<int,int> p = mp(x,y);

    for(int i=0;i<k;i++)
    {
      int a,b;
      cin>>a>>b;
      v.pu(mp(a,b));
    }

    if(k==1) cout<<"Case #"<<h<<": N"<<endl;
    else
    {
      if(check(v[0],v[1],p,n,m)) cout<<"Case #"<<h<<": Y"<<endl;
      else cout<<"Case #"<<h<<": N"<<endl;
    }
    // cout<<"Case #"<<h<<": "<<ans<<endl;
  }
  return 0;
}

