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

const int N = 3e5+10;
vector<vector<int> > adj(N);
vector<int> distanc(N);

int bfs(int n)
{
  queue<int> q;
  q.push(0);
  q.push(-1);
  vector<int> vis(n);
  vis[0] = 1;
  int dist = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u+1) distanc[u] = dist;
    // if(u == n-1) return dist;
    if(u == -1)
    {
      dist++;
      if(!q.empty()) {q.push(-1); continue;}
      else break;
    }
    for(auto v : adj[u])
    {
      if(!vis[v])
      {
        q.push(v);
        vis[v] = 1;
      }
    }
  }
  return -1;
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  vector<int> nextSmallest(n,-1), nextGreatest(n,-1);
  // Smallest
  stack<pair<int,int> > small;
  for(int i=0;i<n;i++)
  {
    while(!small.empty() && small.top().fi >= v[i])
    {
      nextSmallest[small.top().se] = i;
      small.pop();
    }
    small.push(mp(v[i],i));
  }

  // Greatest
  stack<pair<int,int > > great;
  for(int i=0;i<n;i++)
  {
    while(!great.empty() && great.top().fi <= v[i])
    {
      nextGreatest[great.top().se] = i;
      great.pop();
    }
    great.push(mp(v[i],i));
  }

  for(int i=0;i<n;i++)
  {
    if(i != n-1) adj[i].pu(i+1);
    if(nextSmallest[i]+1) adj[i].pu(nextSmallest[i]);
    if(nextGreatest[i]+1) adj[i].pu(nextGreatest[i]);
  }

  // t(nextSmallest,nextGreatest);
  bfs(n);
  // cout << bfs(n) << endl;
  cout << distanc[n-1] << endl;
  for(int i=0;i<n;i++) cout << distanc[i] << " "; cout << endl;
  return 0;
}
