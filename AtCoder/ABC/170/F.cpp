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

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool check(int x,int y,int n,int m)
{
  if(x < 0 || y < 0 || x >= n || y >= m) return false;
  return true;
}

void bfs(vector<string> &mat,pair<int,int> src,pair<int,int> dest,int k)
{
  int n = mat.size(), m = mat[0].size();
  queue<pair<int,int> > q;
  vector<vector<bool> > vis(n,vector<bool>(m));
  q.push(src);
  vis[src.fi][src.se] = true;
  pair<int,int> NUL = mp(-1,-1);
  q.push(NUL);
  int ans = 0;
  while(!q.empty())
  {
    pair<int,int> p = q.front();
    t(p);
    if(p == mp(0,3)) t(ans);
    q.pop();
    if(p == dest) break;
    if(p == NUL)
    {
      if(q.empty()) break;
      else 
      {
        ans++;
        q.push(NUL);
      }
    }

    int x = p.fi, y = p.se;
    for(int i=0;i<4;i++)
    {
      for(int j=1;j<=k;j++)
      {
        int a = x+dx[i]*j, b = y+dy[i]*j;
        if(p == mp(0,3)) 
        {
          t("here");
          t(a,b,p,check(a,b,n,m));
          if(check(a,b,n,m)) t(vis[a][b],mat[a][b]);
        }
        if(!check(a,b,n,m) || vis[a][b] || mat[a][b] == '@') break;
        else 
        {
          vis[a][b] = true;
          if(mp(a,b) == mp(1,3)) t(a,b,p,vis[a][b],ans,"here");
          q.push(mp(a,b));
        }
      }
    }
  }
  if(vis[dest.fi][dest.se]) cout << ans << endl;
  else cout << -1 << endl;
}

int main()
{
  __;
  int n,m,k;
  cin >> n >> m >> k;
  pair<int,int> src,dest;
  cin >> src.fi >> src.se >> dest.fi >> dest.se;
  src.fi--;src.se--;dest.fi--;dest.se--;
  vector<string> mat(n);
  for(int i=0;i<n;i++) cin >> mat[i];
  bfs(mat,src,dest,k);
  return 0;
}
