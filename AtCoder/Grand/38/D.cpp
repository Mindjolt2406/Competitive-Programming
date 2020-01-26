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
template <int> ostream& operator << (ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
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

int main()
{
  __;
  int n,m,q;
  cin >> n >> m >> q;
  vector<pair<int,int> > query;
  for(int i=0;i<n;i++) create(i);
  while(q--)
  {
    int a,b,c;
    cin >> a >> b >> c;
    if(!c) query.pu(mp(a,b));
    else
    {
      merge(a,b);
    }
  }

  for(int i=0;i<query.size();i++)
  {
    pair<int,int> p = query[i];
    if(find(p.fi) == find(p.se)) 
    {
      cout << "No" << endl;
      return 0;
    }
    m--;
    if(m<0) 
    {
      cout << "No" << endl;
      return 0;
    }
  }

  ll sum1 = 0, sum2 = 0;
  set<int> s;
  for(int i=0;i<n;i++) s.insert(find(i));


  for(auto it : s)
  {
    if(sz[it] > 1) 
    {
      if(sz[it] == 2) sum1 += 1;
      else sum1 += sz[it];
    }
    sum2 += (1LL*sz[it]*(sz[it]-1))/2;
    t(it,sum1,sz[it]);
  }

  t(sum1,sum2,m);
  if(sum1 <= m && m <= sum2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

cout << fixed << setprecision(12);
