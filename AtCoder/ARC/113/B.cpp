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

ll power(ll x, ll y, ll p = 1e18)
{
  ll res = 1;      // Initialize result
  x = x % p;  // Update x if it is more than or
  while (y > 0)
  {
      if (y & 1)
          res = (res*x) % p;
      y = y>>1; // y = y/2
      x = (x*x) % p;
  }
  return res;
}

int main()
{
  __;
  map<int, vector<int> > digitMap;
  digitMap[0] = {0};
  digitMap[1] = {1};
  digitMap[2] = {6,2,4,8};
  digitMap[3] = {1,3,9,7};
  digitMap[4] = {6,4};
  digitMap[5] = {5};
  digitMap[6] = {6};
  digitMap[7] = {1,7,9,3};
  digitMap[8] = {6,8,4,2};
  digitMap[9] = {1,9};

  ll a, b, c;
  cin >> a >> b >> c;
  int digit = a%10;
  ll modPow = power(b, c, digitMap[digit].size());
  cout << digitMap[digit][modPow] << endl;
  return 0;
}

// 1 -> 1
// 2 -> 2,4,8,6 -> %4
// 3 -> 3,9,7,1 -> %4
// 4 -> 4,6 -> %2
// 5 -> 5 -> %1
// 6 -> 6 -> %1
// 7 -> 7,9,3,1 -> %4
// 8 -> 8,4,2,6 -> %4
// 9 -> 9,1 %2