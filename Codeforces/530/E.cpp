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

int getCount(vector<string> &v, string &s,vector<string> &w)
{
  int n = v.size(), m = v[0].size();
  int cnt = 0;

  for(int j=0;j<m;j++)
  {
    int cnt1 = 0, cnt2 = 0;
    string s1, s2;
    int offset = (j&1)*2;

    for(int i=0;i<n;i++)
    {
      if(s[(i%2 == 1) + offset] == v[i][j]) cnt1++;
      s1 += s[(i%2 == 1) + offset];
    }
    for(int i=0;i<n;i++)
    {
      if(s[(i%2 != 1) + offset] == v[i][j]) cnt2++;
      s2 += s[(i%2 != 1) + offset];
    }

    if(cnt1 > cnt2) for(int i=0;i<n;i++) w[i] += s1[i];
    else for(int i=0;i<n;i++) w[i] += s2[i];

    cnt += max(cnt1,cnt2);
  }

  return cnt;
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;

  vector<string> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  vector<string> trial = {"AGTC" , "ACTG", "ATGC", "CGAT", "CTAG", "GTAC"};

  vector<string> ans,w(n);

  int max1 = -1;
  for(auto s : trial)
  {
    vector<string> w(n);
    int tempAns = getCount(v,s,w);
    if(tempAns > max1)
    {
      max1 = tempAns;
      ans= w;
    }
  }

  int max2 = -1;
  vector<string> vt(m);
  for(int j=0;j<m;j++)
  {
    for(int i=0;i<n;i++) vt[j] += v[i][j];
  }

  vector<string> anst;
  for(auto s : trial)
  {
    vector<string >w(m);
    int tempAns = getCount(vt,s,w);
    if(tempAns > max2)
    {
      max2 = tempAns;
      anst = w;
    }
  }

  if(max1 > max2)
  {
    for(auto it : ans)
    {
      for(auto it2 : it) cout << it2;
      cout << endl;
    }
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++) cout << anst[j][i];
      cout << endl;
    }
  }
  // cout << max1 << endl;
  return 0;
}
