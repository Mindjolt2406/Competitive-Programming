/*
Rathin Bhargava
IIIT Bangalore

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
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

const int N = 4e5+10;
map<pair<int,int> , vector<pair<int,int> > > adj;
vector<set<pair<int,int> > >hor(N), ver(N);
map<pair<int,int> , bool > deleted;
map<pair<int,int> , int> degree;
set<pair<pair<int,int> , int > > leaf;
pair<int,int> root;

bool check_dir0(pair<int,int> p)
{
  int x = p.fi, y = p.se;
  if(hor[x].find(p) == hor[x].begin()) return true;
  return false;
}

bool check_dir1(pair<int,int> p)
{
  int x = p.fi, y = p.se;
  auto it = hor[x].find(p);
  it++;
  if(it == hor[x].end()) return true;
  return false;
}

bool check_dir2(pair<int,int> p)
{
  int x = p.fi, y = p.se;
  if(ver[y].find(p) == ver[y].begin()) return true;
  return false;
}

bool check_dir3(pair<int,int> p)
{
  int x = p.fi, y = p.se;
  auto it = ver[y].find(p);
  it++;
  if(it == ver[y].end()) return true;
  return false;
}


void get_parent(pair<int,int> p, pair<int,int> &parent, int &dir)
{
  if(degree[p] != 1) 
  {
    dir = -1;
    return;
  }
  for(auto it : adj[p])
  {
    if(!deleted[it])
    {
      parent = it;
      if(p.fi == parent.fi)
      {
        if(p.se > parent.se) dir = 1;
        else dir = 0;
      }
      else
      {
        if(p.fi > parent.fi) dir = 3;
        else dir = 2;
      }
    }
  }
}

bool check_dir(pair<int,int> p)
{
  int dir;
  pair<int,int> parent;
  get_parent(p,parent,dir);

  if(dir == 0) return check_dir0(p);
  else if(dir == 1) return check_dir1(p);
  else if(dir == 2) return check_dir2(p);
  else if(dir == 3) return check_dir3(p);

  return true;
}

void add_neighbours()
{
  int dx[4] = {-1,1,0,0};
  int dy[4] = {0,0,1,-1};

  for(auto it : adj)
  {
    int x = it.fi.fi, y = it.fi.se;
    for(int k=0;k<4;k++)
    {
      int a = x + dx[k], b = y + dy[k];
      if(adj.count(mp(a,b)))
      {
        adj[mp(x,y)].pu(mp(a,b));
      }
    }
    degree[it.fi] = adj[it.fi].size();
  }
}

void update_leaf(pair<int,int> p)
{
  if(p==root) return;
  if(degree[p] == 1)
  {
    pair<int,int> parent;
    int dir;
    get_parent(p,parent,dir);
    if(check_dir(p)) leaf.insert(mp(p,dir));
  }
}

void add_leaves()
{
  for(auto it : adj)
  {
    update_leaf(it.fi);
  }
}

void print(pair<int,int> p, int dir)
{
  if(dir <= 1)
  {
    if(dir == 0)
    {
      cout << "> " << p.fi << endl;
    }
    else 
    {
      cout << "< " << p.fi << endl;
    }
  }
  else
  {
    if(dir == 2)
    {
      cout << "^ " << p.se << endl;
    }
    else
    {
      cout << "v " << p.se << endl;
    }
  }
}

int main()
{
  __;
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<k;i++)
  {
    int a,b;
    cin >> a >> b;
    a--; b--;
    if(i==0) root = mp(a,b);
    adj[mp(a,b)] = {};
    hor[a].insert(mp(a,b));
    ver[b].insert(mp(a,b));
  }

  add_neighbours();
  for(auto it : adj)
  {
    pair<int,int> p = it.fi;
    pair<int,int> par;
    int dir;
    get_parent(p,par,dir);
    t(p,par,dir,degree[p]);
  }
  add_leaves();
  t(leaf.size());

  bool flag = true;
  vector<pair<pair<int,int> , int> > ans;

  for(int i=0;i<k-1;i++)
  {
    if(leaf.size() == 0) 
    {
      t(i);
      cout << "impossible" << endl;
      flag = false;
      break;
    }

    auto it = *leaf.begin();
    leaf.erase(it);
    pair<int,int> p = it.fi;
    int dir = it.se;

    // Update the parent
    pair<int,int> parent;
    int temp;
    get_parent(p,parent,temp);
    degree[parent]--;
    update_leaf(parent);
    
    pair<int,int> horiz_p = *hor[p.fi].begin();
    pair<int,int> horiz_p2 = *hor[p.fi].rbegin();
    pair<int,int> vert_p = *ver[p.se].begin();
    pair<int,int> vert_p2 = *ver[p.se].rbegin();

    hor[p.fi].erase(p);
    ver[p.se].erase(p);

    if(horiz_p == p)
    {
      if(!hor[p.fi].empty())
      {
        pair<int,int> temp = *hor[p.fi].begin(); 
        update_leaf(temp);
      }
    }
    if(horiz_p2 == p)
    {
      if(!hor[p.fi].empty())
      {
        pair<int,int> temp = *hor[p.fi].rbegin();
        update_leaf(temp);
      }
    }
    if(vert_p == p)
    {
      if(!ver[p.se].empty())
      {
        pair<int,int> temp = *ver[p.se].begin();
        update_leaf(temp);
      }
    }

    if(vert_p2 == p)
    {
      if(!ver[p.se].empty())
      {
        pair<int,int> temp = *ver[p.se].rbegin();
        update_leaf(temp);
      }
    }

    ans.pu(mp(p,dir));
  }

  t(ans);
  if(flag)
  {
    cout << "possible" << endl;
    for(int i=0;i<ans.size();i++) print(ans[i].fi, ans[i].se);
  }
  return 0;
}

