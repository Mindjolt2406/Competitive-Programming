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

void addEdge(vector<pair<int,int> >*adj,int a,int b,int c)
{
  adj[a].pu(mp(b,c));
  adj[b].pu(mp(a,c));
}

void floydWasrhall(int**dp,int n)
{
  for(int k=0;k<n;k++)
  {
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++) dp[i][j] = min(dp[i][k]+dp[k][j],dp[i][j]);
    }
  }
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,h,m;
    sc(n);sc(h);sc(m);
    vector<pair<int,int> >*adj = new vector<pair<int,int> >[n];
    int**dist = new int*[n];
    for(int i=0;i<n;i++) dist[i] = new int[n];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==j) dist[i][j] = 0;
        else dist[i][j] = INF;
      }
    }
    for(int i=0;i<n;i++)
    {
      int a,b,c;
      sc(a);sc(b);sc(c);
      a--;b--;
      // addEdge(adj,a,b,c);
      dist[a][b] = c;
      // dist[b][a] = c;
    }
    floydWasrhall(dist,n);
    int z;
    sc(z);
    vector<pair<int,int> > v;

    for(int i=0;i<z;i++)
    {
      int a,b,c;
      sc(a);sc(b);
      for(int j=0;j<c;j++) v.pu(mp(a,b));
    }
    int*dp = new int[v.size()];
    for(int i=0;i<pow(2,v.size());i++) dp[i] = INF;
    dp[0] = 0;
    for(int i=0;i<pow(2,v.size());i++)
    {
      x = // Count the number of bits as those many tasks have been assigned already
      for(int j=0;j<n;j++)
      {
        if (!((1<<j)&i))
        {
          if(j==0)
          {
            dp[i|1<<j] = min(dp[i|1<<j],dp[i]+dist[x][j] + dist[b][x])
          }
          else if(j==n-1)
          {

          }
          else
          {
            
          }
      }
      for(int )
    }
  }
  return 0;
}
