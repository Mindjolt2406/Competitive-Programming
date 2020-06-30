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

int dx[8] = {-1,-2,-2,-1,1,2,2,1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

bool check(int i,int j,int n,int m)
{
  if(i<0 || j<0 || i>=n || j>=m) return false;
  return true;
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<int> > state(n,vector<int>(m,-1));
    vector<vector<bool> > vis(n,vector<bool>(m));

    for(int i=0;i<n;i++) cin >> v[i];

    pair<int,int> beg,end;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(v[i][j] == 'F') end = mp(i,j);
        if(v[i][j] == 'K') beg = mp(i,j);
      }
    }

    queue<pair<int,int> > q;
    q.push(beg);
    bool boo = false;
    while(!q.empty())
    {
      pair<int,int> p = q.front();
      q.pop();
      if(p == end) 
      {
        boo = true;
        break;
      }
      int i = p.fi, j = p.se;
      for(int k=0;k<8;k++)
      {
        int a = dx[k]+i, b = dy[k]+j;
        if(check(a,b,n,m) && !vis[a][b] && v[a][b] != 'X')
        {
          vis[a][b] = true;
          state[a][b] = k;
          q.push(mp(a,b));
        }
      }
    }

    if(!boo) 
    {
      cout << "Neigh" << endl;
      continue;
    }
    string ans = "";
    pair<int,int> p = end;
    while(p != beg)
    {
      int temp = state[p.fi][p.se];
      ans += ('A'+temp);
      p.fi -= dx[temp];
      p.se -= dy[temp];
    }

    reverse(ans.begin(),ans.end());
    // for(int i=0;i<ans.size();i++) 
    // {
    //   if(ans[i]+4 > 'H') ans[i] -= 4;
    //   else ans[i]+=4;
    // }
    cout << "Whinny" << endl;
    cout << ans << endl;
  }
  return 0;
}
