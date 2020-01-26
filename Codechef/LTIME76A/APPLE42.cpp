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
#define PI atan(1)*4
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
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

ld min(ld x, ld y)
{
  if(x<y) return x;
  return y;
}

ld max(ld x, ld y)
{
  if(x>y) return x;
  return y;
}

int check(ld theta, vector<pair< pair<ld,ld>,int> > &v)
{
  vector< pair< pair < ld,ld > , int > > w;

  ld min1 = INF, min2 = INF, max1 = -INF, max2 = -INF;
  for(int i=0;i<v.size();i++)
  {
    pair<ld,ld> p = v[i].fi;
    ld x = p.fi, y = p.se, X,Y;
    X = x*cos(theta) + y*sin(theta);
    Y = -x*sin(theta) + y*cos(theta);

    w.pu(mp(X,Y),v[i].se);

    if(v[i].se)
    {
      min1 = min(min1,X);
      max1 = max(max1,Y);
    }
    else
    {
      min2 = min(min2,X);
      max2=  max(max2,Y);
    }
  }

  if(min2 < min1)
  {
    swap(min2,min1);
    swap(max2,max1);
  }

  if(max2-min1 > 0) return 0; // SUCCESS
  else if()
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,m;
    cin >> n >> m;
    vector<pair<pair<ld,ld>,int> > v;
    for(int i=0;i<n;i++)
    {
      ld x,y;
      cin >> x >> y;
      v.pu(mp(mp(x,y),0));
    }

    for(int i=0;i<m;i++)
    {
      ld x,y;
      cin >> x >> y;
      v.pu(mp(mp(x,y),1));
    }

    ld beg = 0, end = PI; // PI
    bool boo = true;
    while(beg <= end)
    {
      ld mid = (beg + end) >> 1;
      int status = check(mid,v);

      if(status == 0) // Rotate by 90
      {
        mid += PI/2;
        if(beg <= mid && mid <= end) continue;
        else { boo = false; break; }
      }
      else if(status == 1)
      {

      }
    }
  }
  return 0;
}

