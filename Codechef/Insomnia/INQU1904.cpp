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

const int N = 1e5+10;
vector<int> adj[N] = {};
int dp[N][3] = {0};
int val[N] = {0};
int ans[N] = {0};

void dfs(int u = 0,int p = -1)
{
  bool isLeaf = true;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      isLeaf = false;
      dfs(v,u);
    }
  }

  if(isLeaf)
  {
    dp[u][0] = max(val[u],0);
    dp[u][1] = 0;
    dp[u][2] = 0;
    return;
  }

  // dp[i][0] = max(dp[i-1][0]+a[i],a[i]);
  // dp[i][1] = max(dp[i-1][0],dp[i-1][1]); // a[i] = 0
  // dp[i][2] = max(dp[i-1][1]+a[i],dp[i-1][2]+a[i]);

  set<pair<int,int> > s1,s2,s3;

  for(auto v : adj[u])
  {
    s1.insert(mp(dp[v][0],v));
    s2.insert(mp(max(dp[v][1],dp[v][0]),v));
    s3.insert(mp(max(dp[v][2],dp[v][1]),v));
  }

  // if(u==2) t((*s1.rbegin()).fi,(*s1.rbegin()).se,u);

  // 0
  pair<int,int> p1 = *s1.rbegin();
  dp[u][0] += max(0,0+p1.fi);
  s1.erase(p1);
  if(!s1.empty())
  {
    pair<int,int> p2 = *s1.rbegin();
    dp[u][0] += max(0,0+p2.fi);
  }
  dp[u][0] += val[u];
  s1.insert(p1);


  // if(u==2) t((*s1.rbegin()).fi,(*s1.rbegin()).se,u);
  // 1 (1,1) and (1,0)
  p1 = *s2.rbegin();
  dp[u][1] = max(dp[u][1],p1.fi);
  pair<int,int> p2 = mp(0,0), p02 = mp(0,0);
  s2.erase(p1);
  pair<int,int> p0 = *s1.rbegin();
  s1.erase(p0);

  if(!s2.empty())
  {
    p2 = *s2.rbegin();
    // if(u==4) t(u,p1.fi,p2.fi);
    dp[u][1]  = max(p1.fi+p2.fi,dp[u][1]);
  }
  if(!s1.empty())
  {
    p02 = *s2.rbegin();
  }

  // if(u==4) t(u,dp[u][1]);
  if(p0.se != p1.se)
  {
    dp[u][1] = max(dp[u][1],p1.fi+p0.fi);
  }
  else
  {
    dp[u][1] = max(p02.fi+p1.fi,dp[u][1]);
    dp[u][1] = max(p0.fi+p2.fi,dp[u][1]);
  }
  s2.insert(p1);
  s1.insert(p0);

  // if(u==2) for(auto it : s1) t(it);
  // 2
  p1 = *s3.rbegin();
  p0 = *s1.rbegin();
  dp[u][2] = max(p1.fi+val[u],dp[u][2]);
  s3.erase(p1);
  p2 = mp(0,-1), p02 = mp(0,-1);
  s1.erase(p0);

  if(!s3.empty())
  {
    p2 = *s3.rbegin();
    // dp[u][2] = max(p2.fi+p1.fi+val[u],dp[u][2]);
  }
  if(!s1.empty())
  {
    p02 = *s1.rbegin();
  }

  // if(u==2) t(u,dp[u][2],p0,p1,p02,p2);
  if(p0.se != p1.se)
  {
    // if(u==2) t(p1.fi,p0.fi,val[u]);
    dp[u][2] = max(dp[u][2],p1.fi+p0.fi+val[u]);
  }
  else
  {
    dp[u][2] = max(p02.fi+p1.fi+val[u],dp[u][2]);
    dp[u][2] = max(p0.fi+p2.fi+val[u],dp[u][2]);
  }

  dp[u][2] = max(val[u],dp[u][2]);
  s3.insert(p1);
  s1.insert(p0);

  // t(u,dp[u][0],dp[u][1],dp[u][2]);
  ans[u] = max(ans[u],dp[u][1]);
  ans[u] = max(ans[u],dp[u][2]);
  ans[u] = max(ans[u],dp[u][0]);

  p1 = *s1.rbegin();
  p2 = *s2.rbegin();
  pair<int,int> p3 = *s3.rbegin();
  dp[u][0] = max(val[u],p1.fi+val[u]);
  dp[u][1] = p2.fi;
  dp[u][2] = max(val[u],p3.fi+val[u]);
}

int main()
{
  __;
  
  // dp[i] denotes the max sum in the subarray containing i
  // You get the answer by taking max over all i
  // dp[i][0] = Best sum in the subarray containing i such that we haven't used the 0 operation yet
  // dp[i][1] = Best sum " "  such that i is in the subarray which becomes 0
  // dp[i][2] = Best sum " "  such that the 0 operation is already used, i isn't a part of it


  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> val[i];
    for(int i=0;i<n-1;i++)
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      adj[a].pu(b);
      adj[b].pu(a);
    }

    dfs();
    int max1 = 0;
    for(int i=0;i<n;i++) 
    {
      max1 = max(max1,ans[i]);
    }

    cout << max1 << endl;

    // for(int i=0;i<n;i++) t(i,dp[i][0],dp[i][1],dp[i][2],ans[i]);

    memset(val,0,sizeof(val));
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++) adj[i].clear();
    for(int i=0;i<n;i++) dp[i][0] = dp[i][1] = dp[i][2] = 0;
  }

  return 0;
}

/*

1
11
5 -10 3 30 -20 8 100 20 100 20 20
1 2
2 7
1 3
3 5
3 6
5 9 5 10 5 11
1 4
4 8


*/
