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
#define ll long long int
#define ld long double
#define fi first
#define se second
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
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 


const int N = 3e5+10;
vector<int> adj[N] = {},adj2[N] = {};
vector<int> vis(N);

// To get all the odd length cycles
// We know that they are disjoint
pair<bool,int> dfs(int u = 0,int p = -1)
{
  vis[u] = 1;
  pair<bool,int> temp = mp(false,-1);
  for(auto v : adj[u])
  {
    if(v-p)
    {
      if(vis[v]==1) {temp = mp(true,v);adj2[v].pu(u);}
      else if(!vis[v])
      {
        pair<bool,int> p = dfs(v,u);
        if(p.fi) 
        {
          adj2[p.se].pu(u);
          temp = p;
        }
        // t(u,v,p,temp);
      }
    }
  }

  vis[u] = 2;
  if(!temp.fi || u ==temp.se) temp = mp(false,-1);
  // t(u,temp);

  return temp;
}

ll f(vector<ll> &pref, int l,int r)
{
  if(r<0) return 0;
  if(l>0) return pref[r]-pref[l-1];
  else return pref[r];
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;
  while(m--)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  // w stores the min and max vertex of a cycle
  vector<pair<int,int> > w;
  // next[i] stores the index of a smallest max on the right which has a min >= i
  vector<int> next(N);
  // pref[i] stores the 
  vector<ll> pref(N);

  for(int i=0;i<n;i++)
  {
    if(!vis[i]) dfs(i);
  }

  // for(int i=0;i<n;i++) t(i,adj2[i]);
  for(int i=0;i<n;i++)
  {
    vector<int> v = adj2[i];
    if(v.size()==0) continue;
    int max1 = -1, min1 = INF;
    for(int i=0;i<v.size();i++)
    {
      max1 = max(max1,v[i]);
      min1 = min(min1,v[i]);
    }
    w.pu(mp(min1,max1));
  }

  // _;
  sort(w.begin(),w.end());
  for(int i=0;i<n;i++) next[i] = n;

  int right = n;
  for(int i=w.size()-1;i>=0;i--)
  {
    next[w[i].fi] = w[i].se;
  }

  for(int i=n-1;i>=0;i--)
  {
    right = min(next[i],right);
    next[i] = right;
    pref[i] = right-i;
  }

  for(int i=1;i<n;i++) pref[i]+=pref[i-1];

  int q;
  cin>>q;
  while(q--)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;

    int beg = a, end = b;
    ll ans = a-1;
    while(beg<=end)
    {
      int mid = (beg+end)>>1;
      if(next[mid]<=b) {ans = mid; beg = mid+1;}
      else end = mid-1;
    }

    ll count = f(pref,a,ans) + ((b-ans)*(b-ans+1))/2;
    cout<<count<<endl;
  }
  return 0;
}

