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

const int N = 3e5;
vector<int> adj[N];
vector<int> ans_even(N),ans_odd(N);
vector<int> vis_even(N), vis_odd(N);

void bfs_even(vector<int> &v)
{
  queue<int> q;
  int n = v.size();
  for(int i=0;i<n;i++) 
  {
    if((v[i]&1)) 
    {
      // t(v[i]);
      q.push(i);
      vis_even[i] = 1;
    }
  }
  q.push(-1);
  int dist = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u == -1)
    {
      if(q.empty()) break;
      q.push(-1);
      dist++;
      continue;
    }

    // t(u,dist);
    ans_even[u] = dist;
    for(auto x : adj[u])
    {
      if(!vis_even[x])
      {
        vis_even[x] = 1;
        q.push(x);
      } 
    }
  }
}

void bfs_odd(vector<int> &v)
{
  queue<int> q;
  int n = v.size();
  for(int i=0;i<n;i++) 
  {
    if(!(v[i]&1)) 
    {
      q.push(i);
      vis_odd[i] = 1;
    }
  }
  q.push(-1);
  int dist = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u == -1)
    {
      if(q.empty()) break;
      q.push(-1);
      dist++;
      continue;
    }

    ans_odd[u] = dist;
    for(auto x : adj[u])
    {
      if(!vis_odd[x])
      {
        vis_odd[x] = 1;
        q.push(x);
      } 
    }
  }
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin >> v[i];

  for(int i=0;i<n;i++)
  {
    if(i-v[i] >= 0)
    {
      adj[i-v[i]].pu(i);
    }
    if(i+v[i]<n)
    {
      adj[i+v[i]].pu(i);
    }
  }

  // for(int i=0;i<n;i++) t(i,adj[i]);
  for(int i=0;i<n;i++) ans_even[i] = ans_odd[i] = -1;
  bfs_even(v);
  bfs_odd(v);

  // for(int i=0;i<n;i++) cout << ans_odd[i] << " "; cout << endl;
  // for(int i=0;i<n;i++) cout << ans_even[i] << " "; cout << endl;
  for(int i=0;i<n;i++)
  {
    if(v[i]&1) cout << ans_odd[i] << " ";
    else cout << ans_even[i] << " ";
  }
  cout << endl;
  return 0;
}

