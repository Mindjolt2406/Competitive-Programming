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
  ll*l = new ll[n];
  for(int i=0;i<n;i++) scll(l[i]);
  ll *m = new ll[5];
  for(int i=0;i<5;i++) scll(m[i]);
  ll*m1 = (ll*)calloc(5,sizeof(ll));
  ll count=  0;
  for(int i=0;i<n;i++)
  {
    count+=l[i];
    int j= 4;
    while(j>=0)
    {
      if(m[j]<=count)
      {
        m1[j]+= count/m[j];
        count-=(count/m[j])*m[j];
      }
      j--;
    }
  }
  for(int i=0;i<5;i++) cout<<m1[i]<<" ";cout<<endl;
  cout<<count<<endl;
  return 0;
}
