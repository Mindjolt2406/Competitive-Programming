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

const int N = 1e5+100;

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
      if(s[i] == '0') v[i] = -1;
      else v[i] = 1;
    }

    for(int i=1;i<n;i++) v[i]  += v[i-1];

    // t(v);

    // vector<vector<int> > w(N,vector<int> (2,-1));
    map<int,pair<int,int>  > d;

    // for(int i=-N;i<=N;i++) d[i] = mp(INF,-1);
    // for(int i=0;i<N;i++) {w[i][0] = INF; w[i][1] = -1;}

    d[0].fi = -1;

    for(int i=0;i<n;i++)
    {
      if(d.find(v[i])!=d.end())
      {
        d[v[i]].fi  = min(d[v[i]].fi,i);
        d[v[i]].se = max(d[v[i]].se,i);
      }
      else
      {
        d[v[i]].fi = d[v[i]].se = i;
      }
    }

    int max1 = 0;
    for(auto it : d)
    {
      if(it.se.se != -1) max1 = max(max1,it.se.se - it.se.fi);
      // if(d[i].se != -1) max1 = max(max1,d[i].se-d[i].fi);
    }

    // for(int i=0;i<20;i++) t(i,w[i]);
    cout << max1 << endl;

  }
  return 0;
}

