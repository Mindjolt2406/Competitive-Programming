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

const int N = 100100;
int p[N], sz[N];

void create(int x){
	p[x] = x;
	sz[x] = 1;
	return;
}

int find(int x){
  if(x == p[x]) return x;
  return p[x] = find(p[x]);
}

void merge(int x, int y){
	x = find(x), y = find(y);
	if(x == y) return;
  if(sz[x] < sz[y]) swap(x, y);
  p[y] = x;
  sz[x] += sz[y];
  return;
}

int uncoloured(vector<vector<int> > &v, int i,int j)
{
  int n = v.size();
  int cnt = 0;
  // t(i,j);
  if(i%2==0)
  { 
    if(i>0 && !v[i-1][j]) cnt++;
    else if(i==0) cnt++;
    // t(cnt);
    if(i>0 && j>0 && !v[i-1][j-1]) cnt++;
    else if(i==0 || j==0) cnt++;
    // t(cnt);
    if(j+1<n && !v[i][j+1]) cnt++;
    else if(j+1==n) cnt++;
    // t(cnt);
    if(j>0 && !v[i][j-1]) cnt++;
    else if(j==0) cnt++;
    // t(cnt);
    if(i+1<n && j>0 && !v[i+1][j-1]) cnt++;
    else if(i+1==n || j==0) cnt++;
    // t(cnt);
    if(i+1<n && !v[i+1][j]) cnt++;
    else if(i+1==n) cnt++;
    // t(cnt);
  }
  else
  {
    // (i,j-1),(i,j+1),(i-1,j),(i-1,j+1),(i+1,j+1),(i+1,j)

    if(j>0 && !v[i][j-1]) cnt++;
    else if(j==0) cnt++;
    // t(cnt);
    if(j+1<n-1 && !v[i][j+1]) cnt++;
    else if(j+1==n-1) cnt++;
    // t(cnt);
    if(i>0 && !v[i-1][j]) cnt++;
    else if(i==0) cnt++;
    // t(cnt);
    if(i>0 && j+1<n && !v[i-1][j+1]) cnt++;
    else if(i==0 || j+1==n) cnt++;
    // t(cnt);
    if(i+1<n && j+1<n && !v[i+1][j+1]) cnt++;
    else if(i+1==n || j+1==n) cnt++;
    // t(cnt);
    if(i+1<n && !v[i+1][j]) cnt++;
    else if(i+1==n) cnt++;
    // t(cnt);
  }
  return cnt;
}

void activate(vector<vector<int> > &v,int i,int j)
{
  int n = v.size();
  int temp = i*n+j;
  if(i%2==0)
  { 
    if(i>0 && v[i-1][j]) 
    {
      int idx = (i-1)*n + (j);
      merge(idx,temp);
    }
    if(i>0 && j>0 && v[i-1][j-1]) 
    {
      int idx = (i-1)*n + (j-1);
      merge(idx,temp);
    }
    if(j+1<n && v[i][j+1]) 
    {
      int idx = (i)*n + (j+1);
      merge(idx,temp);
    }
    if(j>0 && v[i][j-1]) 
    {
      int idx = (i)*n + (j-1);
      merge(idx,temp);
    }
    if(i+1<n && j>0 && v[i+1][j-1]) 
    {
      int idx = (i+1)*n + (j-1);
      merge(idx,temp);
    }
    if(i+1<n && v[i+1][j]) 
    {
      int idx = (i+1)*n + (j);
      merge(idx,temp);
    }
  }
  else
  {
    // (i,j-1),(i,j+1),(i-1,j),(i-1,j+1),(i+1,j+1),(i+1,j)
    if(j>0 && v[i][j-1]) 
    {
      int idx = (i)*n + (j-1);
      merge(idx,temp);
    }
    if(j+1<n-1 && v[i][j+1]) 
    {
      int idx = (i)*n + (j+1);
      merge(idx,temp);
    }
    if(i>0 && v[i-1][j]) 
    {
      int idx = (i-1)*n + (j);
      merge(idx,temp);
    }
    if(i>0 && j+1<n && v[i-1][j+1]) 
    {
      int idx = (i-1)*n + (j+1);
      merge(idx,temp);
    }
    if(i+1<n && j+1<n && v[i+1][j+1]) 
    {
      int idx = (i+1)*n + (j+1);
      merge(idx,temp);
    }
    if(i+1<n && v[i+1][j]) 
    {
      int idx = (i+1)*n + (j);
      merge(idx,temp);
    }
  }
}

void print(vector<vector<int> > &v)
{
  cout << endl;
  int n = v.size();
  for(int i=0;i<n;i++)
  {
    int m;
    if(i%2) m = n-1;
    else m = n;
    for(int j=0;j<m;j++)
    {
      cout << find(i*n+j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  vector<vector<int> > v(n,vector<int>(n));
  for(int i=0;i<n;i++)
  {
    int m;
    if(i%2) m = n-1;
    else m = n;
    for(int j=0;j<m;j++) 
    {
      cin >> v[i][j];
      create(i*n+j);
      if(v[i][j]) activate(v,i,j);
    }
  }


  int q;
  cin >> q;
  while(q--)
  {
    // t(q);
    string s;
    cin >> s;
    if(s=="a")
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      v[a][b] = 1;
      activate(v,a,b);
      // print();
    }
    else
    {
      int a,b;
      cin >> a >> b;
      a--; b--;
      if(!v[a][b])
      {
        cout << 0 << endl;
        continue;
      }
      int col = find(a*n+b);
      int ans = 0;
      for(int i=0;i<n;i++)
      {
        int m;
        if(i%2) m = n-1;
        else m = n;
        for(int j=0;j<m;j++)
        {
          if(find(i*n+j) == col) 
          {
            int temp = uncoloured(v,i,j);
            // t(i+1,j+1,temp);
            ans += temp;
          }
        }
      }

      cout << ans << endl;
    }
  }
  return 0;
}

/*
3 3
0 1 0
0 1
0 0 0
5
a 1 3
k 2 2
k 2 1
a 3 1
k 3 1

3 3
0 1 0
0 1
0 0 0
2
a 1 3
k 2 2

5 5
0 1 0 0 0
0 1 0 0
0 0 0 1 1
1 0 1 0
0 0 0 1 1
2
a 2 1
a 3 3



*/