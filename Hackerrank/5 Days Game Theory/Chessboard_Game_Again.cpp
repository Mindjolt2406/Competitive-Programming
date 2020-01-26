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

bool check(int i,int j,int n)
{
  if(i<0 || j<0 || i>=n || j>=n) return false;
  return true;
}

int main()
{
  __;
  int mat[15][15] = {0};

  for(int k=0;k<=28;k++)
  {
    for(int i=0;i<=min(14,k);i++)
    {
      int j = k-i;
      if(!check(i,j,15)) continue;
      set<int> s;
      if(check(i-2,j+1,15)) s.insert(mat[i-2][j+1]);
      if(check(i-2,j-1,15)) s.insert(mat[i-2][j-1]);
      if(check(i+1,j-2,15)) s.insert(mat[i+1][j-2]);
      if(check(i-1,j-2,15)) s.insert(mat[i-1][j-2]);
      
      for(int h=0;h<=5;h++)
      {
        if(!s.count(h)) 
        {
          mat[i][j] = h;
          break;
        }
      }
    } 

  }

  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;

    int ans = 0;
    for(int i=0;i<n;i++)
    {
      int x,y;
      cin >> x >> y;
      x--; y--;

      ans ^= mat[x][y];
    }

    if(ans) cout << "First" << endl;
    else cout << "Second" << endl;
  }
  return 0;
}
