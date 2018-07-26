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

int bsearch1(int k,int*memo,int n)
{
  int beg = 1,end = k+1,max1 = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(memo[mid]<n) {max1 = max(max1,mid);beg = mid+1;}
    else if(memo[mid]>=n) {end = mid-1;}
  }
  return max1;
}

int main()
{
  int n,m;
  sc(n);sc(m);
  int *a = new int[n];
  int *b = new int[m];
  for(int i=0;i<n;i++) sc(a[i]);
  for(int i=0;i<m;i++) sc(b[i]);
  // int* other = new int[n];
  int* dp = new int[n];
  map<int,vector<int> > d;
  int* memo = new int[n+1];
  // int*prev = new int[n];
  for(int i=0;i<=n;i++) memo[i] = INF;
  for(int i=0;i<n;i++) dp[i] = -1;
  for(int i=0;i<m;i++) d[b[i]].pu(i); // Storing the indices of the second array in a map
  for(int i=0;i<n;i++)
  {
    int c = a[i];
    if(d.find(c)==d.end() || d[c].empty()) {dp[i] = 0;continue;}
    int dpvar,memovar;
    memovar = INF;
    for(int j=0;j<d[c].size();j++)
    {
      int c1 = d[c][j];
      // other[i] = c1;
      cout<<"c1: "<<c1<<endl;
      int c2 = bsearch1(i,memo,c1);
      cout<<"c2: "<<c2<<endl;
      if(c2==-1) {dpvar = 1;memovar = min(c1,memovar);}
      else {c2++;dpvar = max(dp[i],c2);if(dpvar==c2) memovar = c1;}
    }
    dp[i] = dpvar;
    memo[dpvar] = min(memovar,memo[dpvar]);
    for(int i=0;i<n;i++) cout<<dp[i]<<" ";cout<<endl;
    for(int i=1;i<n+1;i++) cout<<memo[i]<<" ";cout<<endl;
  }
  // int max1= -1;
  // for(int i=0;i<n;i++) if(dp[i]!=INF) max1 = max(max1,dp[i]);
  // vector<int> v;
  // for(int i=n-1;i>=0;i--)
  // {
  //   if(dp[i]==max1) {v.pu(a[i]);max1--;}
  //   if(max1==0) break;
  // }
  for(int i=1;i<=n;i++)
  {
    if(memo[i]!=INF) printf("%d ",a[i]);
    else break;
  }
  printf("\n");
  // for(int i=0;i<n;i++) cout<<dp[i]<<" ";cout<<endl;
  // for(int i=0;i<n+1;i++) cout<<memo[i]<<" ";cout<<endl;
  // for(int i=0;i<n;i++) cout<<other[i]<<" ";cout<<endl;
  // cout<<v.size()<<endl;
  // for(int i=v.size()-1;i>=0;i--) printf("%d ",v[i]);
  // printf("\n");
  // cout<<"here"<<endl;
  return 0;
}

/*
4 5
1 3 5 1
3 5 1 3 5

*/
