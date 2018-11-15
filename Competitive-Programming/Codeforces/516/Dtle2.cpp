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

int**visited;
pair<int,int >**d;
// map<pair<int,int>,pair<int,int> > d; 

void bfs(vector<string> v,int x,int y,int n,int m)
{
  queue<pair<int,int> > q;
  q.push(mp(x,y));
  visited[x][y] = 1;
  while(!q.empty())
  {
    pair<int,int> p = q.front();
    int i = p.first,j = p.second;
    q.pop();
    pair<int,int> p1 = d[i][j];
    int x = p1.first, y = p1.second;
    // cout<<"i: "<<i<<" j: "<<j<<" x: "<<x<<" y: "<<y<<endl;
    if(i+1<n && v[i+1][j]=='.' && visited[i+1][j]==0 ) 
    {
      q.push(mp(i+1,j));
      d[i+1][j] = mp(x,y);
      visited[i+1][j] = 1;
    }
    if(j>0 && v[i][j-1]=='.' && visited[i][j-1]==0 && x>0)
    {
      q.push(mp(i,j-1));
      d[i][j-1] = mp(x-1,y);
      visited[i][j-1] = 1;
    }
    if(i>0 && v[i-1][j]=='.' && visited[i-1][j]==0)
    {
      q.push(mp(i-1,j));
      d[i-1][j] = mp(x,y);
      visited[i-1][j] = 1;
    }
    if(j+1<m && v[i][j+1]=='.' && visited[i][j+1]==0 && y>0)
    {
      q.push(mp(i,j+1));
      d[i][j+1] = mp(x,y-1);
      visited[i][j+1] = 1;
    }
  } 
}

int main()
{
  int n,m,a,b,x,y;
  sc(n);sc(m);
  cin>>a>>b>>x>>y;
  d =  new pair<int,int>*[n];
  for(int i=0;i<n;i++) d[i] = new pair<int,int>[m];
  vector<string> v;
  for(int i=0;i<n;i++) 
  {
    string s;
    scr(s);
    v.pu(s);
  }
  visited = (int**)calloc(n,sizeof(int*));
  for(int i=0;i<n;i++) visited[i] = (int*)calloc(m,sizeof(int));
  d[a-1][b-1] = mp(x,y);
  bfs(v,a-1,b-1,n,m);
  int count = 0;
  for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<visited[i][j]<<" "; cout<<endl;}
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) count+=visited[i][j];
  cout<<count<<endl;
  return 0;
}

