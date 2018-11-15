#pragma comment(linker, "/STACK:2000000")
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

void dfs(vector<string> &v, int i,int j,int key,int**visited,int n,int m)
{
  visited[i][j] = key;
  if(i>0 && !visited[i-1][j] && v[i-1][j]=='.') dfs(v,i-1,j,key,visited,n,m);
  if(i<n-1 && !visited[i+1][j] && v[i+1][j]=='.') dfs(v,i+1,j,key,visited,n,m);
  if(j>0 && !visited[i][j-1] && v[i][j-1]=='.') dfs(v,i,j-1,key,visited,n,m);
  if(j<m-1 && !visited[i][j+1] && v[i][j+1]=='.') dfs(v,i,j+1,key,visited,n,m);
} 

int main()
{
  int n,m,q;
  // map<int,int> d;
  sc(n);sc(m);sc(q);
  // string*v = new string[n];
  vector<string> v;
  int** visited = (int**)calloc(n,sizeof(int*));
  for(int i=0;i<n;i++) visited[i] = (int*)calloc(m,sizeof(int));
  for(int i=0;i<n;i++)
  {
    string s;
    scr(s);
    v.pu(s);
  }
  int key = 1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    { 
      if(visited[i][j] || v[i][j]=='*') continue;
      dfs(v,i,j,key,visited,n,m);
      key++;
    }
  }
  int*d = (int*)calloc(key,sizeof(int));
  // for(int i=1;i<key;i++) d[i] = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      int count = 0;
      if(i>0 && v[i-1][j]=='*') count++;
      if(i<n-1 && v[i+1][j]=='*') count++;
      if(j>0 && v[i][j-1]=='*') count++;
      if(j<m-1 && v[i][j+1]=='*') count++;
      d[visited[i][j]] +=count;
    }
  }
  // for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<visited[i][j]<<" ";cout<<endl;}
  for(int i=0;i<q;i++)
  {
    int a,b;
    sc(a);sc(b);
    a--;b--;
    printf("%d\n",d[visited[a][b]]);
  }
  return 0;
}

