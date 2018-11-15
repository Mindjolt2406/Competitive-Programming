#include<bits/stdc++.h>
using namespace std;

void print(int**l, int n,int m)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++) cout<<l[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
}

int dfs(char **l, int** visited, int i,int j,int n,int m)
{
  // cout<<"i: "<<i<<" j: "<<j<<endl;
  // print(visited,n,m);
  if(i<0 || j<0 ||i>=n || j>=m) return 1;
  if(visited[i][j]==1) return 1;
  else if(visited[i][j]==2) return 0;
  visited[i][j] = 1;
  int c = 0;
  if(l[i][j]=='N')  c = dfs(l,visited, i-1,j,n,m);
  else if(l[i][j]=='E') c = dfs(l,visited,i,j+1,n,m);
  else if(l[i][j]=='W') c = dfs(l,visited,i,j-1,n,m);
  else c = dfs(l,visited,i+1,j,n,m);
  visited[i][j] = 2;
  return c;
}

int main()
{
  int n,m;
  cin>>n>>m;
  char **l = new char*[n];
  for(int i=0;i<n;i++) l[i] = new char[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>l[i][j];
  int **visited = new int*[n];
  for(int i=0;i<n;i++) visited[i] = new int[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = 0;
  int c = 0,count = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(visited[i][j]==0)
      {
        c = dfs(l,visited,i,j,n,m);
        if(c==1) count++;
      }
    }
  }
  cout<<count<<endl;
}
