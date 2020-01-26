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


int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n),w(n),ans(n),arr(n);
  set<int> s;
  map<int,int> it_to_idx;

  for(int i=0;i<n;i++) cin >> v[i];

  w = v;
  sort(w.begin(),w.end());

  map<int,deque<int> > d;
  for(int i=0;i<n;i++) 
  {
    d[w[i]].pu(i);
  }

  for(int i=0;i<n;i++)
  {
    arr[i] = d[v[i]].back();
    d[v[i]].pop_back();
  }

  // for(int i=0;i<n;i++) cout << arr[i] << " "; cout << endl;

  // Work with arr now

  for(int i=0;i<n;i++)
  {
    int left = 0, right = 0;
    s.insert(arr[i]);
    it_to_idx[arr[i]] = i;
    auto it = s.find(arr[i]);
    if(arr[i] != *s.begin())
    {
      it--;
      int idx = it_to_idx[*it];
      left = ans[idx];
      // t(i,left);
    }

    it = s.find(arr[i]);
    it++;
    if(it != s.end())
    {
      int idx = it_to_idx[*it];
      right = ans[idx];
      // t(i,right);
    } 

    // t(i,arr[i],left,right);
    int level = max(left,right);
    level++;
    ans[i] = level;
  }

  for(int i=0;i<n;i++) cout << ans[i] << " "; cout << endl;
  return 0;
}

