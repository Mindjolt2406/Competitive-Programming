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

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  int* count = (int*)calloc(100001,sizeof(int));
  int counter = 0;
  for(int i=0;i<n;i++)
  {
    if(count[l[i]]) count[l[i]]++
    sc(l[i]);count[l[i]]++;}
  int**dp = new int*[n];
  for(int i=0;i<n;i++) dp[i] = new int[2];
  for(int i=0;i<n;i++) {dp[i][0] = -1;dp[i][1] = -1;}
  sort(l,l+n);
  dp[n-1][1] = count[l[n-1]];
  dp[n-1][0] = 0;
  for(int i=n-2;i>=0;i--)
  {
    dp[i][1] =
  }
  return 0;
}
