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
  ll count = 0;
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  sort(l,l+n);
  int c= n/2;
  if(k>=l[c])
  {
    for(;c<n;c++)
    {
      if(l[c]>k) break;
      count+=abs(l[c]-k);
    }
  }
  else
  {
    for(;c>=0;c--)
    {
      if(l[c]<k) break;
      count+=abs(l[c]-k);
    }
  }
  cout<<count<<endl;
  return 0;
}
