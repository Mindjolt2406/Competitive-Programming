#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define vi vector<int>

using namespace std;

void print(int**l, int n,int m)
{
  for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<l[i][j]<<" ";cout<<endl;}
  cout<<endl;
}
void dfs1(int**l, int** visited, int key, set<int> &s,int i,int j,int n,int m)
{
  if(visited[i][j]==-1 || visited[i][j]>l[i][j]) return;
  visited[i][j] = -1;
  if(i>0 && l[i-1][j]==key) dfs1(l,visited,key,s,i-1,j,n,m);
  else if(i>0 && l[i-1][j] > key) s.insert(l[i-1][j]);
  if(i<n-1 && l[i+1][j]==key) dfs1(l,visited,key,s,i+1,j,n,m);
  else if(i<n-1 && l[i+1][j] > key) s.insert(l[i+1][j]);
  if(j>0 && l[i][j-1]==key) dfs1(l,visited,key,s,i,j-1,n,m);
  else if(j>0 && l[i][j-1] > key) s.insert(l[i][j-1]);
  if(j<m-1 && l[i][j+1]==key) dfs1(l,visited,key,s,i,j+1,n,m);
  else if(j<m-1 && l[i][j+1] > key) s.insert(l[i][j+1]);
}

int dfs2(int**l, int** visited, int key1,int key2, int i,int j,int n,int m)
{
  // cout<<"i: "<<i<<" j: "<<j<<endl;
  if((visited[i][j]==key1 && l[i][j]==key2) || (visited[i][j]==key2 && l[i][j]==key1)) return 0;
  if(l[i][j]==key1) visited[i][j] = key2;
  else if(l[i][j]==key2)visited[i][j] = key1;
  int count = 1;
  if(i>0 && (l[i-1][j]==key1 || l[i-1][j]==key2)) count+=dfs2(l,visited,key1,key2,i-1,j,n,m);
  // else if(i>0 && l[i-1][j] > key) s.insert(l[i-1][j]);
  if(i<n-1 && (l[i+1][j]==key1 || l[i+1][j]==key2)) count+=dfs2(l,visited,key1,key2,i+1,j,n,m);
  // else if(i<n-1 && l[i+1][j] > key) s.insert(l[i+1][j]);
  if(j>0 && (l[i][j-1]==key1 || l[i][j-1]==key2)) count+=dfs2(l,visited,key1,key2,i,j-1,n,m);
  // else if(j>0 && l[i][j-1] > key) s.insert(l[i][j-1]);
  if(j<m-1 && (l[i][j+1]==key1 || l[i][j+1]==key2)) count+=dfs2(l,visited,key1,key2,i,j+1,n,m);
  // else if(j<m-1 && l[i][j+1] > key) s.insert(l[i][j+1]);
  return count;
}

int main()
{
  int n,m;
  scanf("%d %d",&n,&m);
  int **l = new int*[n];
  for(int i=0;i<n;i++) l[i] = new int[m];
  int **visited = new int*[n];
  for(int i=0;i<n;i++) visited[i] = new int[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j] = 0;
  set<int> s;
  set<int> :: iterator it,it1;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) {scanf("%d",&l[i][j]);}
  int max1 = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(visited[i][j]<l[i][j])
      {
        dfs1(l,visited,l[i][j],s,i,j,n,m);
        // print(visited,n,m);
        for(it = s.begin();it!=s.end();it++)
        {
          // cout<<"*it: "<<*it<<endl;
          int c = dfs2(l,visited,l[i][j],*it,i,j,n,m);
          max1 = max(max1,c);
          if(c==max1)cout<<l[i][j]<<" "<<*it<<endl;
          // cout<<"max1: "<<max1<<endl;
          // print(visited,n,m);
        }
        s.clear();
      }
    }
  }
  if(max1)printf("%d\n",max1);
  else printf("%d\n",n*m);
  return 0;
}
