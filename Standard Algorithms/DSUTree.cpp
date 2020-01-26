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

const int N = 1e5+1;
int count[N] = {0};
int colour[N] = {0};
bool big[N] = {false};
vector<int> adj[N];
int sz[N] = {0};

void add(int u,int p, int k)
{
  count[colour[u]] +=k;
  for(int i=0;i<adj[u].size();i++)
  {
    if(!big[adj[u][i]] && adj[u][i]!=p) add(adj[u][i],p,k);
  } 
}

int dfs(int u,int p)
{
  if(adj[u].size()==1 && adj[u][0]==p) {sz[u] = 1;return 1; }
  int count = 0;
  for(int i=0;i<adj[u].size();i++)
  {
    if(adj[u][i]!=p) count+=dfs(adj[u][i],u);
  }
  sz[u] = count;
  return count;
}

void dfs(int u,int p, bool boo)
{
  int max1 = -1, big1 = -1;
  for(int i=0;i<adj[u][i].size();i++)
  {
    if(adj[u][i]!=p) 
    {
      if(sz[adj[u][i]]>max1)
      {
        max1 = sz[adj[u][i]];
        big1 =adj[u][i];
        big[adj[u][i]] = true;
      }
    }
  }

  // Do the dfs for small
  for(int i=0;i<adj[u][i].size();i++)
  {
    if(adj[u][i]!=p && ! big[adj[u][i]]) dfs(adj[u][i],u,0);
  }

  // Do the dfs for big after small
  if(big1!=-1) dfs(big1,u,1);

  add(u,p,1);

  // Ans queries here

  // Clear the bigchild if any
  if(big1!=-1) big[big1] = false;

  // Clear if small
  if(!boo) add(u,p,-1);
}

int main()
{

  return 0;
}

