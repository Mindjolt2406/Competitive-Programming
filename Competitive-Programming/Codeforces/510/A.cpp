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
  int k;
  sc(k);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  ll sum1 = 0;
  int max1 = -1,min1 =INF;
  for(int i=0;i<n;i++)
  {
    sum1+=l[i];
    max1= max(max1,l[i]);
    // min1 = min(min1,l[i]);
  }
  int c = -1;
  if((n)*max1>=sum1+k)
  {
    c = max1;
  }
  else
  {
    if((sum1+k -max1*n)%n==0) c = (sum1+k-max1*(n))/n + max1;
    else c = (sum1+k-max1*(n))/n + max1 + 1;
  }
  cout<<c<<" "<<max1+k<<endl;
  return 0;
}
