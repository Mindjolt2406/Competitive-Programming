/*
Rathin Bhargava
IIIT Bangalore

*/
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

vector< vector<int> > mat(105,vector<int>(105));


void make(int n)
{
  int k = n/2;
  mat[k+2][k+1] = mat[k+1][k+2] = 1;
  mat[k+1][k-1] = mat[k-1][k+1] = 1;
  mat[k][k+2] = mat[k+2][k] = 1;
  mat[k-1][k] = mat[k][k-1] = 1;

  int left = k-2, right = k+3;
  while(left > 0 && right <= n)
  {
    for(int i=left+1;i<right;i++) 
    {
      mat[left][i] = mat[i][left] = 1;
      mat[right][i] = mat[i][right] = 1;
    }
    left--; right++;
  }
}

int main()
{
  __;
  int n;
  cin >> n;

  if(n%2==1)
  {
    n/=2;
    n*=2;
    make(n);
    for(int i=1;i<=n;i++) mat[i][n+1] = mat[n+1][i] = 1;
  }
  else make(n);

  vector<pair<int,int> > ans;
  int cnt = 0;
  for(int i=1;i<=100;i++)
  {
    for(int j=1;j<i;j++)
    {
      if(mat[i][j]) ans.pu(mp(i,j));
    }
  }

  cout << ans.size() << endl;
  for(int i=0;i<ans.size();i++) cout << ans[i].fi << " " << ans[i].se << endl;

  return 0;
}

