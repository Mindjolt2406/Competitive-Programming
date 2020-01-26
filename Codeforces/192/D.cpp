/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;


bool check(int i,int j,int n,int m)
{
  if(i<0 || j<0 || i>=n || j>=m) return false;
  return true;
}

int main()
{
  __;
  int n,m;
  cin>>n>>m;

  vector<string> v(n);
  vector<vector<int> > w(n,vector<int> (m));
  vector<vector<int> > x(n,vector<int> (m,INF));
  vector<vector<int> > vis(n,vector<int> (m));
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
  }

  pair<int,int> start,end;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(v[i][j]=='T') w[i][j] = -1;
      else if(v[i][j]=='S') {start = mp(i,j); w[i][j] = 1;}
      else if(v[i][j]=='E') {end = mp(i,j);w[i][j] = 1;}
      else w[i][j] = v[i][j]-'0'; 
    }
  }

  queue<pair<int,int> > q;
  q.push(end);
  vis[end.fi][end.se] = 1;
  q.push(mp(-1,-1));
  int count = 0;
  // int counter = 0;
  while(!q.empty())
  {
    pair<int,int> p = q.front();
    int i = p.fi, j = p.se;
    q.pop();
    if(i==-1 && j==-1 && q.empty()) break;
    else if(i==-1 && j==-1) {count++;q.push(mp(-1,-1));continue;}
    
    // counter++;
    // t(i,j);
    // vis[i][j] = 1;

    if(w[i][j]==-1) {x[i][j] = INF;continue;}

    x[i][j] = count;
    int dx[4] = {1,-1,0,0};
    int dy[4]= {0,0,1,-1};

    for(int h=0;h<4;h++)
    {
      int a = i+dx[h], b = j+dy[h];
      if(check(a,b,n,m) && !vis[a][b]) {q.push(mp(a,b)); vis[a][b] = 1;}
    }
  }

  int starter = x[start.fi][start.se];

  int ans = 0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(mp(i,j)==start || mp(i,j)==end) continue;
      if(x[i][j]<=starter) ans+=w[i][j];
    }
  }

  cout<<ans<<endl;
  return 0;
}

