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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

const int N = 100;
vector<int> adj[N] = {};
int dp[N][4][3][2] = {0};

vector<vector<int> > dom(N,vector<int>(2)); // How many colours is the vertex u dominated by which occur in its own subtree? 
vector<vector<int> > undom(N,vector<int>(2)); // How many colours are in the open neighbourhood of u intersecting with its own subtree wuch that they don't dominate u?


void dfs(int u = 0,int p = -1)
{

  bool isLeaf = true;
  for(auto v : adj[u])
  {
    if(v-p)
    {
      dfs(v,u);
      isLeaf = false;
    }
  }

  if(isLeaf)
  {
    for(int i=0;i<4;i++)
    {
      for(int j=1;j<=3;j++)
      {
        for(int  k=0;k<2;k++)
        {
          if(i==0) dp[u][i][j][k] = 0;
          else dp[u][i][j][k] = 1;
        }
      }
    } 

    return;
  }

  for(int i=0;i<4;i++)
  {
    for(int j=1;j<=3;j++)
    {
      // k == 0
      
      // k == 1
    }
  }
  // We are free to change the colours of the subtrees to suit our needs, keeping in mind the number of colours used
  // Can vertex u be type 1?
  // That means if a colour appears in its children, it has to appear more than once
  // For this case we can assume all the children have the same colour

  // for(auto )


}

int main()
{
  __;
  int n;
  cin>>n;
  for(int i=0;i<n-1;i++)
  {
    int a,b;
    cin>>a>>b;
    adj[a].pu(b);
    adj[b].pu(a);
  }

  dfs();
  return 0;
}

