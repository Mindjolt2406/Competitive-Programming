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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

map<int,int> d;

void dfs(vector<int>*adj,int *ans,multiset<int> &sleft,multiset<int> &sright,int u)
{
  // adj[u][0] is the value
  // adj[u][1] is the left index
  // adj[u][2] is the right index

  // t(u,sright.size(),sleft.size());
  ans[u] = 1;
  if(sleft.rbegin()!=sleft.rend())
  {
    int c = *sleft.rbegin();
    if(c<=adj[u][0]) ans[u] = 1;
    else ans[u] = 0;
  }
  if(sright.begin()!=sright.end())
  {
    int c = *sright.begin();
    if(c>=adj[u][0] && ans[u]!=0) ans[u] = 1;
    else ans[u] = 0;
  }
  d[adj[u][0]]|=ans[u];
  if(adj[u][1]!=-1)
  {
    sright.insert(adj[u][0]);
    dfs(adj,ans,sleft,sright,adj[u][1]);
    sright.erase(sright.find(adj[u][0]));
  }

  if(adj[u][2]!=-1)
  {
    sleft.insert(adj[u][0]);
    dfs(adj,ans,sleft,sright,adj[u][2]);
    sleft.erase(sleft.find(adj[u][0]));
  }
  // t(u,sright.size(),sleft.size());
}

int main()
{
  int n;
  sc(n);
  vector<int>*adj = new vector<int>[n];
  int*parent = (int*)calloc(n,sizeof(int));
  for(int i=0;i<n;i++) parent[i] = -1;
  map<int,int> counter;
  for(int i=0;i<n;i++)
  {
    int a,b,c;
    sc(a);sc(b);sc(c);
    d[a] = 0;
    if(counter.find(a)==counter.end()) counter[a] = 1;
    else counter[a] ++;
    if(b!=-1) {b--;parent[b] = i;}
    if(c!=-1) {c--;parent[c] = i;}
    adj[i].pu(a);
    adj[i].pu(b);
    adj[i].pu(c);
  }
  multiset<int> sleft,sright;
  int*ans= (int*)calloc(n,sizeof(int));
  int root = -1;
  for(int i=0;i<n;i++) if(parent[i] ==-1) {root = i;break;}
  // t(root);
  dfs(adj,ans,sleft,sright,root);
  // _;
  int count =0 ;
  map<int,int> :: iterator it;
  for(it=d.begin();it!=d.end();it++)
  {
    if(it->second==0) count+=counter[it->first];
  }
  
  // for(int i=0;i<n;i++) cout<<ans[i]<<" ";cout<<endl;
  cout<<count<<endl;
  return 0;
}