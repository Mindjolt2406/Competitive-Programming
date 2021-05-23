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

bool check(ll k,vector<int> &p, vector<int> &q)
{
  int left = 0, right = 0;
  int n = p.size(), m = q.size();

  int origPos = p[left];
  int compulPos = q[right];

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
  int n,m,k,s;
  cin >> n >> m >> k >> s;
  vector<int> p(n),q(m);

  for(int i=0;i<k;i++) cin >> p[i];
  ll ap,bp,cp,dp;
  cin >> ap >> bp >> cp >> dp;
  for(int i=k;i<n;i++) p[i] = ((ap*p[i-2]) % dp + (bp*p[i-1]) % dp + cp) % dp + 1;

  for(int i=0;i<k;i++) cin >> q[i];
  ll aq,bq,cq,dq;
  cin >> aq >> bq >> cq >> dq;
  for(int i=k;i<m;i++) q[i] = ((aq*q[i-2]) % dq + (bq*q[i-1]) % dq + cq) % dq + 1;

  sort(p.begin(),p.end());
  sort(q.begin(),q.end());

  // t(p,q);

  int beg = 0, end = 1e9, ans = 1e9;
  while(beg <= end)
  {
    int mid = (beg+end) >> 1;
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
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}

/*
1
6 6 6 0
10 30 100000 100000 100000 100000
0 0 0 100000000
16 28 29 31 32 32
0 0 0 100000000

1
2 2 2 0
10 20
0 0 0 100
13 16
0 0 0 100

2 2 2 0
10 20
0 0 0 100
17 18
0 0 0 100
3 3 3 0
20 60 30
0 0 0 100
25 10 35
0 0 0 100
8 7 3 0
83 16 59
13 5 41 414
8 62 92
62 48 21 404
35 45 8 0
512 931 3092 1477 167 2003 3204 1889
1927 1824 2165 3998
2999 3627 1603 387 1017 905 2215 295
1317 2142 1583 3999

1
6 6 6 0
10 40 100000 100000 100000 100000
0 0 0 100000000
16 32 39 41 42 43
0 0 0 100000000

*/