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

const int N = 21;
vector<string> v(N);
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool check(int i,int j,int n,int m)
{
  if(i<0 || j<0 || i>=n || j>=m || v[i][j] == '#') return false;
  return true;
}

int bfs(pair<int,int> start,pair<int,int> end,int n,int m)
{
  queue<pair<int,int> > q;
  q.push(start);
  pair<int,int> null = mp(-1,-1);
  q.push(null);
  vector<vector<bool> > vis(21,vector<bool>(21));

  int dist = 0;
  while(!q.empty())
  {
    pair<int,int> u = q.front();
    if(u == end) break;
    q.pop();
    if(u == null)
    {
      if(q.empty()) break;
      dist++;
      q.push(null);
    }

    for(int k=0;k<4;k++)
    {
      int x = u.fi + dx[k];
      int y = u.se + dy[k];

      if(check(x,y,n,m) && !vis[x][y]) 
      {
        q.push(mp(x,y));
        vis[x][y] = true;
      }
    }    
  }

  return dist;
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
    cin >> v[i];
  }

  int max1 = 0;
  for(int a=0;a<n;a++)
  {
    for(int b=0;b<m;b++)
    {
      for(int c=0;c<n;c++)
      {
        for(int d=0;d<m;d++)
        {
          if(check(a,b,n,m) && check(c,d,n,m) && (mp(a,b) <= mp(c,d))) 
          {
            max1 = max(max1,bfs(mp(a,b),mp(c,d),n,m));
          } 
        }
      }
    }
  }

  cout << max1 << endl;
  return 0;
}
