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
vector<pair<int,int> > adj[N],adj2[N];

int ans[N] = {0};
vector<bool> checker(N);
int vis[N] = {0};

// Functor to compare by the Mth element
template<int M, template<typename> class F = std::less>
struct TupleCompare
{
    template<typename T>
    bool operator()(T const &t1, T const &t2)
    {
        return F<typename tuple_element<M, T>::type>()(std::get<M>(t1), std::get<M>(t2));
    }
};

void dfs(int u = 0, int p = -1,int val = -INF)
{
  int cnt = 0;
  ans[u] = val;
  vis[u] = 1;
  for(auto v : adj2[u])
  {
    if(!vis[v.fi]) dfs(v.fi,u,max(val,v.se));
  }
}

bool check(int i,int j,int n,int m)
{
  if(i<0 || j<0 || i>=n || j>=m) return false;
  return true;
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  vector<vector<int> > v(n,vector<int>(m));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++) cin >> v[i][j];
  }
  int dx[8] = {-1,-1,-1,0,0,1,1,1};
  int dy[8] = {-1,0,1,-1,1,-1,0,1};

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      for(int k=0;k<9;k++)
      {
        int a = dx[k]+i, b = dy[k]+j;
        if(check(a,b,n,m))
        {
          int x = m*i + j + 1, y = m*a+b + 1;
          // t(i,j,a,b,x,y);
          // t(v[i][j],v[a][b],k);
          if(v[a][b] >=0 || v[i][j] >= 0) {continue;}
          // _;
          // t(i,j,a,b,x,y);
          // t(v[i][j],v[a][b],k);
          adj[x].pu(mp(y,min(max(v[i][j],v[a][b]),0)));
          adj[y].pu(mp(x,min(max(v[i][j],v[a][b]),0)));
        }
      }
    }
  }

  vector<tuple<int,int,int> > w;
  for(int i=0;i<N;i++) 
  {
    for(auto j : adj[i])
    {
      w.pu(mt(i,j.fi,j.se));
    }
  }

  sort(w.begin(),w.end());

  n = n*m;

  vector<int> colour(n+1), number(n+1);
  vector<list<int> > refer(n+1);
  list <int> :: iterator it;
  int countcolour = n;

  for(int i=0;i<n;i++)
  {
    colour[i] = i;
    number[i] = 1;
    refer[i].pu(i);
  }
  int count = 0;
  for(int i=0;i<w.size()&& countcolour;i++)
  {
    int a = get<0>(w[i]), b = get<1>(w[i]), c = get<2>(w[i]);
    int d = colour[a],e = colour[b];
    if(d==e) continue;
    else if(number[d]>number[e])
    {
      // for(int j=0;j<number[e];j++) colour[refer[e][j]] = d;
      for(it = refer[e].begin();it!=refer[e].end();it++) colour[*it] = d;
      number[d]+=number[e];
      number[e] = 0;
      count+=c;
      adj2[a].pu(mp(b,c));
      adj2[b].pu(mp(a,c));
      countcolour--;
      // cout<<c<<endl;
      refer[d].splice(refer[d].end(),refer[e]);
    }
    else
    {
      // for(int j=0;j<number[d];j++) colour[refer[d][j]] = e;
      for(it = refer[d].begin();it!=refer[d].end();it++) colour[*it] = e;
      number[e]+=number[d];
      number[d] = 0;
      count+=c;
      adj2[a].pu(mp(b,c));
      adj2[b].pu(mp(a,c));
      countcolour--;
      // cout<<c<<endl;
      refer[e].splice(refer[e].end(), refer[d]);
    }
  }

  int a,b;
  cin >> a >> b;
  a--;b--;
  int root = a*m+b+1;
  for(int i=1;i<=9;i++)
  {
    cout << i << ": ";
    for(auto v : adj[i]) cout << v << " "; cout << endl;
  }
  
  dfs(root,-1);

  int sum1 = 0;
  for(int i=0;i<n;i++) sum1 += ans[i];
  for(int i=0;i<n;i++) cout << ans[i] << " "; cout << endl;

  cout << abs(sum1) << endl;
  return 0;
}

/*
3 3
-5 2 -5
-1 -2 -1
5 4 -5
2 2

*/