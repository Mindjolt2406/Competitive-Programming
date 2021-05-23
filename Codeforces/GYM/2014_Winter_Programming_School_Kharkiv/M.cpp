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

const int N = 110;
vector<ld> logFact(N);

void precompute() {
  logFact[0] = 0;

  for(int i=1;i<N;i++) {
    logFact[i] = logFact[i-1] + log(i);
  }
}

ll C(int n, int r) {
  return roundl(exp(logFact[n] - logFact[n-r] - logFact[r]));
}

ld logNCR(int n, int r) {
  if(n<r) return 0;
  return logFact[n] - logFact[n-r] - logFact[r];
}

ld div(int n1, int r, int n2, int k) {
  if(n1 < r || n2 < k) return 0;
  return exp(logNCR(n1, r) - logNCR(n2, k));
}

ld calK(int n, int k) {
  ld sum1 = 0;

  for(int i=0;i<=k;i++) {
    sum1 += div(n-1-i, k-i, n, k) * i;
  }

  t(n, k, sum1);
  return sum1;
}

int main()
{
  __;
  precompute();
  int n, m;
  cin >> n >> m;

  ld ans = 0;
  for(int i=0;i<m;i++) {
    ans += calK(n, i);
    t(ans);
  }

  cout << fixed << setprecision(12);
  cout << ans << endl;
  return 0;
}

0 -> 0
1 ->
  0*3 + 1/4 -> 0.25
2 -> 3C2 * 0 + 2C1 * 1 + 1C0 * 2 / 6 -> 0.67
3 -> 3C3 * 0 + 2C2 * 1 + 1C1 * 2 + 0C0 * 3/ 4C3 -> 1.5