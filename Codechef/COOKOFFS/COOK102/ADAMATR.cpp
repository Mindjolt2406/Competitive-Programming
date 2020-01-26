/*
Rathin Bhargava
IIIT-Bangalore

*/
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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

const int N = 3e3;
vector<int> adj[N] = {};
vector<int> vis(N,-1);

int key = 1;

void dfs(int u,int p = -1)
{
  vis[u] = key;
  for(auto v : adj[u]) if(v-p && vis[v]!=key) dfs(v,u);
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    vector<vector<int> > v(n),w(n);
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        int a;
        cin>>a;
        v[i].pu(a);
      }
    }

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        int a;
        cin>>a;
        w[i].pu(a);
      }
    }

    vector<vector<int> > sw(n,vector<int>(n));
    int boo = 0;
    for(int i=0;i<n;i++)
    {
      if(v[i][i]!=w[i][i]) boo = 1;
    }
    
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(v[i][j]==v[j][i]) {sw[i][j] = sw[j][i] = -1; continue;}
        vector<int> a = {v[i][j],v[j][i]};
        vector<int> b = {w[i][j],w[j][i]};
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a[0]!=b[0] || a[1]!=b[1]) {boo = 1; break;}

        if(v[i][j]==w[i][j]) sw[i][j] = 0;
        else sw[i][j] = 1;
      }
      if(boo) break;
    }

    if(boo) {cout<<"No"<<endl;}
    else
    {
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(sw[i][j]==-1) continue;
          if(sw[i][j]) 
          {
            adj[2*i].pu(2*j+1);
            adj[2*j+1].pu(2*i);
            adj[2*j].pu(2*i+1);
            adj[2*i+1].pu(2*j);
          }
          else
          {
            adj[2*i].pu(2*j);
            adj[2*j].pu(2*i);
            adj[2*i+1].pu(2*j+1);
            adj[2*j+1].pu(2*i+1);
          }
        }
      }

      // for(int i=0;i<n;i++)
      // {
      //   for(int j=0;j<n;j++)
      //   {
      //     cout<<sw[i][j]<<" ";
      //   }
      //   cout<<endl;
      // }
      for(int i=0;i<2*n;i++)
      {
        if(vis[i]==-1) {dfs(i); key++;}
      }

      // for(int i=0;i<2*n;i++) cout<<vis[i]<<" "; cout<<endl;
      int boo = 0;
      for(int i=0;i<2*n;i+=2)
      {
        if(vis[i]==vis[i+1] && vis[i]!=-1) {boo = 1;break;}
      }

      if(boo) cout<<"No"<<endl;
      else cout<<"Yes"<<endl;
    }

    for(int i=0;i<vis.size();i++) vis[i] = 0;
    for(int i=0;i<N;i++) adj[i].clear();
  }
  return 0;
}

/*
2
3
1 2 3
4 5 6
7 8 9
1 2 7
4 5 8
3 6 9
3
1 4 6
5 2 8
7 9 3
1 5 6
4 2 8
7 9 3

*/
