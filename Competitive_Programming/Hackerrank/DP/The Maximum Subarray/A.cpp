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
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    int *l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    int sum2 = 0;
    for(int i=0;i<n;i++) if(l[i]>0) sum2+=l[i];
    if(sum2==0)
    {
      int max1 = -1*INF;
      for(int i=0;i<n;i++) max1 = max(max1,l[i]);
      sum2 = max1;
    }
    for(int i=1;i<n;i++)
    {
      if(l[i]<l[i-1]+l[i]) l[i] = l[i-1]+l[i];
    }
    // for(int i=0;i<n;i++) cout<<l[i]<<" ";cout<<endl;
    int sum1 = -1*INF;
    for(int i=0;i<n;i++) sum1 = max(sum1,l[i]);
    printf("%d %d\n",sum1,sum2);
  }
  return 0;
}
