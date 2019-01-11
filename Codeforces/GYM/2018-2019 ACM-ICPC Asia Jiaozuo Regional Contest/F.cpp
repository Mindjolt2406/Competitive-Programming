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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

const int MAXN = 6300;
char v[MAXN][MAXN];
int visited[MAXN*MAXN];

void addEdge(vector<int>*adj,int u,int v)
{
  adj[u].pu(v);
  // adj[v].pu(u);
}

int bfs(vector<int>*adj,int source,int target,int n)
{
  queue<int> q;
  q.push(source);
  q.push(-1);
  int count = 1;
  int boo = 1;
  // int*visited = (int*)calloc(n,sizeof(int));
  while(!q.empty())
  {
    int u = q.front();
    q.pop();
    t(u,boo);
    if(u==-1 && boo) {count++;q.push(-1);boo = 0;continue;}
    else if(!boo && u==-1) break;
    boo = 1;
    if(u==target) return count;
    visited[u] = 1;
    // t(u);
    for(int i=0;i<adj[u].size();i++)
    {
      if(!visited[adj[u][i]]) q.push(adj[u][i]);
    }
  }
  // free(visited);
  return -1;
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,m;
    sc(n);sc(m);
    vector<int>*adj = new vector<int>[n*m+1];
    int** mat = new int*[n];
    for(int i=0;i<n;i++) mat[i] = new int[m];
    int count = 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {mat[i][j] = count;count++;visited[count] = 0;}
    // vector<string> v;
    int  source ,target;
    getchar();
    // v.resize(4*n+3);
    // for(int i=0;i<)
    // for(int i=0;i<v.size();i++) v[i].resize(6*m+6);
    for(int i=0;i<4*n+3;i++)
    {
      // char str[6*m+6];
      fgets(v[i],6*m+6,stdin);
    }
    // if(n==3 && m==4) cout<<7<<endl;
    // else cout<<-1<<endl;
    // continue;
    // for(int i=0;i<v.size();i++) cout<<v[i]<<endl;

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        int a,b;
        a = 4*i+2;
        b = 6*j+4;

        if(j%2==1) a+=2;
        if(v[a][b]=='S') source = mat[i][j];
        else if(v[a][b]=='T') target = mat[i][j];
        if(j%2==1)
        {
          if(i>0)
          {
            // Up
            if(v[a-2][b]!='-')
            {
              addEdge(adj,mat[i][j],mat[i-1][j]);
            }
          }
          if(i<n-1)
          {
            // Down
            if(v[a+2][b]!='-')
            {
              addEdge(adj,mat[i][j],mat[i+1][j]);
            }
          }
          if(j>0)
          {
            if(v[a-1][b-3]==' ') addEdge(adj,mat[i][j],mat[i][j-1]);
            // Left
          }
          if(j<m-1)
          {
            if(v[a-1][b+3]==' ') addEdge(adj,mat[i][j],mat[i][j+1]);
            // Right
          }
          if(j>0 && i<n-1)
          {
            if(v[a+1][b-3]==' ') addEdge(adj,mat[i][j],mat[i+1][j-1]);
            // Left down
          }
          if(i<n-1 && j<m-1)
          {
            if(v[a+1][b+3]==' ') addEdge(adj,mat[i][j],mat[i+1][j+1]);
            // Right down
          }
        }
        else
        {
          if(i>0)
          {
            // Up
            if(v[a-2][b]!='-')
            {
              addEdge(adj,mat[i][j],mat[i-1][j]);
            }
          }
          if(i<n-1)
          {
            // Down
            if(v[a+2][b]!='-')
            {
              addEdge(adj,mat[i][j],mat[i+1][j]);
            }
          }
          if(j>0)
          {
            if(v[a+1][b-3]==' ') addEdge(adj,mat[i][j],mat[i][j-1]);
            // Left
          }
          if(j<m-1)
          {
            if(v[a+1][b+3]==' ') addEdge(adj,mat[i][j],mat[i][j+1]);
            // Right
          }
          if(j>0 && i>0)
          {
            if(v[a-1][b-3]==' ') addEdge(adj,mat[i][j],mat[i-1][j-1]);
            // Left up
          }
          if(i>0 && j<m-1)
          {
            if(v[a-1][b+3]==' ') addEdge(adj,mat[i][j],mat[i-1][j+1]);
            // Right up
          }
        }
      }
    }

    // for(int i=0;i<n*m;i++)
    // {
    //   cout<<i<<": ";
    //   for(auto v:adj[i])
    //   {
    //     cout<<v<<" ";
    //   }
    //   cout<<endl;
    // }
    // if (n==3 && m==4) cout<<7<<endl;
    // else cout<<-1<<endl;
    printf("%d\n",bfs(adj,source,target,n*m));
    
  }
  return 0;
}

