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

ll phif(ll n) 
{ 
    float result = n; // Initialize result as n 
  
    // Consider all prime factors of n and for every prime 
    // factor p, multiply result with (1 - 1/p) 
    for (int p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result *= (1.0 - (1.0 / (float)p)); 
        } 
    } 
  
    // If n has a prime factor greater than sqrt(n) 
    // (There can be at-most one such prime factor) 
    if (n > 1) 
        result *= (1.0 - (1.0 / (float)n)); 
  
    return (int)result; 
} 

const int N = 1e5+10;
vector<int> phi(N);

vector<int> adj[N] = {};

vector<pair<int,int>  >ans;

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}
void bfs(int st,int en,unordered_set<int> &s)
{
  queue<vector<ll> > q;
  q.push({st,st,0});

  while(!q.empty())
  {
    vector<ll>  v = q.front();
    q.pop();
    if(v[0] == en) 
    {
      // ans.pu(mp(v[2],v[1]));
      cout << v[2] << " " << v[1] << endl;
      break;
    }

    if(s.count(phi[v[0]]))
    {
      q.push({phi[v[0]],v[1]+phi[v[0]],v[2]+1});
    }
    if(s.count(v[0]*v[0]))
    {
      int a = v[0]*v[0];
      q.push({a,v[1]+a,v[2]+1});
    }
  }
}

int main()
{
  __;
  for(int i=1;i<N;i++) phi[i] = phif(i);

  int n,st,en;
  cin >> n >> st >> en;

  unordered_set<int> s;

  for(int i=0;i<n;i++) 
  {
    int a;
    cin >> a;
    s.insert(a);
  }

  bfs(st,en,s);

  int min1 = INF,min2 = INF;
  for(int i=0;i<ans.size();i++) min1 = min(min1,ans[i].fi);

  for(int i=0;i<ans.size();i++) 
  {
    if(min1 == ans[i].fi) min2 = min(min2,ans[i].se);
  }
  return 0;
}

