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
char dir[4] = {'U','D','L','R'};

bool check(int i,int j,int n)
{
  if(i < 0 || i >= n || j < 0 || j >= n) return false;
  return true;
}

int main()
{
  __;
  int n;
  cin >> n;
  vector<vector< pair<int,int> > > v(n,vector<pair<int,int> > (n));
  vector<vector<int> > vis(n,vector<int> (n));
  vector<vector<char> > ans(n,vector<char> (n));
  
  vector<pair<int,int> > w;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cin >> v[i][j].fi >> v[i][j].se;
      if(v[i][j] != mp(-1,-1))
      {
        v[i][j].fi--;
        v[i][j].se--;
      }

      if(mp(i,j) == v[i][j]) w.pu(mp(i,j));
    }
  }

  for(int i=0;i<w.size();i++)
  {
    pair<int,int> start = w[i];
    ans[start.fi][start.se] = 'X';
    vis[start.fi][start.se] = 1;
    queue < pair<int,int> > q;
    q.push(start);

    while(!q.empty())
    {
      pair<int,int> p = q.front();
      q.pop();
      for(int k=0;k<4;k++)
      {
        int i = p.fi, j = p.se;
        int a = i+dx[k], b = j+dy[k];
        if(check(a,b,n) && !vis[a][b] && start == v[a][b])
        {
          q.push(mp(a,b));
          vis[a][b] = true;
          ans[a][b] = dir[k];
        }
      }
    }
  }

  // t(v);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(v[i][j] != mp(-1,-1) && vis[i][j] == 0) 
      {
        // t(i,j);
        // _;
        cout << "INVALID" <<endl;
        return 0;
      }

      
      if(v[i][j] == mp(-1,-1) && !vis[i][j])
      {
        // t(i,j);
        bool boo = false;
        int index = -1;
        for(int k=0;k<4;k++)
        {
          int a = i+dx[k], b = j+dy[k];
          if(check(a,b,n) && v[a][b] == mp(-1,-1))
          {
            boo = true;
            index = k;
            break;
          }
        }

        if(!boo) 
        {
          // _;
          cout << "INVALID" << endl;
          return 0;
        }

        // t(i,j,index);
        index ^= 1;
        ans[i][j] = dir[index];
        // t(i,j,ans[i][j]);

        queue < pair<int,int> > q;
        pair<int,int> start = mp(i,j);
        vis[i][j] = true;
        q.push(start);

        // t(start);
        while(!q.empty())
        {
          pair<int,int> p = q.front();
          q.pop();
          // t(p);
          for(int k=0;k<4;k++)
          {
            int i = p.fi, j = p.se;
            int a = i+dx[k], b = j+dy[k];
            // if(check(a,b,n)) t(a,b,vis[a][b],v[a][b]);
            if(check(a,b,n) && !vis[a][b] && v[a][b] == mp(-1,-1))
            {
              // t(a,b);
              q.push(mp(a,b));
              vis[a][b] = true;
              ans[a][b] = dir[k];
            }
          }
        }
      }
    }
  }

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(!vis[i][j])
      {
        cout << "INVALID" << endl;
        return 0;
      }
    }
  }

  cout << "VALID" << endl;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
