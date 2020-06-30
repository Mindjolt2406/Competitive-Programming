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

const int N = 3e5+10;
vector<int> adj(N);
vector<int> v(N);
vector<int> depth(N);

int cnt = 1;
int dep_idx = -1;
int vert = -1;
int max_dep = 0;

void dfs(int u = 0,int p = -1, int allow = v[1],int dep = 0)
{
  adj[u] = p;
  depth[u] = dep;
  // t(u,p,allow,dep,dep_idx);
  if(max_dep == dep) return;

  for(int i=0;i<allow;i++)
  {
    if(i == 0) dfs(cnt++,u,v[dep+2],dep+1);
    else 
    {
      if(dep == dep_idx-1 && vert == -1) 
      {
        vert = cnt;
        // t(vert);
        dfs(vert,u,0,dep+1);
        cnt++;
      }
      else dfs(cnt++,u,0,dep+1);
    }
  }
}

int main()
{
  __;
  int n;
  cin >> n;
  max_dep = n;
  int sum1 = 0;
  for(int i=0;i<=n;i++)
  {
    cin >> v[i];
    sum1 += v[i];
  }

  bool boo = false;
  for(int i=0;i<n;i++)
  {
    if(v[i] != 1 && v[i+1] != 1) 
    {
      boo = true;
      dep_idx = i;
      break;
    }
  }

  if(boo)
  {
    cout << "ambiguous" << endl;
    dfs();
    for(int i=0;i<sum1;i++) cout << adj[i]+1 << " ";
    cout << endl;
    bool boo = false;
    for(int i=0;i<sum1;i++)
    {
      if(depth[i] == dep_idx+1 && !boo)
      {
        boo = true;
        cout << vert+1 << " ";
      }
      else cout << adj[i]+1 << " ";
    }
    cout << endl;
  }
  else cout << "perfect" << endl;

  return 0;
}
