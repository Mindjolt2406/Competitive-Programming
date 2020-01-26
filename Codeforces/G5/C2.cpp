/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
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

vector<pair<int,int> > ans;

int f1d(vector<pair<vector<int>,int> > &v)
{
  // for(int i=0;i<v.size();i++) t(i,v[i].fi,v[i].se);
  for(int i=0;i<v.size() && i+1<v.size();i+=2)
  {
    ans.pu(mp(v[i].se,v[i+1].se));
  }
  if(v.size()%2==1) return v.size()-1;
  return -1;
}

pair<vector<int>,int> f2d(vector<pair<vector<int>,int> > &v)
{
  // _;
  int prev = (v[0].fi)[1];
  vector<pair<vector<int>,int> > w,temp;

  for(int i=0;i<v.size();i++)
  {
    if((v[i].fi)[1] == prev)
    {
      vector<int> temp2 = {(v[i].fi)[1]};
      temp.pu(mp(temp2,v[i].se));
    }
    else
    {
      int a = f1d(temp);
      if(a!=-1) w.pu(temp[temp.size()-1]);
      // for(int i=0;i<w.size();i++) t(i,w[i].se);
      temp.clear();
      prev = (v[i].fi)[1];
      vector<int> temp2 = {(v[i].fi)[1]};
      temp.pu(mp(temp2,v[i].se));
    }
  }
  if(temp.size()) 
  {
    int a = f1d(temp);
    if(a!=-1) w.pu(temp[temp.size()-1]);
    // for(int i=0;i<w.size();i++) t(i,w[i].se);
    temp.clear();
  }

  // t(ans);
  for(int i=0;i<w.size() && i+1<w.size();i+=2)
  {
    ans.pu(mp(w[i].se,w[i+1].se));
  }
  // t(ans);

  if(w.size()%2) return w[w.size()-1];
  else 
  {
    vector<int> temp2;
    return mp(temp2,-1);
  }
}

void f3d(vector<pair<vector<int>,int> > &v)
{
  int prev = (v[0].fi)[0];
  vector<pair<vector<int>,int> > w,temp;

  for(int i=0;i<v.size();i++)
  {
    if((v[i].fi)[0] == prev)
    {
      temp.pu(v[i]);
    }
    else
    {
      pair<vector<int>,int>  a = f2d(temp);
      if(a.se!=-1) w.pu(a);
      temp.clear();
      prev = (v[i].fi)[0];
      temp.pu(v[i]);
    }
    // t(i,ans);
  }
  if(temp.size()) 
  {
    pair<vector<int>,int>  a = f2d(temp);
    if(a.se!=-1) w.pu(a);
    temp.clear();
  }

  for(int i=0;i<w.size() && i+1<w.size();i+=2)
  {
    ans.pu(mp(w[i].se,w[i+1].se));
  }
}

int main()
{
  __;
  vector<pair<vector<int> ,int > > v,w;
  int n;
  cin >> n;
  for(int i=0;i<n;i++)
  {
    int a,b,c;
    cin >> a >> b >> c;
    // vector<int> temp3  ={0,a,b};
    // w.pu(mp(temp3,i+1));
    vector<int> temp2 = {a,b,c};
    v.pu(mp(temp2,i+1));
  }

  sort(v.begin(),v.end());
  // sort(w.begin(),w.end());
  // f2d(w);

  // for(int i=0;i<v.size();i++) cout << v[i].se << " "; cout << endl;
  f3d(v);
  for(int i=0;i<ans.size();i++)
  {
    cout << ans[i].fi << " " << ans[i].se << endl;
  }

  return 0;
}

