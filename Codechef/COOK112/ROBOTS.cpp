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

pair<ld,ld> f(int i,vector<int> v)
{
  pair<ld,ld> p;
  p.fi = 1*v[0] + (ld)v[2]*0.5;
  p.se = 1*v[1] + (ld)(sqrt(3))/2*v[3];
  return p;
}

int main()
{
  __;
  int t;
  cin >> t;
  ld PI6 = (atan(1)*4)/3;
  while(t--)
  {
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int> > v;
    vector<int> w;
    int prev = 0;
    for(int i=0;i<n;i++)
    {
      vector<int> x(4);
      if((s[i] - '0' + prev)%6== 0)
      {
        // p = mp(1,0);
        x = {1,0,0,0};
        prev = 0;
      }
      else if((s[i] - '0' + prev)%6== 1)
      {
        x = {0,0,1,1};
        prev = 1;
        // p = mp(1/2.0,sqrt(3)/2);
      }
      else if((s[i] - '0' + prev)%6== 2)
      {
        x = {0,0,-1,1};
        prev = 2;
        // p = mp(-1/2.0,sqrt(3)/2);
      }
      else if((s[i] - '0' + prev)%6== 3)
      {
        x = {-1,0,0,0};
        prev = 3;
        // p = mp(-1,0);
      }
      else if((s[i] - '0' + prev)%6== 4)
      {
        x = {0,0,-1,-1};
        prev = 4;
        // p = mp(-1/2.0,-sqrt(3)/2.0);
      }
      else if((s[i] - '0' + prev)%6== 5)
      {
        x = {0,0,1,-1};
        prev = 5;
        // p = mp(1/2.0,-sqrt(3.0)/2);
      }
      v.pu(x);
      w.pu(prev);
    }
    for(int i=1;i<v.size();i++)
    {
      for(int j=0;j<4;j++) v[i][j] += v[i-1][j];
    }

    while(q--)
    {
      int l,r;
      cin >> l >> r;
      l--; r--;
      ld a,b;
      int rot = 0;
      if(l == 0) 
      {
        a =  f(r,v[r]).fi;
        b = f(r,v[r]).se;
      }
      else 
      {
        a = f(r,v[r]).fi - f(l-1,v[l-1]).fi;
        b = f(r,v[r]).se - f(l-1,v[l-1]).se;
        rot = w[l-1];
        // a = v[r] - v[l-1];
        // b = w[r] - w[l-1];
      }

      int dif = 6-rot;
      ld x = a*cos(dif*PI6) - b*sin(dif*PI6);
      ld y = a*sin(dif*PI6) + b*cos(dif*PI6);

      cout << fixed << setprecision(7);
      cout << x << " " << y << endl;
    }
  }
  return 0;
}

