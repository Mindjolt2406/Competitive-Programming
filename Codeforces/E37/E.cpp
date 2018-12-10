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
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

int boo = 1;

void dfs(vector<int>*adj,int*visited,int u,int key)
{
  // if(visited[u] == -1) boo = 0;
  if(visited[u]) return;
  visited[u] = key;
  for(int i=0;i<adj[u].size();i++)
  {
    dfs(adj,visited,adj[u][i],key);
  }
}

int main()
{
  int n,m;
  sc(n);sc(m);
  vector<int>*adj = new vector<int> [n];
  vector<int> deg,vert,other; 
  deg.assign(n,0);
  vert.assign(n,0);
  other.assign(n,0);
  set<pair<int,int> > edge;
  int boo = 1,count = 0; // Checks whether the guys taken granted for 1 component are a part of the guys in the dfs component or no
  for(int i=0;i<m;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    edge.insert(mp(a,b));
    edge.insert(mp(b,a));
    deg[a]++;deg[b]++;
  }
  
  for(int i=0;i<n;i++) other[i] = 1;

  for(set<pair<int,int> >:: iterator it = edge.begin();it!=edge.end();it++)
  {
    if(deg[it->fi]>n/2) 
    {
      vert[it->fi] = 1;
      other[it->fi] = 0;
    }
    if(deg[it->se]>n/2) 
    {
      vert[it->se] = 1;
      other[it->se] = 0;
    }
  }


  // for(int i=0;i<n;i++) cout<<vert[i]<<" ";cout<<endl;
  // for(int i=0;i<n;i++) cout<<deg[i]<<" ";cout<<endl;
  // Make the graph
  vector<int> keep;
  for(int i=0;i<n;i++)
  {
    if(vert[i])
    {
      for(int j=0;j<n;j++)
      {
        // if(vert[j] && edge.find(mp(i,j))==edge.end())
        if(edge.find(mp(i,j))==edge.end())
        {
          if(other[j]) {boo = 0;keep.pu(i);}
          // t(i,j);
          if(i==j) continue;
          adj[i].pu(j);
          adj[j].pu(i);
        }
        // else if(other[j] && edge.find(mp(i,j))==edge.end()) {boo = 0;keep = i;}
      }
    }
  }

  // for(int i=0;i<n;i++)
  // {
  //   cout<<i<<" : ";
  //   for(int j=0;j<adj[i].size();j++) cout<<adj[i][j]<<" ";cout<<endl;
  // }

  // Initialise visited
  int*visited = (int*)calloc(n,sizeof(int));
  for(int i=0;i<n;i++) visited[i] = 0;

  for(int i=0;i<n;i++) if(other[i]) count++;
  for(int i=0;i<n;i++) if(other[i]) visited[i] = 1;
  // map for counting the number of guys per component
  map<int,int> d;
  if(!boo) 
  {
    int count = 0;
    // t(keep);
    for(int i=0;i<keep.size();i++) dfs(adj,visited,keep[i],1);
    for(int i=0;i<n;i++) if(visited[i]==1) count++;
    // for(int i=0;i<n;i++) cout<<visited[i]<<" ";cout<<endl;
    d[1] = count;
  }
  else d[1] = count;
  // Dfs for connected components
  int key = 2;
  for(int i=0;i<n;i++)
  {
    if(!visited[i] && vert[i])
    {
      // t(i,key);
      dfs(adj,visited,i,key);
      d[key] = 1;
      key++;
    }
    else if(vert[i] && visited[i] && visited[i]!=1) d[visited[i]]++;
  }

  // for(int i=0;i<n;i++) cout<<visited[i]<<" ";cout<<endl;

  vector<int> out;
  // t(boo);
  // if(boo==0) d[keep]+=count;
  // if(boo==1) out.pu(count);
  for(auto it = d.begin();it!=d.end();it++) out.pu(it->second);
  sort(out.begin(),out.end());
  cout<<key-1<<endl;
  for(int i=0;i<out.size();i++) cout<<out[i]<<" ";cout<<endl;
  return 0;
}

