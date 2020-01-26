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
map<pair<int,int> , ll> edge;
vector<set<int> > par(N);
vector<set<int> > child(N);
set<int> pending;
queue<int> q;

void add(int i)
{
  if(par[i].size() && child[i].size()) 
  {
    if(!pending.count(i)) 
    {
      q.push(i);
      pending.insert(i);
    }
  }
}

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  __;
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++)
  {
    int a,b;
    ll c;
    cin >> a >> b >> c;
    a--; b--;
    edge[mp(a,b)] += c;
    par[b].insert(a);
    child[a].insert(b);
  }  

  for(int i=0;i<n;i++) 
  {
    add(i);
  }


  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    pending.erase(u);

    auto left = par[u].begin();
    auto right = child[u].begin();

    while(left != par[u].end() && right != child[u].end())
    {
      ll a = edge[mp(*left,u)];
      ll b = edge[mp(u,*right)];
      t(*left,u,*right,a,b);
      for(auto it : edge) t(it);
      _;

      edge[mp(*left,u)] -= min(a,b);
      edge[mp(u,*right)] -= min(a,b);

      edge[mp(*left,*right)] += min(a,b);
      par[*right].insert(*left);
      par[*left].insert(*right);

      add(*left);
      add(*right);
      
      for(auto it : edge) t(it);
      _;
      if(!edge[mp(*left,u)]) 
      {
        edge.erase(mp(*left,u));
        child[*left].erase(u);
        left++;
      }
      _;
      if(!edge[mp(u,*right)]) 
      {
        edge.erase(mp(u,*right));
        par[*right].erase(u);
        right++;
      }
      _;
      for(auto it : edge) t(it);
    }

    auto it = par[u].begin();

    while(it !=par[u].end() && *it!=*left)
    {
      par[u].erase(*it);
      it++;
    }
    _;
    it = child[u].begin();
    while(it != child[u].end() && *it != *right)
    {
      child[u].erase(*it);
      it++;
    }
  }

  cout << edge.size() << endl;
  for(auto it : edge)
  {
    cout << it.fi.fi + 1 << " " << it.fi.se + 1 << " " << it.se << endl;
  }
  return 0;
}

