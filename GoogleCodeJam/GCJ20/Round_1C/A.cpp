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

void solve()
{
  int n,m;
  cin >> n >> m;
  string s;
  cin >> s;
  if(mp(n,m) == mp(0,0))
  {
    cout << 0 << endl;
    return;
  }
  pair<int,int> pos = mp(n,m);
  bool boo = false;
  int timer = -1;
  for(int i=0;i<s.size();i++)
  {
    if(s[i] == 'E') pos.fi++;
    else if(s[i] == 'W') pos.fi--;
    else if(s[i] == 'N') pos.se++;
    else pos.se--;

    if(abs(pos.fi) + abs(pos.se) > (i+1)) continue;
    else if(abs(pos.fi) + abs(pos.se) == (i+1)) 
    {
      // t(pos,i);
      boo = true;
      timer = i+1;
      break;
    }
    else 
    {
      // t(pos,i);
      boo = true;
      timer = i+1;
      break;
    }
  }
  if(boo)
  {
    cout << timer << endl;
  }
  else cout << "IMPOSSIBLE" << endl;
}

int main()
{
  __;
  int t;
  cin >>t;
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": "; 
    solve();
  }
  return 0;
}
