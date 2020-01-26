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

const int N = 2e5+10;
set<int> adj[N] = {};

int main()
{
  __;
  int n,t,k;
  cin >> n >> t >> k;

  vector<int> v(t);
  for(int i=0;i<t;i++) cin >> v[i];

  int sum1 = v[t-1], sum2 = v[t-1];
  for(int i=0;i<t-1;i++) 
  {
    sum1 += max(0,v[i]-v[i+1]);
    sum2 += v[i];
  }
  sum2 -= (t-1);

  if(k<sum1 || k>sum2) {cout << -1 << endl; return 0;}

  // Generate the tree where k = sum2
  int idx = 1;
  int level = 0;
  vector<int> level_idx;
  level_idx.pu(idx);
  while(level<t)
  {
    for(int i=1;i<=v[level];i++) 
    {
      adj[idx].insert(idx+i);
    }
    idx = *adj[idx].rbegin();
    level++;
    level_idx.pu(idx);
  }

  // t(level_idx);
  // for(int i=1;i<=n;i++)
  // {
  //   for(auto it : adj[i]) cout << i << " " << it << endl;
  // }
  int cnt = sum2;
  level = 1;
  while(cnt>k)
  {
    int idx = level_idx[level];
    bool boo = false;
    for(int i=1;i<v[level-1] && adj[idx].size()>1;i++) // Iterating through the children
    {
      int temp = *adj[idx].begin();
      // t(idx,idx-i,temp,level);
      adj[idx-i].insert(temp);
      adj[idx].erase(temp);
      cnt--;
      if(cnt==k) {boo = true; break;}
    }
    if(boo) break;
    level++;
  }

  cout << n << endl;
  for(int i=1;i<=n;i++)
  {
    for(auto it : adj[i]) cout << i << " " << it << endl;
  }
  // t(sum1,sum2);
  return 0;
}

