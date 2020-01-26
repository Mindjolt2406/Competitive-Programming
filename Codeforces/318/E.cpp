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
vector<int> path(N);
vector<int> good(N);
vector<int> par(N);
int root = -1;

void dfs(int u = 0,int p = -1)
{
  par[u] = p;
  bool isLeaf = true;
  int paths = 0;
  // t(u);
  for(auto v : adj[u])
  {
    if(v-p)
    {
      isLeaf = false;
      dfs(v,u);
      if(adj[u].size() == 2 && path[v] && u!=root) 
      {
        path[u] = 1;
        good[u] = 1;
        paths++;
      }
      else if(path[v]) 
      {
        paths++;
      }
    }
  }

  if(isLeaf) 
  {
    path[u] = 1;
    good[u] = 1;
  }
  // if(root == u) t(paths,adj[u].size());
  if(paths <= 2 && adj[u].size() == paths+1 ) // This node is not the root
  {
    good[u] = 1;
  }
  // else if(root == u && paths <= 2 && adj[u].size() <= paths) // Not needed though
  // {
  //   good[u] = 1;
  // }
}

int main()
{
  __;
  int n;
  cin >> n;

  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  for(int i=0;i<n;i++) 
  {
    if(adj[i].size() >= 3) 
    {
      root = i;
      break;
    }
  }

  if(root == -1) // Every node has degree 2 or 1
  {
    cout << "Yes" << endl;
    return 0;
  }

  dfs(root);
  // t(root);
  // for(int i=0;i<n;i++) cout << good[i] << " "; cout << endl;
  // t(good[21],good[28],good[30],good[0]);

  bool boo = true;
  for(int i=0;i<n;i++)
  {
    if(good[i]) continue;
    int notGood = 0;
    for(auto v : adj[i])
    {
      if(!good[v]) 
      {
        notGood++; 
        // t(i,v,notGood);
      }
    }
    if(notGood > 2) boo = false;
  }

  if(boo) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

/*
29
1 2
1 3
1 4
1 5
2 6
2 7
2 8
5 9
5 10
5 11
1 12
6 13
6 14
7 15
7 16
1 17
8 18
8 19 
8 20
9 21
9 22
1 23
10 24
10 25
1 26
11 27
11 28
11 29

25
5 19
16 23
23 19
22 23
12 22
22 1
14 10
20 15
11 16
19 9
7 6
25 21
1 13
15 1
21 18
23 4
21 22
6 2
4 17
24 19
9 3
21 6
22 10
6 8


50
37 12
28 34
31 24
33 0
10 25
25 13
30 34
9 39
33 1
27 20
24 34
16 23
48 47
36 4
39 21
43 26
21 19
36 28
5 25
37 10
20 45
6 46
44 11
41 38
14 40
4 21
35 9
32 3
19 2
27 1
42 38
13 41
26 49
35 23
31 48
12 17
7 49
14 18
29 44
24 40
5 43
22 6
32 8
5 0
6 30
0 34
8 26
29 2
3 15

*/