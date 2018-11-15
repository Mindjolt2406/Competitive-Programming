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

int store[2000][2000][2] = {0};

int poss(int x,int y,int n,int m)
{
  if(x>=0 && y>=0 && x<n && y<m) return 1;
  return 0;
}

int main()
{
  int n,m,a,b,x,y;
  // cout<<"here"<<endl;
  sc(n);sc(m);sc(a);sc(b);sc(x);sc(y);
  a--;b--;
  vector<string> v;
  for(int i=0;i<n;i++) 
  {
    string s;
    scr(s);
    v.pu(s);
  }
  deque<pair<int,int> > q;
  // cout<<"here"<<endl;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int k=0;k<2;k++) store[i][j][k] = INF;
  store[a][b][0] = 0;
  store[a][b][1] = 0;
  q.push_front(mp(a,b));
  // int dx[4] = {1,-1,0,0};
  // int dy[4] = {0,0,1,-1};
  while(!q.empty())
  {
    auto p = q.front();
    q.pop_front();
    int i = p.first, j = p.second;
    if(poss(i+1,j,n,m) && v[i+1][j]=='.' && store[i+1][j][0]+store[i+1][j][1]>store[i][j][0]+store[i][j][1])
    {
      q.push_front(mp(i+1,j));
      store[i+1][j][0] = store[i][j][0];
      store[i+1][j][1] = store[i][j][1];
    }
    if(poss(i-1,j,n,m) && v[i-1][j]=='.' && store[i-1][j][0]+store[i-1][j][1]>store[i][j][0]+store[i][j][1])
    {
      q.push_front(mp(i-1,j));
      store[i-1][j][0] = store[i][j][0];
      store[i-1][j][1] = store[i][j][1];
    }
    if(poss(i,j+1,n,m) && v[i][j+1]=='.' && store[i][j+1][0]+store[i][j+1][1]+1>store[i][j][0]+store[i][j][1])
    {
      q.push_back(mp(i,j+1));
      store[i][j+1][0] = store[i][j][0];
      store[i][j+1][1] = store[i][j][1]+1;
    }
    if(poss(i,j-1,n,m) && v[i][j-1]=='.' && store[i][j-1][0]+store[i][j-1][1]+1>store[i][j][0]+store[i][j][1])
    {
      q.push_back(mp(i,j-1));
      store[i][j-1][0] = store[i][j][0]+1;
      store[i][j-1][1] = store[i][j][1];
    }
  }
  int count = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      // cout<<i<<" "<<j<<" "<<store[i][j][0]<<" "<<store[i][j][1]<<endl;
      if(store[i][j][0]<=x && store[i][j][1]<=y) {count++;}
    }
  }
  cout<<count<<endl;
  return 0;
}

