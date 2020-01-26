/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 4e9+1
#define MOD 1000000007
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

const int N = 102;
vector<pair<ll,ll> > adj[N] = {};

void path(int n,int u,vector<ll> &dist)
{
  set<pair<ll,ll> > pq;

  pq.insert(mp(0,u));
  dist[u] = 0;
  while(!pq.empty())
  {
    pair<ll,ll> temp = (*pq.begin());
    int u = temp.se;
    pq.erase(temp);

    for(auto p : adj[u])
    {
      ll v = p.se, weight = p.fi;
      if(dist[v]> dist[u]+weight)
      {
        pq.erase(mp(dist[v],v));
        dist[v] = dist[u] + weight;
        pq.insert(mp(dist[v],v));
      }
    }
  }
}

ll min(ld x, ld y)
{
  if(x<y) return x;
  return y;
}

ld dis1(ll x1, ll y1, ll x2, ll y2)
{
  return sqrt(abs(x1-x2)*abs(x1-x2) + abs(y1-y2)*abs(y1-y2));
}

ll dis2(ll x1, ll y1, ll x2, ll y2)
{
  return abs(x1-x2) + abs(y1-y2);
}

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<vector<ll> > w;
    vector<ll> dist(n+2,INF);

    for(int i=0;i<n;i++) 
    {
      ll a,b,c;
      cin >> a >> b >> c;
      w.pu({a,b,c});
    }

    ll x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    w.pu({x1,y1,0});
    w.pu({x2,y2,0});

    for(int i=0;i<w.size();i++)
    {
      ll p = w[i][2];
      for(int j=0;j<w.size();j++)
      {
        if(i==j) continue;

        ld d1 = dis1(w[i][0],w[i][1],w[j][0],w[j][1]);
        ll d2 = dis2(w[i][0],w[i][1],w[j][0],w[j][1]);
        // t(i,j,d1,d2);
        if(d1<=p) 
        {
          if(2LL<d2) adj[i].pu(mp(2,j));
          // adj[i].pu(mp(d2,j));
        }
        adj[i].pu(mp(d2,j));
      }   
    }

    // for(int i=0;i<n;i++) t(adj[i]);
    path(n+2,n,dist);

    // for(int i=0;i<=n+1;i++) cout << dist[i] << " "; cout << endl;
    cout << dist[n+1] << endl;

    for(int i=0;i<n+2;i++) adj[i].clear();
    // memset(adj,0,sizeof(adj));
    
  }
  return 0;
}

/*
2
3
5 5 5
9 5 3
11 7 2
4 6 11 8
3
5 5 5
9 5 3
11 7 2
4 6 11 8

 */
