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

vector<int> adj[N] = {};
vector<int> adj_rev[N] = {};
vector<int> vis(N,-1),vis_rev(N,-1);

void bfs(int end)
{
  queue<int> q;
  q.push(end);
  vis_rev[end] = 0;
  q.push(-1);
  int dis = 0;

  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u == -1) 
    {
      dis++;
      if(q.empty()) break;
      q.push(-1);
      continue;
    }

    for(auto v : adj_rev[u])
    {
      if(vis_rev[v] == -1)
      {
        vis_rev[v] = dis+1;
        q.push(v);
      }
    }
  }
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin >> a >> b;
    adj[a].pu(b);
    adj_rev[b].pu(a);
  }
  int path_n;
  cin >> path_n;
  vector<int> path(path_n);
  for(int i=0;i<path_n;i++) cin >> path[i];

  int start = path[0];
  int end = path[path.size()-1];

  bfs(end);

  int max_cnt = 0, min_cnt = 0;

  for(int i=0;i<path.size()-1;i++)
  {
    int now = path[i];
    int dist = vis_rev[now];
    bool boo1 = false, boo2 = false;
    for(auto v : adj[now])
    {
      if(vis_rev[v] == dist-1)
      {
        if(v == path[i+1]) boo1 = true;
        else boo2 = true;
      }
    }

    if(boo1 && boo2)
    {
      max_cnt++;
    }
    else if(boo2)
    {
      max_cnt++;
      min_cnt++;
    }
  }

  cout << min_cnt << " " << max_cnt <<endl;
  return 0;
}
