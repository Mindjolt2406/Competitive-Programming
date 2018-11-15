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


int main()
{
  int n,m;
  sc(n);sc(m);
  int** graph = new int*[n];
  for(int i=0;i<n;i++) graph[i] = new int[n];
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  int**dp = new int*[n];
  for(int i=0;i<n;i++) dp[i] = new int[(int)pow(2,n)];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<pow(2,n);j++)
    {
      for(int k=0;k<n;k++)
      {
        if(l[i][k])
        dp[i][j | 1<<k]
      }
    }
  }
  return 0;
}
