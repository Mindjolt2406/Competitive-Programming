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

const int N = 1e5+10;
vector<int> adj[N] = {};
vector<int> vis(N);
vector<int>  check(N);
vector<int> dist(N,-1);

int bfs(int u,int t,int k)
{
  queue<int> q;
  q.push(u);
  dist[u] = k;
  vis[u] = dist[u];

  int boo = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u==t) {boo = 1; break;}
    // vis[u] = dist[u];
    // t(u,dist[u],k);
    // if(check[u]) dist[u] = k;
    int a = dist[u] - 1;
    if(a<0) continue;

    for(auto v : adj[u])
    {
      if(v==t) {boo = 1; break;}
      if(dist[v]<a) 
      {
        q.push(v); 
        // vis[v] = a;
        dist[v] = a;
        if(check[v]) dist[v] = k;
      }
    }

    if(boo) break;
  }
  return boo;
}

int main()
{
  __;
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=0;i<k;i++) 
  {
    int a;
    cin>>a;
    a--;
    check[a] = 1;
  }

  while(m--)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  int s,t;
  cin>>s>>t;
  s--;t--;

  int beg = 0, end = n,ans = -1;
  while(beg<=end)
  {
    int mid = (beg+end)>>1;
    int a = bfs(s,t,mid);
    // t(mid,a);
    if(a) {ans = mid; end = mid-1;}
    else beg = mid+1;
  }
  cout<<ans<<endl;
  return 0;
}

