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

void f(vector<vector<int> > &v,int n)
{
  // idx is the first non zero value
  // t(v);
  int idx = n;
  for(int i=0;i<n;i++) 
  {
    if(v[0][i]!=0){idx = i; break;}
  }

  // t(idx);
  for(int j=0;j<n;j++)
  {
    if(j<idx) cout << 0 << " ";
    else
    {
      // Assume v[0][j] to be positive
      // t(-1*v[0][idx],v[0][j],v[idx][j]);
      if(abs(-1*v[0][idx] - v[0][j]) == v[idx][j]) 
      {
        cout << v[0][j] << " ";
      }
      else
      {
        cout << -1*v[0][j] << " ";
      }
    }
  }
  cout << endl;
}

int main()
{
  __;
  int n,q;
  cin >> n >> q;

  vector<vector<int> > v(n,vector<int>(n));
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> v[i][j];

  f(v,n);

  while(q--)
  {
    int idx;
    cin >> idx;
    idx--;

    vector<int> w(n);
    for(int i=0;i<n;i++) cin >> w[i];

    for(int i=0;i<n;i++)
    {
      v[idx][i] = w[i];
      v[i][idx] = w[i];
    }

    f(v,n);
  }
  return 0;
}

