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


void three(vector<vector<int> > &v, vector<vector<pair<int,int> > > &ans)
{
  vector<pair<int,int> > set,unset;
  for(int i=0;i<2;i++) 
  {
    for(int j=0;j<2;j++) 
    {
      if(v[i][j]) set.pu(mp(i,j));
      else unset.pu(mp(i,j));
    }
  }

  if(set.size() == 3)
  {
    vector<pair<int,int> > tempAns;
    for(auto p : set)
    {
      tempAns.pu(p);
      v[p.fi][p.se] ^= 1;
    }
    ans.pu(tempAns);
  }

  cout << ans.size() << endl;
  for(auto tempAns : ans)
  {
    for(auto p : tempAns)
    {
      cout << p.fi + 1 << " " << p.se + 1 << " ";
    }
    cout << endl;
  }

  bool flag = false;
  for(int i=0;i<v.size();i++) for(int j=0;j<v[0].size();j++) flag |= v[i][j];
  // t(flag);
}

void two(vector<vector<int> > &v, vector<vector<pair<int,int> > > &ans)
{
  vector<pair<int,int> > set,unset;
  for(int i=0;i<2;i++) 
  {
    for(int j=0;j<2;j++) 
    {
      if(v[i][j]) set.pu(mp(i,j));
      else unset.pu(mp(i,j));
    }
  }

  if(set.size() == 2)
  {
    vector<pair<int,int> > tempAns;
    tempAns.pu(unset[0]); v[unset[0].fi][unset[0].se] ^= 1;
    tempAns.pu(unset[1]); v[unset[1].fi][unset[1].se] ^= 1;
    tempAns.pu(set[0]); v[set[0].fi][set[0].se] ^= 1;
    ans.pu(tempAns);
  }
  three(v,ans);
}

void one(vector<vector<int> > &v, vector<vector<pair<int,int> > > &ans)
{

  int cnt = 0;
  for(int i=0;i<2;i++) for(int j=0;j<2;j++) cnt += v[i][j];

  if(cnt == 1)
  {
    vector<pair<int,int> > tempAns;
    if(v[0][0] || v[0][1])
    {
      tempAns.pu(mp(1,0)); v[1][0] ^= 1;
      tempAns.pu(mp(1,1)); v[1][1] ^= 1;
      if(v[0][0]) {tempAns.pu(mp(0,0)); v[0][0] ^= 1;}
      else {tempAns.pu(mp(0,1)); v[0][1] ^= 1;}
    }
    else
    {
      tempAns.pu(mp(0,0)); v[0][0] ^= 1;
      tempAns.pu(mp(0,1)); v[0][1] ^= 1;
      if(v[1][0]) {tempAns.pu(mp(1,0)); v[1][0] ^= 1;}
      else {tempAns.pu(mp(1,1)); v[1][1] ^= 1;}
    }
    ans.pu(tempAns);
  }
  two(v,ans);
}

void four(vector<vector<int> > &v, vector<vector<pair<int,int> > > &ans)
{
  int cnt = 0;
  for(int i=0;i<2;i++) for(int j=0;j<2;j++) cnt += v[i][j];

  if(cnt == 4) 
  {
    vector<pair<int,int> > tempAns;
    tempAns.pu(mp(0,0)); v[0][0] ^= 1;
    tempAns.pu(mp(1,0)); v[1][0] ^= 1;
    tempAns.pu(mp(1,1)); v[1][1] ^= 1;
    ans.pu(tempAns);
  }
  one(v,ans);
}

void solve()
{
  int n,m;
  cin >> n >> m;
  vector<vector<int> > v(n, vector<int>(m));
  for(int i=0;i<n;i++) 
  {
    string s;
    cin >> s;
    for(int j=0;j<s.size();j++) v[i][j] = (s[j] == '1');
  }

  vector<vector<pair<int,int> > > ans;
  for(int i=n-1;i>1;i--)
  {
    for(int j=m-1;j>0;j--)
    {
      if(v[i][j])
      {
        vector<pair<int,int> > tempAns;
        tempAns.pu(mp(i,j));
        tempAns.pu(mp(i-1,j));
        tempAns.pu(mp(i-1,j-1));
        v[i][j] ^= 1; v[i-1][j] ^= 1; v[i-1][j-1] ^= 1;
        ans.pu(tempAns);
      }
    }
    if(v[i][0])
    {
      vector<pair<int,int> > tempAns;
      tempAns.pu(mp(i,0));   v[i][0] ^= 1;
      tempAns.pu(mp(i-1,0)); v[i-1][0] ^= 1;
      tempAns.pu(mp(i-1,1)); v[i-1][1] ^= 1; 
      ans.pu(tempAns);
    }
  }

  for(int j=m-1;j>1;j--)
  {
    if(v[0][j] && v[1][j])
    {
      vector<pair<int,int> > tempAns;
      tempAns.pu(mp(0,j)); v[0][j] ^= 1;
      tempAns.pu(mp(1,j)); v[1][j] ^= 1;
      tempAns.pu(mp(0,j-1)); v[0][j-1] ^= 1;
      ans.pu(tempAns);
    }
    else if(v[0][j] ^ v[1][j])
    {
      vector<pair<int,int> > tempAns;
      tempAns.pu(mp(0,j-1)); v[0][j-1] ^= 1;
      tempAns.pu(mp(1,j-1)); v[1][j-1] ^= 1;
      if(v[0][j]) 
      {
        tempAns.pu(mp(0,j)); v[0][j] ^= 1;
      }
      else 
      {
        tempAns.pu(mp(1,j)); v[1][j] ^= 1;
      }
      ans.pu(tempAns);
    }
  }

  four(v,ans);
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    solve();
  }
  return 0;
}
