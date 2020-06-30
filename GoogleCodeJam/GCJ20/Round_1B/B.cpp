#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define EPS 1e-6
// #define ll long long int
#define int long long int
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

int cnt = 0;
int query(int x,int y)
{
  cnt++;
  t(cnt);
  cout << x << " " << y << endl;
  string s;
  cin >> s;
  if(s == "WRONG") exit(1);
  else if(s == "HIT") return 1;
  else if(s == "MISS") return 0;
  else return 2;
}

int bsearch1(int x)
{
  int beg_y = 1e9-100, end_y = 1e9,ans = 1e9-100;
  while(beg_y <= end_y)
  {
    int mid = (beg_y +end_y) >> 1;
    t(beg_y,end_y,mid,x);
    int a = query(x,mid);
    if(a == 0)
    {
      end_y = mid-1;
    }
    else
    {
      ans = mid;
      beg_y = mid+1;
    }
  }
  return ans;
}

void solve()
{
  int beg_x = -50, end_x = 50,max_x = 0,max_y = 0;
  while(beg_x <= end_x)
  {
    int mid_x = (beg_x + end_x) >> 1;
    int a = bsearch1(mid_x-1);
    int b = bsearch1(mid_x);
    int c = bsearch1(mid_x+1);
    t(a,b,c);

    if(c > b)
    {
      mid_x = beg_x+1;
    }
    else if(a > b)
    {
      end_x = mid_x-1;
    }
    else
    {
      max_y = b;
      max_x = mid_x;
    }
  }
  query(max_x, max_y);
}

int32_t main()
{
  __;
  int t;
  cin >> t;
  int a,b;
  cin >> a >> b;
  for(int h=1;h<=t;h++)
  {
    // cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}
