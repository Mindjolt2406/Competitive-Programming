// Upsolved
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
  int n,m;
  sc(n);sc(m);
  int*l1 = new int[n];
  int*l2 = new int[m];
  for(int i=0;i<n;i++) sc(l1[i]);
  for(int i=0;i<m;i++) sc(l2[i]);
  int x1 = 0,x2 = 0;
  for(int i=0;i<n-1;i++) x1^=l1[i];
  x1^=l2[m-1];
  for(int i=0;i<m-1;i++) x2^=l2[i];
  x2^=l1[n-1];
  if(x1==x2)
  {
    printf("YES\n");
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<m-1;j++) printf("0 ");
      printf("%d\n",l1[i]);
    }
    for(int j=0;j<m-1;j++) printf("%d ",l2[j]);
    printf("%d\n",x1);
  }
  else printf("NO\n");
  return 0;
}
