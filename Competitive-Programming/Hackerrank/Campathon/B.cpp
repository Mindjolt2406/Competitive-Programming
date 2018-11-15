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
  int n,k;
  sc(n);sc(k);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int max1 = -1,a = -1,b = -1;
  for(int i=1;i<=k+1;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(j+i>=n) continue;
      // cout<<j<<" "<<j+i<<" "<<l[i]+l[i+j]<<" "<<l[i]<<" "<<l[j]<<endl;
      if(l[j]+l[j+i]>max1)
      {
        max1 = l[j]+l[j+i];
        a = j;b = j+i;
      }
    }
  }
  cout<<a<<" "<<b<<endl;
  return 0;
}
