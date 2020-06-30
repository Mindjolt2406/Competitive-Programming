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

// void recur(int n,int depth, bool reverse)
// {
//   t(n,depth);
//   if(n == 0) return;
//   if(n >= (1 << (depth-1)))
//   {
//     if(!reverse) for(int i=1;i<=depth;i++) cout << depth << " " << i << endl;
//     else for(int i=depth;i>=1;i--) cout << depth << " " << i << endl;

//     n -= (1 << (depth-1));
//     recur(n,depth-1,reverse^1);
//   }
//   else
//   {
//     n--;
//     if(reverse) cout << depth << " " << depth << endl;
//     else cout << depth << " " << 1 << endl;
//     recur(n,depth-1,reverse);
//   }
// }

void solve()
{
  int n;
  cin >> n;
  int m = max(n-40,0);
  int k = m;
  bool reverse = false;
  int depth = 1;
  while(m)
  {
    if(m&1)
    {
      if(reverse) for(int i=depth;i>0;i--) cout << depth << " " << i << endl;
      else for(int i=1;i<=depth;i++) cout << depth << " " << i << endl;
      reverse ^= 1;
    }
    else 
    {
      cout << depth << " " << (reverse ? depth : 1) << endl;
      n--;
    }
    m >>= 1;
    depth++;
  }
  for(int i=0;i<n-k;i++)
  {
    cout << depth << " " << (reverse ? depth : 1) << endl;
    depth++;
  }
}

int main()
{
  __;
  int t;
  cin >> t;
  for(int h=1;h<=t;h++)
  {
    // cout << "Case #" << h << ": " << endl;
    solve();
  }
  return 0;
}