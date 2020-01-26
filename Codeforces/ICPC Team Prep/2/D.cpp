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

pair<int,int> d[50][50][4] = {};

bool see(int i,int j,int n,int m)
{
  if(i<0 || j<0 || i==n || j==m) return false;
  return true;
}

int main()
{
  __;
  int n,k,m;
  cin >> n >> k;

  vector<vector<int> > v(n);
  // map<pair<int,int> , vector<pair<int,int> > > d;

  for(int i=0;i<n;i++)
  {
    string s;
    cin >> s;
    for(int j=0;j<s.size();j++) 
    {
      v[i].pu(s[j]-'0');
      d[i][j][0] = mp(-1,-1);
    }
    m = s.size();
  }

  vector<vector<bool> > check(n,vector<bool>(m,false));
  vector<vector<vector<pair<int,int> > > > w(n,vector<vector< pair<int,int> > >(m,vector<pair<int,int> >(4,mp(-1,-1)));

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j] == 0) continue;

      if(d[i][j][0] == mp(-1,-1))
      {
        // Go down
        int col = v[i][j];
        int index1 = i, index2 = j;
        for(int k=i;k<n;k++)
        {
          if(v[k][j] == col) index1 = k;
          else break;
        }

        for(int k=j;k<m;k++)
        {
          if(v[i][k] == col) index2 = k;
        }

        check[i][index2] = check[i][j] = check[index1][j] = check[index1][index2] = true;

        for(int k1 = i;k1<=index1;k1++)
        {
          for(int k2 = j;k2<=index2;k2++)
          {
            d[k1][k2][0] = mp(i,j);
            d[k1][k2][1] = mp(i,index2);
            d[k1][k2][2] = mp(index1,j);
            d[k1][k2][3] = mp(index1,index2);
          }
        }
      }
    }
  }

  int dx[4] = {1,-1,0,0};
  int dy[4] = {0,0,1,-1};

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(check[i][j])
      {
        for(int k=0;k<4;k++)
        { 
          int x = i+dx[k], y = j+dy[k];
          if(see(x,y,n,m))
          {
            if(v[i][j] == v[x][y]) continue;
            w[i][j].se = v[x][y];
            else w[i][j].fi = v[x][y];
          }
          else 
          {
            if(k<2) w[i][j].se = 0;
            else w[i][j].fi = 0;
          }
        }
      }
    }
  }

  pair<int,int> start = mp(0,0);
  pair<int,int> pos = mp(0,0);
  int ans = 0;

  while(k--)
  {
    t(start,pos);
    int a = start.fi, b = start.se;
    int x = pos.fi, y = pos.se;

    if(a == 0 && b == 0)
    {
      pair<int,int> p = d[x][y][1];
      t(p);
      int a1 = p.fi, a2 = p.se;
      // Verticals
      if(w[a1][a2].fi == 0) start = mp(a,(b+1)%2);
      else pos = mp(x,y+1);
    }
    else if(a == 0 && b == 1)
    {
      pair<int,int> p = d[x][y][3];      
      int a1 = p.fi, a2 = p.se;
      // Verticals
      if(w[a1][a2].fi == 0) start = mp((a+1)%4,(b+1)%2);
      else pos = mp(x,y+1);
    }
    else if(a == 1 && b == 0)
    {
      pair<int,int> p = d[x][y][3];
      int a1 = p.fi, a2 = p.se;
      if(w[a1][a2].se == 0) start = mp(a,(b+1)%2);
      else pos = mp(x+1,y);

    }
    else if(a == 1 && b == 1)
    {
      pair<int,int> p = d[x][y][2];
      int a1 = p.fi, a2 = p.se;
      if(w[a1][a2].se == 0) start = mp((a+1)%4,(b+1)%2);
      else pos = mp(x+1,y+1);

    }
    else if(a == 2 && b == 0)
    {     
      pair<int,int> p = d[x][y][2];
      int a1 = p.fi, a2 = p.se;
      // Verticals
      if(w[a1][a2].fi == 0) start = mp(a,(b+1)%2);
      else pos = mp(x,y-1);

    }
    else if(a == 2 && b == 1)
    {
      pair<int,int> p = d[x][y][0];
      int a1 = p.fi, a2 = p.se;
      // Verticals
      if(w[a1][a2].fi == 0) start = mp((a+1)%4,(b+1)%2);
      else pos = mp(x,y-1);

    }
    else if(a == 3 && b == 0)
    {
      pair<int,int> p = d[x][y][0];
      int a1 = p.fi, a2 = p.se;
      if(w[a1][a2].se == 0) start = mp(a,(b+1)%2);
      else pos = mp(x-1,y);

    }
    else if(a == 3 && b == 1)
    {
      pair<int,int> p = d[x][y][1];
      int a1 = p.fi, a2 = p.se;
      if(w[a1][a2].se == 0) start = mp((x+1)%4,(y+1)%2);
      else pos = mp(x-1,y);
    }

    ans = v[pos.fi][pos.se];
  }

  cout << ans << endl;

  return 0;
}

