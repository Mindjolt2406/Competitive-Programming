#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
// 9:32
using namespace std;

int gcd(int a,int b)
{
  while(b)
  {
    int c = a%b;
    a = b;
    b = c;
  }
  return a;
}
int main()
{
  int n;
  sc(n);
  while(n)
  {
    vector<int> v;
    for(int i=0;i<n;i++) {int a;sc(a);v.pu(a);}
    ld count = 0;
    for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
      {
        int c = gcd(max(v[i],v[j]),min(v[i],v[j]));
        if(c==1) count++;
      }
    }
    if(count==0) printf("No estimate for this data set.\n");
    else
    {
      ld c = sqrt((6*((n*(n-1))/2))/count);
      printf("%Lf\n",c);
    }
    sc(n);
  }
  return 0;
}
