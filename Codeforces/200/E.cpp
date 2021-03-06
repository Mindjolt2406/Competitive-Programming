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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

bool check(ll k,vector<ll> &p, vector<ll> &q)
{
  int left = 0, right = 0;
  int n = p.size(), m = q.size();

  ll origPos = p[left];
  ll compulPos = q[right];

  while(right < m)
  {
    if(compulPos < origPos && abs(compulPos - origPos) <= k && q[right] < origPos) {right++; continue;}

    if(abs(origPos - q[right]) + abs(q[right]-compulPos) <= k || abs(origPos - compulPos) + abs(q[right] - compulPos) <= k)
    {
      right++;
    }
    else
    {
      left++;
      if(left >= n) return false;
      origPos = p[left];
      compulPos = q[right];
    }
  }

  return true;
}

void solve()
{
  int n,m;
  cin >> n >> m;
  vector<ll> p(n),q(m);

  for(int i=0;i<n;i++) cin >> p[i];

  for(int i=0;i<m;i++) cin >> q[i];

  sort(p.begin(),p.end());
  sort(q.begin(),q.end());

  // t(p,q);

  ll beg = 0, end = 1e18, ans = 1e18;
  while(beg <= end)
  {
    ll mid = (beg+end) >> 1;
    if(check(mid,p,q))
    {
      ans = mid;
      end = mid-1;
    }
    else beg = mid+1;
  }

  cout << ans << endl;
}

int main()
{
  __;
  solve();
  return 0;
}
