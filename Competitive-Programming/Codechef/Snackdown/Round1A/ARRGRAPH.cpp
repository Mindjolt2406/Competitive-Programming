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

int gcd(int a, int b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

void dfs(vector < int > *adj,int u,int *visited)
{
  if(u==-1) return;
  if(visited[u]!=0) return;
  visited[u] = 1;
  for(int i=0;i<adj[u].size();i++)
  {
    dfs(adj,adj[u][i],visited);
  }
}

int main()
{
  int t;
  sc(t);
  int m[9] = {2,3,5,7,11,13,17,19,23};
  while(t--)
  {
    vector<int>*adj = new vector<int>[51];
    int* visited = (int*)calloc(51,sizeof(int));
    int n;
    sc(n);
    int*l = new int[n];
    vector<int> v;
    set<int> s;
    for(int i=0;i<n;i++) {sc(l[i]);s.insert(l[i]);}
    if(n==1) {printf("0\n%d\n",l[0]);continue;}
    set<int> :: iterator it;
    for(it = s.begin();it!=s.end();it++) v.pu(*it);
    for(int i=0;i<v.size();i++)
    {
      for(int j=0;j<v.size();j++)
      {
        int a = v[i],b = v[j];
        int c = min(a,b),d = max(a,b);
        if(gcd(d,c)==1) 
        {
          adj[v[i]].pu(v[j]);
          adj[v[j]].pu(v[i]);
        }
      }
    }
    int root = -1;
    for(int i=2;i<51;i++) if(adj[i].size()!=0) {root = i;break;}
    dfs(adj,root,visited);
    int boo1 = 0;
    for(int i=0;i<v.size();i++) if(visited[v[i]]!=1) boo1 = 1;
    if(!boo1) 
    {
      printf("0\n");
      for(int i=0;i<n;i++) printf("%d ",l[i]);
      printf("\n");
    }
    else
    {
      l[0] = 47;
      if(s.size()==1 && *(s.begin())==47) l[0] = 43; 
      printf("1\n");
      for(int i=0;i<n;i++) printf("%d ",l[i]);
      printf("\n");
    }
    // for(int i=0;i<51;i++) visited[i] = 0;
    // for(int i=0;i<51;i++) adj[i].clear();
  }
  return 0;
}

/*
1
9
4 6 10 14 22 26 34 38 46 

*/