#include<bits/stdc++.h>
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 main.cpp
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

ll power(ll x, ll y, ll p)
{
	ll res = 1;      // Initialize result
	x = x % p;  // Update x if it is more than or
	while (y > 0)
	{
			if (y & 1)
					res = (res*x) % p;
			y = y>>1; // y = y/2
			x = (x*x) % p;
	}
	return res;
}

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

typedef struct query
{
  ll s,t,k;
  int index;

  bool operator <(const query &q1) const
  {
    if(this->k == q1.k) return this->index < q1.index;
    else return this->k < q1.k;
  }

} query;

ll min(ll x, ll y) {return x<y?x:y;}
ll max(ll x, ll y) {return x>y?x:y;}

void solve1(vector<pair<int,int> > &stable, vector<query> &queries, vector<bool> &answers)
{
  int n = stable.size();
  vector<vector<ll> > dist(n, vector<ll>(n,1e18));
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i == j) continue;
      dist[i][j] = abs(stable[i].fi - stable[j].fi) + abs(stable[i].se - stable[j].se)-1;
    }
  }

  for(int k=0;k<n;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        dist[i][j] = min(dist[i][j],max(dist[i][k],dist[k][j]));
      }
    }
  }

  // t(dist);

  for(auto query : queries)
  {
    answers[query.index] = (dist[query.s][query.t] <= query.k ? 1 : 0);
  }
}

void solve2(vector<pair<int,int> > &stable, vector<query> &queries, vector<bool> &answers)
{
  set<pair<int,int> > stableSet;
  map<pair<int,int> , int> stableMap;
  for(int i=0;i<stable.size();i++) 
  {
    stableMap[stable[i]] = i;
    create(i);
  }

  for(auto pair : stable) stableSet.insert(pair);

  sort(queries.begin(), queries.end());
  // reverse(queries.begin(), queries.end());
  int prevK = 0;
  for(auto query : queries)
  {
    // t(query.s, query.t, query.k);
    if(prevK < query.k)
    {
      for(auto pair : stable)
      {
        int total = query.k+1;
        for(int k1=-total;k1<=total;k1++)
        {
          for(int k2=-total;k2<=total;k2++)
          {
            {
              int x = pair.fi+k1;
              int y = pair.se + (total-abs(k2));
              if(abs(x-pair.fi) + abs(y-pair.se) > total) continue;
              if(stableSet.count(mp(x,y)))
              {
                // t(total,stableMap[mp(x,y)],stableMap[pair]);
                merge(stableMap[mp(x,y)],stableMap[pair]);
              }
            }
            {
              int x = pair.fi+k1;
              int y = pair.se - (total-abs(k2));
              if(abs(x-pair.fi) + abs(y-pair.se) > total) continue;
              if(stableSet.count(mp(x,y)))
              {
                // t(total,stableMap[mp(x,y)],stableMap[pair]);
                merge(stableMap[mp(x,y)],stableMap[pair]);
              }
            }
          }
        }
        prevK = query.k;
      }
    }
    answers[query.index] = find(stableMap[stable[query.s]]) == find(stableMap[stable[query.t]]);
  }
}

int main()
{
  __;
  ll n,q,sq,mk;
  cin >> n >> q >> sq >> mk;
  vector<pair<int,int> > stable(n);
  for(int i=0;i<n;i++) cin >> stable[i].fi >> stable[i].se;

  ll as,bs,cs,at,bt,ct,ak,bk,ck;
  cin >> as >> bs >> cs >> at >> bt >> ct >> ak >> bk >> ck;

  vector<ll> vs(q), vt(q), vk(q);
  vector<query> queries(q);
  for(int i=0;i<sq;i++) cin >> vs[i] >> vt[i] >> vk[i];

  for(int i=sq;i<q;i++) vs[i] = ((((as*vs[i-1]) % n ) + ((bs*vs[i-2]) % n)) % n + cs) % n + 1;
  for(int i=sq;i<q;i++) vt[i] = ((((at*vt[i-1]) % n ) + ((bt*vt[i-2]) % n)) % n + ct) % n + 1;
  for(int i=sq;i<q;i++) vk[i] = (((((ak*vk[i-1]) % mk) + ((bk*vk[i-2]) % mk)) % mk) + ck) % mk;

  for(int i=0;i<q;i++) 
  {
    queries[i].s = vs[i]-1;
    queries[i].t = vt[i]-1;
    queries[i].k = vk[i];
    queries[i].index = i;
    // t(vs[i],vt[i],vk[i]);
  }

  vector<bool> answers(q);
  // solve2(stable,queries,answers);
  if(n <= 500)
  {
    solve1(stable,queries,answers);
  }
  else 
  {
    solve2(stable,queries,answers);
  }

  ll ans = 0;
  for(int i=0;i<q;i++)
  {
    ll a = power(2,i+1,MOD);
    if(answers[i]) ans += a;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
