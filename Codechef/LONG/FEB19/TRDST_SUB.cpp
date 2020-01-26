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
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

void bfs(int root,int n, vector<vector<int> > &dist,vector<int>*adj)
{
  queue<int> q;
  vector<int> visited(n);
  visited[root] = 1;
  q.push(root);
  q.push(-1);
  int count = 0;
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    if(u==-1 && q.empty()) break;
    else if(u==-1) {q.push(-1);count++;continue;}
    
    dist[root][u] = count;
    // if(root==u) t(dist[u][u]);
    for(int i=0;i<adj[u].size();i++)
    {
      if(!visited[adj[u][i]])
      {
        visited[adj[u][i]] = 1;
        q.push(adj[u][i]);
      }
    }
  }
  // t(root);
}


int main()
{
  __;
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<v.size();i++) cin>>v[i];
  vector<int>*adj = new vector<int>[n];
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<vector<int> > dist(n,vector<int>(n)); 

  for(int i=0;i<n;i++) bfs(i,n,dist,adj);
  for(int i=0;i<n;i++) 
  {
    sort(dist[i].begin(),dist[i].end());
    reverse(dist[i].begin(),dist[i].end());
  }
  
  for(int i=0;i<n;i++) 
  {
    cout<<dist[i][v[i]-1]-1<<" ";
  }
  cout<<endl;
  return 0;
}

