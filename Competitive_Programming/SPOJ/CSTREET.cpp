#include<bits/stdc++.h>
using namespace std;

int N = 1000001;
int sz[N] = {0};
int p[N] = {0};

void create(int x)
{
  sz[x] = 1;
  p[x] = x;
}

void finder(int x)
{
  if(p[x]==x) return x;
  return p[x] = finder(p[x]);
}

 int merger(int x,int y)
{
  x = finder(x);
  y = finder(y);
  if(x==y) return 0;
  if(sz[x]<sz[y])
  {
    int t = y; y = x; x = t;
  }
  p[y] = x;
  sz[x]+=sz[y];
  return 1;
}
int main()
{
  
}
