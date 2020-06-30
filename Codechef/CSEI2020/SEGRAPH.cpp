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

const int N = 1e5+100;
vector<bool> bip(N); // bip of a collour
vector<int> par(N); //parity of a vertex
vector<vector<int> > col_vert(N); // col[u] -> vector of vertices
vector<int> col(N);
vector<int> sz(N); // sz[colour]

void create(int i)
{ 
  col_vert[i].pu(i);
  col[i] = i;
  sz[i] = 1;
  bip[i] = true;
  par[i] = 0;
}

void invert(int a)
{
  // t(a,col_vert[a].size());
  for(int i=0;i<col_vert[a].size();i++)
  {
    par[col_vert[a][i]] ^= 1;
  }
  // _;
}

void merge(int x, int y)
{
  int a = col[x], b = col[y];
  if(a == b) 
  {
    bip[a] = false;
    // t(bip[a],a);
    return;
  }
  if(sz[a] < sz[b]) swap(a,b);
  if(par[x] == par[y])
  {
    invert(b);
  }

  for(int i=0;i<col_vert[b].size();i++)
  {
    int vert = col_vert[b][i];
    col[vert] = a;
    col_vert[a].pu(vert);
  }
  bip[a] = bip[a] && bip[b];
}

int main()
{
  __;
  int n;
  cin >> n;
  for(int i=0;i<n;i++) create(i);
  int q;
  cin >> q;
  while(q--)
  {
    int val;
    cin >> val;
    
    int a,b;
    cin >> a >> b;
    a--; b--;
    if(val == 1) merge(a,b);
    else
    {
      int x = col[a], y = col[b];
      // t(x,y,par[x],par[y]);
      if(x == y)
      {
        if(!bip[x]) cout << "No" << endl;
        else cout << "Yes" << endl;
      }
      else
      {
        // t(bip[x],bip[y],x,y);
        if(bip[x] && bip[y]) cout << "Yes" << endl;
        else cout << "No" << endl;
      }
    }

  }
  return 0;
}
