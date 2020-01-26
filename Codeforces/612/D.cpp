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

const int N = 2010;
vector<int> adj[N] = {};
vector<int> val(N);
vector<int> lesser(N);
vector<int> sz(N);
bool pos = true;

void add(int u = 0, int p = -1, int k = 0)
{
  val[u] += k;
  for(auto v : adj[u])
  {
    if(v-p) add(v,u,k);
  }
}

void add(int u,int p, set<pair<int,int> > &s)
{ 
  s.insert(mp(val[u],u));
  for(auto v : adj[u])
  {
    if(v-p) add(v,u,s);
  }
}

void dfs(int u = 0,int p = -1)
{
  sz[u] = 1;

  vector<set<pair<int,int> > > v(adj[u].size());
  bool isLeaf = true;

  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]-p)
    {
      dfs(adj[u][i],u);
      sz[u] += sz[adj[u][i]];
      isLeaf = false;
    }
  }


  if(lesser[u] > sz[u]-1) 
  {
    pos = false;
  }

  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]-p)
    {
      add(adj[u][i],u,v[i]);
    }
  }
  
  if(isLeaf) 
  {
    val[u] = 1;
    return;
  }

  int prev = 0;
  bool done  = false;

  if(lesser[u] == 0)
  {
    val[u] = 0;
    add(u,p,1);
    return;
  }

  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i] - p)
    {
      if(lesser[u] > prev && lesser[u] <= prev+sz[adj[u][i]])
      {
        int k = lesser[u];
        k -= prev;
        int previous = -1;
        for(auto it : v[i])
        {
          pair<int,int> pa = it;
          int index = it.se;
          if(k) 
          {
            val[index]+= prev;
            previous = val[index];
            k--;
          }
          else
          {
            val[index] += prev+1;
          }
          if(!k && !done)
          {
            val[u] = previous + 1;
            done = true;
          } 
        }
        prev += sz[adj[u][i]]+1;
      }
      else 
      {
        add(adj[u][i],u,prev);
        prev += sz[adj[u][i]];
      }
    }
  }

  if(!done) val[u] = prev+1;

  // t(u,val);
}

int main()
{
  __;
  int n;
  cin >> n;
  int root = -1;
  for(int i=0;i<n;i++)
  {
    int par,val;
    cin >> par >> val;
    par--;
    if(par+1)
    {
      adj[i].pu(par);
      adj[par].pu(i);
    }
    else root = i;

    lesser[i] = val;
  }

  dfs(root);

  if(pos)
  {
    cout << "YES" << endl;
    for(int i=0;i<n;i++) cout << val[i] << " "; cout << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
