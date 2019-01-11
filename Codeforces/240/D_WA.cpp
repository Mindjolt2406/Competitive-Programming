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

ll ans = 0;
ll n,k;

int dp[4001][4001] = {0};
//Initialise array elements with zero
ll nCr(ll n,ll r)
{
  // t(n,r);
  if(r<0) return 0;
  if(n==r) return dp[n][r] = 1; //Base Case
  if(r==0) return dp[n][r] = 1; //Base Case
  // t(n,r);
  if(r==1) return dp[n][r] = n;
  if(dp[n][r]) return dp[n][r]; // Using Subproblem Result
  return dp[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%MOD;
}

// void dfs(vector<int>*adj,int*visited, int u,int depth)
// {
//   visited[u] = 1;
//   ll n1 = k-1;
//   ans+=nCr(n1+depth-1,depth-1);
//   t(k,n1,depth,ans,u);
//   for(int i=0;i<adj[u].size();i++)
//   {
//     if(!visited[adj[u][i]]) dfs(adj,visited,adj[u][i],depth+1);
//   }
// }

int main()
{
  scll(n);scll(k);
  if(k==1) {cout<<n<<endl; return 0;}
  ll *l = (ll*)calloc(n+1,sizeof(ll));
  for(int i=1;i<=n;i++)
  {
    for(int j=i+1;j<=n;j++)
    {
      if(j%i==0) l[j]++;
    }
  }

  ll ans = 0;
  for(int i=n;i>=1;i--)
  {
    if(k==2) 
    {
      ans+=l[i]+1;
      ans%=MOD;
      continue;
    }
    for(int j=i-1;j>=1;j--)
    {
      if(i%j!=0) continue;
      ll c = nCr(k-2+l[j]+1,l[j]+1);;
      ans+=c;
      ans%=MOD;
    }
    ans++;
    ans%=MOD;
  }

  // for(int i=1;i<=6;i++) cout<<l[i]<<" ";cout<<endl;
  // vector<int> *adj = new vector<int> [n+1];
  // for(int i=1;i<=n;i++)
  // {
  //   vector<int> v;
  //   for(int j=i+1;j<=n;j++)
  //   {
  //     if(j%i==0) v.pu(j);
  //   }
  //   if(!v.empty()) adj[i].pu()
  // }
  // int*visited = (int*)calloc(n,sizeof(int));
  // dfs(adj,visited,1,1);

  cout<<ans<<endl;
  return 0;
}

