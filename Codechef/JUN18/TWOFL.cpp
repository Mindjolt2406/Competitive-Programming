#include<bits/stdc++.h>
#define pu push_back
using namespace std;

typedef struct
{
  int colour;
  int size;
  int index;
  map<int,int>
  node()
  {
    colour = 0;
    size = 0;
    index = 0;
  }
} node;

// node newNode(int colour,int size,int index)
// {
//
// }

int N = 4000000;
void addEdge(vector<int>)

void shrink(int key,int **visited,int **l, int i,int j,map<int,int> &d,int n,int m)
{
  if(visited[i][j]) return;
  visited[i][j] = 1;
  if(i-1>=0 && l[i-1][j]!=key)
  {
    if(d.find(l[i-1][j])!=d.end()) d[l[i-1][j]]++;
    else d[l[i-1][j]] = 1;
  }
  else if(i-1>=0) shrink(key,visited,l,i-1,j,d);
  if(i+1<n && l[i+1][j]!=key)
  {
    if(d.find(l[i+1][j])!=d.end()) d[l[i+1][j]]++;
    else d[l[i+1][j]] = 1;
  }
  else if(i+1<n) shrink(key,visited,l,i+1,j,d);
  if(j-1>=0 && l[i][j-1]!=key)
  {
    if(d.find(l[i][j-1])!=d.end()) d[l[i][j-1]]++;
    else d[l[i][j-1]] = 1;
  }
  else if(j-1>=0) shrink(key,visited,l,i,j-1,d);
  if(j+1<m && l[i][j+1]!=key)
  {
    if(d.find(l[i][j+1])!=d.end()) d[l[i][j+1]]++;
    else d[l[i][j+1]] = 1;
  }
  else if(j+1<m) shrink(key,visited,l,i,j+1,d);
}

int main()
{
  int n,m;
  cin>>n>>m;
  set<int> s;
  set<int> ::iterator it;
  int **l = new int*[n];
  for(int i=0;i<n;i++) l[i] = new int[m];
  int **visited = new int*[n];
  for(int i=0;i<n;i++) visited[i] = new int[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) {cin>>l[i][j];}
  int n = N;
  vector<node>*adj = new vector<node>[N];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(!visited[i][j])
      {
        shrink(l[i][j],visited,l,i,j,s,n,m);
        for(it = s.begin();it!=s.end();it++)
        {

        }
        s.clear();
      }
    }
  }
  return 0;
}
