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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

// void bfs(vector <int> adj[],int n,vector<int>&v,int start)
// {
//   queue<int> q;
//   q.push(start);
//   q.push(-1);
//   v.pu(start);
//   v.pu(-1);
//   // int n = adj.size();
//   int* visited = (int*)calloc(n,sizeof(int));
//   while(!q.empty())
//   {
//     int u = q.front();
//     // if(u!=-1) count++;
//     if(q.size()!=1 && u==-1){q.push(-1);q.pop();v.pu(-1);}
//     else if(u==1 && q.size()==1) break;
//     visited[u] = 1;
//     q.pop();
//     for(int i=0;i<adj[u].size();i++)
//     {
//       if(visited[adj[u][i]]==0){q.push(adj[u][i]);v.pu(adj[u][i]);visited[adj[u][i]] = 1;}
//     }
//   }
// }

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  adj[v].pu(u);
}

int main()
{
  int n;
  sc(n);
  vector<int>*adj = new vector<int>[n];
  set<pair<int,int> > s;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    addEdge(adj,a,b);
    s.insert(mp(a,b));
    s.insert(mp(b,a));
  }
  vector<int>v;
  int*l = new int[n];
  for(int i=0;i<n;i++) {sc(l[i]);l[i]--;}
  if(l[0]!=0) {cout<<"No"<<endl;return 0;}
  // bfs(adj,n,v,l[0]);
  // for(int i=0;i<n;i++) cout<<l[i]<<" ";cout<<endl;
  int left = 0,right = 1;
  int boo = 1;
  while(right<n)
  {
    if(left>=right) {boo = 0;break;}
    if(s.find(mp(l[left],l[right]))!=s.end()) right++;
    else left++;
  }
  if(boo) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
