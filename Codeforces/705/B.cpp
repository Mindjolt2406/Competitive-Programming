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

pair<int, int> inc(pair<int, int> p, int h, int m) {
  p.se++;
  p.se %= m;
  if(!p.se) {
    p.fi++;
    p.fi %= h;
  }
  return p;
}

bool isMirrorValid(pair<int, int> p, int h, int m) {
  map<int, int> d;
  d[0] = 0;
  d[1] = 1;
  d[2] = 5;
  d[5] = 2;
  d[8] = 8;

  vector<int> digits = {p.fi/10, p.fi%10, p.se/10, p.se%10};
  for(auto it : digits) if(!d.count(it)) return false;

  pair<int, int> reversedTime = mp(d[(p.se%10)]*10 + d[p.se/10], d[(p.fi%10)]*10 + d[p.fi/10]);
  return reversedTime.fi < h && reversedTime.se < m;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--) {
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    int a = (s[0]-'0')*10 + (s[1]-'0');
    int b = (s[3]-'0')*10 + (s[4]-'0');
    pair<int, int> currTime = mp(a, b);
    while(!isMirrorValid(currTime, h, m)) {
      currTime = inc(currTime, h, m);
    }
    string s1 = (currTime.fi < 10) ? "0" : "";
    string s2 = (currTime.se < 10) ? "0" : "";
    cout << s1 << currTime.fi << ":" << s2 << currTime.se << endl;
  }
  return 0;
}
