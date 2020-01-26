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


int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    string s;
    cin >> s;
    int x = 0, y = 0,minx = INF, maxx = 0, miny = INF, maxy = 0;
    vector<pair<int,int> > v;
    for(int i=0;i<s.size();i++)
    {
      if(s[i]=='W') y++;
      else if(s[i]=='A') x--;
      else if(s[i]=='D') x++;
      else if(s[i]=='S') y--;

      v.pu(mp(x,y));

      maxy = max(maxy,y);
      maxx = max(maxx,x);
      miny = min(miny,y);
      minx = min(minx,x);
    }

    ll area = (ll)abs(maxy-miny)*abs(maxx-minx);
    t(area,minx,maxx,miny,maxy);

    bool bmaxy = false, bmaxx = false, bminy = false,bminx = false;
    bool left = true, right = true, up = true, down = true;

    x = 0; y = 0;
    
    for(int i=s.size()-1;i>=0;i--)
    {
      if(v[i].fi == maxx && bminx) right = false;
      if(v[i].fi == minx && bmaxx) left = false;

      if(v[i].se == maxy && bminy) down = false;
      if(v[i].se == miny && bmaxy) up = false; 

      if(v[i].fi == maxx) bmaxx = true;
      if(v[i].fi == minx) bminx = true;

      if(v[i].se == maxy) bmaxy = true;
      if(v[i].se == miny) bminy = true;
    }

    if(up || down) area = min(area,area - abs(maxx-minx));
    if(left || right) area = min(area,area - abs(miny-maxy));

    cout << area << endl;
  }
  return 0;
}

