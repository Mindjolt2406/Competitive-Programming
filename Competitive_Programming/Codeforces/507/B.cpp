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
  k = 2*k+1;
  int count = ceil(n/(float)k);
  cout<<count<<endl;
  if(n%k<=k/2 && n%k>0)
  {
    for(int i=1;i<=n;i+=k)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
  else
  {
    for(int i=k/2+1;i<=n;i+=k)
    {
      cout<<i<<" ";
    }
    cout<<endl;
  }
  return 0;
}
