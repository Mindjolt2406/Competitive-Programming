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

const int N = 1e5+100;
vector<int> adj[N] = {};
vector<int> col(N,-1);
int key = 0;

void dfs(int u)
{
  col[u] = key;
  t(u,key);
  for(auto v : adj[u])
  {
    if(col[v] == -1) dfs(v);
  }
}

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

int main()
{
  __;
  int t;
  cin >> t;
  while(t--)
  {
    int n,m;
    cin >> n >> m;
    vector<string> v;
    for(int i=0;i<n;i++)
    {
      string s;
      cin >> s;
      v.pu(s);
    }

    for(int j=0;j<m;j++)
    {
      for(int i=0;i<n;i++)
      {
        if(v[i][j] == '1') 
        {
          adj[j].pu(i+100);
          adj[i+100].pu(j); 
        }
      }
    }

    for(int i=100;i<100+n;i++)
    {
      if(col[i] == -1) 
      {
        dfs(i);
        key++;
      }
    }

    for(int i=100;i<100+n;i++) cout << col[i] << " ";
    cout << endl;
    map<int,int> d;
    for(int i=0;i<key;i++) d[i] = 0;
    for(int i=100;i<100+n;i++) d[i]++;

    ll prod = 1;
    for(auto it : d)
    {
      prod *= it.se;
      prod %= MOD;
    }

    prod = prod -1 + MOD;
    prod %= MOD;

    cout << prod << endl;

    key = 0;
    for(int i=0;i<N;i++) adj[i].clear();
    for(int i=0;i<N;i++) col[i] = -1;
  }
  return 0;
}

