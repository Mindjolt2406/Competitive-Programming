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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

vector<vector<int> > v(4000,vector<int>(4000));
vector<vector<int> > dp(4000,vector<int>(4000));


void make(int n)
{
  //Computes the 2D prefix sum
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==0 && j==0) continue;
      if(i==0) v[i][j]+=v[i][j-1];
      else if(j==0) v[i][j]+=v[i-1][j];
      else v[i][j]+= v[i-1][j] + v[i][j-1] - v[i-1][j-1];
    }
  }
}

int cost(int i,int j)
{
  // Cost for (i,j]
  return (v[j][j]+v[i][i]-v[i][j]-v[j][i])/2;
}

void compute(int i, int l, int r,int opt_l, int opt_r)
{
  if(l>r) return;
  int mid = (l+r)>>1;
  pair<int,int> best = mp(INF,0);
  for(int j=opt_l;j<=min(mid,opt_r);j++)
  {
    best = min(best,mp(dp[i-1][j]+ cost(j,mid),j));
  }
  if(best.fi==INF) best = mp(0,0);
  dp[i][mid] = best.fi;
  int opt = best.se;

  compute(i,l,mid-1,opt_l,opt);
  compute(i,mid+1,r,opt,opt_r);
}

int main()
{
  // __;
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++) 
  {
    for(int j=0;j<n;j++)
    {
      char c;
      c = getchar();
      while(c-'0'>9 || c-'0'<0) c = getchar();
      v[i][j] = c-'0'; 
    }
  }

  make(n);

  // Base case for DP
  for(int i=0;i<n;i++) dp[1][i] = v[i][i]/2;

  for(int i=2;i<=k;i++)
  {
    // For each i, compute the values of opt using divide and conquer
    compute(i,0,n-1,0,n-1);
  }
  // _;

  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     cout<<v[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  
  // for(int i=1;i<=k;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  cout<<dp[k][n-1]<<endl;
  return 0;
}

