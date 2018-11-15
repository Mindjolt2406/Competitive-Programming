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
  for(int i=0;i<n;i++) sc(l[i]);
  sort(l,l+n);
  int boo = 0;
  for(int i=0;i<n;i++)
  {
    if(l[i]<0 && !boo){boo++;}
    else if(l[i]>=0 && boo==1){boo++;break;}
  }
  if(boo==0)
  {
    ll sum1 = 0;
    if(n==1) cout<<l[0]<<endl;
    else
    {
      sum1-=l[0];
      for(int i=1;i<n;i++) sum1+=l[i];
      cout<<sum1<<endl;
    }
  }
  else if(boo==1)
  {
    ll sum1 = 0;
    if(n==1)
    {
      cout<<l[0]<<endl;
    }
    else
    {
      sum1+=l[n-1];
      for(int i=0;i<n-1;i++)
      {
        sum1-=l[i];
      }
      cout<<sum1<<endl;
    }
  }
  else
  {
    ll sum1 = 0;
    for(int i=0;i<n;i++)
    {
      sum1+=abs(l[i]);
    }
    cout<<sum1<<endl;
  }
  return 0;
}
