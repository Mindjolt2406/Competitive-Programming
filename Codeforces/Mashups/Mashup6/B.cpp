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
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  int n,l,k;
  cin>>n>>l>>k;
  k = min(l/n,k);
  vector<vector<int> > dp(n,vector<int>(k+1));
  vector<int> a(n),pref(k+1);
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++) dp[i][1] = 1;  
  for(int i=0;i<n;i++)
  {
    pref[1]++;
    for(int j=2;j<=k;j++)
    {
      t(i,j);
      pr(pref);
      dp[i][j] += pref[j-1];
      dp[i][j]%=MOD;
      pref[j]+=dp[i][j];
      pref[j]%=MOD;
      // for(int k1=0;k1<=i;k1++) dp[i][j]+=dp[k1][j-1];
      pr(pref);
    }
  }
  ll sum1 = 0;
  for(int i=0;i<n;i++) for(int j=1;j<=k;j++) {sum1+=dp[i][j]; sum1%=MOD;}
  cout<<sum1<<endl;

  
  // for(int i=0;i<n;i++) pr(dp[i]);
  for(int i=0;i<n;i++)
  {
    for(int j=1;j<=k;j++) cout<<dp[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}

/*
3 9 3
5 9 1

*/