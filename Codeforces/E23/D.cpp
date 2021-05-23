#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


int main()
{
  __;

  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  vector<ll> maxLeft(n), maxRight(n), minLeft(n), minRight(n);
  stack<pair<int, int> > nextMaxLeft, nextMaxRight, nextMinLeft, nextMinRight;

  for(int i=0;i < n; i++) {
    while(!nextMaxRight.empty() && nextMaxRight.top().fi <= v[i]) {
      pair<int, int> temp = nextMaxRight.top();
      nextMaxRight.pop();
      maxRight[temp.se] = i-temp.se;
    }
    nextMaxRight.push(mp(v[i], i));
  }
  while(!nextMaxRight.empty()) {
    pair<int, int> temp = nextMaxRight.top();
    nextMaxRight.pop();
    maxRight[temp.se] = n-temp.se;
  }

  for(int i = 0;i < n; i++) {
    while(!nextMinRight.empty() && nextMinRight.top().fi > v[i]) {
      pair<int, int> temp = nextMinRight.top();
      nextMinRight.pop();
      minRight[temp.se] = i-temp.se;
    }
    nextMinRight.push(mp(v[i], i));
  }
  while(!nextMinRight.empty()) {
    pair<int, int> temp = nextMinRight.top();
    nextMinRight.pop();
    minRight[temp.se] = n-temp.se;
  }

  for(int i = n-1; i >= 0; i--) {
    while(!nextMaxLeft.empty() && nextMaxLeft.top().fi < v[i]) {
      pair<int, int> temp = nextMaxLeft.top();
      nextMaxLeft.pop();
      maxLeft[temp.se] = temp.se-i;
    }
    nextMaxLeft.push(mp(v[i], i));
  }
  while(!nextMaxLeft.empty()) {
    pair<int, int> temp = nextMaxLeft.top();
    nextMaxLeft.pop();
    maxLeft[temp.se] = temp.se+1;
  }

  for(int i = n-1; i >= 0; i--) {
    while(!nextMinLeft.empty() && nextMinLeft.top().fi >= v[i]) {
      pair<int, int> temp = nextMinLeft.top();
      nextMinLeft.pop();
      minLeft[temp.se] = temp.se-i;
    }
    nextMinLeft.push(mp(v[i], i));
  }
  while(!nextMinLeft.empty()) {
    pair<int, int> temp = nextMinLeft.top();
    nextMinLeft.pop();
    minLeft[temp.se] = temp.se+1;
  }

  ll ans = 0;
  for(int i=0;i<n;i++) {
    ans += (maxRight[i] * maxLeft[i]) * v[i];
    ans -= (minRight[i] * minLeft[i]) * v[i];
  }

  cout << ans << endl;
  return 0;
}
