#include<bits/stdc++.h>
#define pu push_back
#define mp make_pair
#define INF 1000000001
using namespace std;

int check(int i,int j,int n,int m)
{
  if(i<0||j<0 ||i>=n ||j>=m) return 0;
  return 1;
}

void bfs(int** l,int**visited,int n, int m, int i,int j)
{
  queue< pair<int,int> > q;
  q.push(mp(i,j));
  int boo = 0,count = 0;
  while(!q.empty())
  {
    pair<int,int> p = q.front();
    q.pop();
    int i = p.first,j = p.second;
    if(p.first==-1) {count++;boo = 0;}
    else
    {
      l[i][j] = min(l[i][j],count);
      if(!boo) {q.push(mp(-1,-1));boo = 1;}
      if(check(i+1,j,n,m) && !visited[i+1][j]) {q.push(mp(i+1,j));visited[i+1][j] = 1;}
      if(check(i-1,j,n,m) && !visited[i-1][j]) {q.push(mp(i-1,j));visited[i-1][j] = 1;}
      if(check(i,j+1,n,m) && !visited[i][j+1]) {q.push(mp(i,j+1));visited[i][j+1] = 1;}
      if(check(i,j-1,n,m) && !visited[i][j-1]) {q.push(mp(i,j-1));visited[i][j-1] = 1;}
    }
  }
}

int dfs(int**l, int** visited, int n, int m, int i,int j)
{
  if(!check(i,j,n,m)) return 1;
  int c = 0;
  if((check(i+1,j,n,m) && !visited[i+1][j] && l[i+1][j]!=0) || !check(i+1,j,n,m))
  {
    if(check(i+1,j,n,m)) {visited[i+1][j] =1;}
    c = max(dfs(l,visited,n,m,i+1,j),c);
    if(c) return c;
  }
  if((check(i-1,j,n,m) && !visited[i-1][j] && l[i-1][j]!=0) || !check(i-1,j,n,m))
  {
    if(check(i-1,j,n,m)) visited[i-1][j] =1;
    c = max(dfs(l,visited,n,m,i-1,j),c);
    if(c) return c;
  }
  if((check(i,j+1,n,m) && !visited[i][j+1] && l[i][j+1]!=0) || !check(i,j+1,n,m))
  {
    if(check(i,j+1,n,m)) visited[i][j+1] =1;
    c = max(dfs(l,visited,n,m,i,j+1),c);
    if(c) return c;
  }
  if((check(i,j-1,n,m) && !visited[i][j-1] && l[i][j-1]!=0) || !check(i,j-1,n,m))
  {
    if(check(i,j-1,n,m)) visited[i][j-1] =1;
    c = max(dfs(l,visited,n,m,i,j-1),c);
    if(c) return c;
  }
  return c;
}
int main()
{
  int n,m;
  cin>>n>>m;
  int q;
  cin>>q;
  for(int h=0;h<q;h++)
  {
    int m1,m2,c1,c2,c3,c4;
    cin>>m1>>m2>>c1>>c2>>c3>>c4;
    m1-=1;m2-=1;c1-=1;c2-=1;c3-=1;c4-=1;
    // Initalisation of 3 2d arrays - l,visited,checker
    int**l = new int*[n];
    for(int i=0;i<n;i++) l[i] = new int[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) l[i][j] = INF;
    int**visited = new int*[n];
    for(int i=0;i<n;i++) visited[i] = new int[m];
    int**checker= new int*[n];
    for(int i=0;i<n;i++) checker[i] = new int[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = 0;
    bfs(l,visited,n,m,c1,c2);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = 0;
    bfs(l,visited,n,m,c3,c4);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        int c = abs(m1-i)+abs(m2-j);
        if(l[i][j]==c) checker[i][j] = 0;
        else checker[i][j] = 1;
      }
    }
    checker[c1][c2] = 0; checker[c3][c4] = 0;
    int c = dfs(checker,visited,n,m,m1,m2);
    if(c==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  return 0;
}
