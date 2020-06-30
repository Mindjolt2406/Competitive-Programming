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
template<int> ostream& operator<<(ostream& os,const int &a) {if(a == INF) os << "INF"; else os << a;  }
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

void solve()
{
  int n;
  cin >> n;
  vector<pair<pair<int,int>,int> > v(n);
  for(int i=0;i<n;i++) 
  {
    cin >> v[i].fi.se >> v[i].fi.fi;
    v[i].se = i;
  }

  sort(v.begin(),v.end());

  vector<vector<pair<int,int> > > dp(n+1,vector<pair<int,int> >(n+1,mp(INF,INF))); // (finish time of 0,finish time of 1)
  vector<vector<pair<int,int> > > back(n+1,vector<pair<int,int> >(n+1,mp(-1,-1))); // (index,fellow)

  dp[0][0] = mp(0,0);
  back[0][0] = mp(-1,-1);

  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=i;j++)
    {
      int x = j, y = i-j;
      if(x > 0)
      {
        if(dp[x-1][y].fi <= v[i-1].fi.se)
        {
          dp[x][y] = mp(v[i-1].fi.fi,dp[x-1][y].se);
          back[x][y] = mp(x-1,y);
        }
      }
      if(y>0)
      {
        if(dp[x][y-1].se <= v[i-1].fi.se)
        {
          int temp = max(dp[x][y].fi, dp[x][y].se);
          int temp2 = max(dp[x][y-1].fi,v[i-1].fi.fi);
          if(temp2 < temp)
          {
            dp[x][y] = mp(dp[x][y-1].fi,v[i-1].fi.fi);
            back[x][y] = mp(x,y-1);
          }
        }
      }
    }
  }

  pair<int,int> p;
  bool boo = false;

  for(int j=0;j<=n;j++)
  {
     if(back[j][n-j] != mp(-1,-1))
     {
       boo = true;
       p = mp(j,n-j);
     }
  }

  if(!boo)
  {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  vector<int> taken(n);

  while(p != mp(-1,-1))
  {
    int x = p.fi, y = p.se;
    // t(x+y,v[x+y]);
    // t(p,dp[x][y]);
    if(back[x][y] == mp(x-1,y))
    {
      taken[v[x+y-1].se] = 1;
      p = back[x][y];
    }
    else
    {
      taken[v[y+x-1].se] = 2;
      p = back[x][y];
    }
  }

  // t(dp);
  // t(back);
  // t(taken);
  for(int i=0;i<n;i++)
  {
    if(taken[i] == 1) cout << "C";
    else cout << "J";
  }

  cout << endl;
  return;
}

int main()
{
  __;
  int t;
  cin >> t; 
  for(int h=1;h<=t;h++)
  {
    cout << "Case #" << h << ": ";
    solve();
  }
  return 0;
}

/*
1
3
360 480
420 540
600 660

1
3
0 1440
1 3
2 4

*/