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

// int getor(int a,int b)
// {
//   // a|x = b
//   if(b==0 && a!=0) return -1;
//   else if(b==0) return 0;
//   if(b==1 && (a==2||a==3)) return -1;
//   else if(b==1 && a==0) return 1;
//   else if(b==1) return 1;

// }

int main()
{
  int n;
  sc(n);
  // int dp[n][4];
  int a[n-1],b[n-1];
  for(int i=0;i<n-1;i++)sc(a[i]);
  for(int i=0;i<n-1;i++)sc(b[i]);
  for(int i=0;i<n-1;i++) if(b[i]>a[i] || (a[i]&b[i])!=b[i]) {cout<<"NO"<<endl;return 0;}
  // for(int i=0;i<n;i++) for(int j=0;j<4;j++) dp[i][j] = -1;
  int *l1 = new int[n];
  int *l2 = new int[n];
  l[0] = b[0];l[1] = a[0];l[n-1] = b[n-2];
  // l2[0] = a[0];l2[1] = b[0];l2[n-1] = b[n-2];
  if(l[i]&b[i]==b[i]) 
  cout<<"YES"<<endl;
  for(int i=0;i<n;i++) cout<<l[i]<<" ";cout<<endl;
  return 0;
}

