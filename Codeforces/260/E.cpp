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
#define vi vector<int>
#define vll vector<long long int>
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

const int N = 3e5+10;

int visited[N] = {0};
int pre[N] = {0}, ans[N] = {0};
int p[N], sz[N];
int key = 1;
vector<int> adj[N];

int dfs(int u,int p = -1)
{
  if(visited[u]) return 0;
  visited[u] = key;
  int max1 = 0, max2 = 0;
  for(auto v : adj[u])
  {
    if(v==p) continue;
    int a = dfs(v,u);
    if(a>max1) {max2 = max1; max1 = a;}
    else if(a>max2) max2 = a;
  }

  pre[u] = max1+max2+1;
  // t(u+1,pre[u],max1,max2);
  return max1+1;
}


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
  cin>>n>>m>>q;
  while(m--)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      dfs(i);
      key++;
    }
  }

  for(int i=0;i<n;i++)
  {
    ans[visited[i]] = max(ans[visited[i]], pre[i]);
  }

  for(int i=1;i<=n;i++) create(i);
  // for(int i=0;i<n;i++) t(visited[i], find(visited[i]));cout<<endl;
  // for(int i=0;i<n;i++) cout<<pre[i]<<" ";cout<<endl;

  while(q--)
  {
    int a;
    cin>>a;
    if(a==1)
    {
      int b;
      cin>>b;
      b--;
      cout<<ans[find(visited[b])]-1<<endl;
    }
    else
    {
      int b,c;
      cin>>b>>c;
      b--;c--;
      int d = find(visited[b]), e = find(visited[c]);
      // t(b,c,d,e);
      if(d!=e)
      {
        int f = ans[d], g = ans[e];
        int max1 = max(f,g);
        merge(visited[b],visited[c]);
        // t(f,g);
        int h = f/2 + g/2 + 2;
        // t(b,c,f,g,h,ans[find(visited[b])]);
        ans[find(visited[b])] = max(h,max1);

      }
    }
  }

  return 0;
}

/*
5 3 2
1 2
2 3
3 4
2 1 5
1 5

*/