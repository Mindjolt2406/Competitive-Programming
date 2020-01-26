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

const int N = 31;
int pref[N][N] = {0};
map<vector<int>,int> dp;

int get_sum(int a,int b, int c, int d)
{
  int sum1 = 0;
  if(a>0 && b>0) sum1 += pref[a-1][b-1];
  if(a>0) sum1 -= pref[a-1][b];
  if(b>0) sum1 -= pref[a][b-1];

  return pref[c][d] + sum1;
}

int recur(int a,int b,int c,int d,vector<vector<int> > &mat)
{
  vector<int> v = {a,b,c,d};

  t(v);
  if(dp.count(v)) return dp[v];

  set<int> s;
  if(mp(a,b) == mp(c,d)) return 0;

  for(int i=a;i<=c;i++)
  {
    if(get_sum(a,b,i,d)) s.insert(recur(a,b,i,d,mat));
  }

  for(int i=b;i<=d;i++)
  {
    if(get_sum(a,b,c,i)) s.insert(recur(a,b,c,i,mat));
  }

  for(int i=0;i<=100;i++)
  {
    if(!s.count(i)) 
    {
      dp[v] = i;
      return i;
    }
  }
  return 0;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    vector<vector<int> > mat(N,vector<int> (N));

    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin >> mat[i][j];
        if(mat[i][j] == 2 || mat[i][j] == 3 || mat[i][j] == 5 || mat[i][j] == 7) mat[i][j] = 0;
        else mat[i][j] = 1;
      }
    }

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        int sum1 = 0;
        if(i>0 && j>0) sum1 -= pref[i-1][j-1];
        if(i>0) sum1 += pref[i-1][j];
        if(j>0) sum1 += pref[i][j-1];
        pref[i][j] = sum1 + mat[i][j];
      }
    }


    int x = recur(0,0,n-1,n-1,mat);

    _;
    if(x) cout << "First" << endl;
    else cout << "Second" << endl;

    for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++) pref[i][j] = 0;
    }
    dp.clear();
  }
  return 0;
}
