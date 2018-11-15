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
  int max1 = -1;
  for(int i=0;i<n;i++) max1 = max(max1,l[i]);
  int boo = 0;
  for(int i=0;i<n;i++)
  {
    if(l[i]!=max1) boo = 1;
  }
  if(!boo)
  {
    int boo1 = 0;
    for(int i=0;i<n;i++) if(l[i]!=0) {boo1 = 1;break;}
    if(boo1) {cout<<"NO"<<endl;return 0;}
    else
    {
      cout<<"YES"<<endl;
      for(int i=0;i<n;i++) cout<<max1+1<<" ";cout<<endl;
      return 0;
    }
  }

  else cout<<"YES"<<endl;

  int index = -1;
  boo = 0;
  for(int i=1;i<n;i++)
  {
    if(l[i]==max1 && l[i-1]!=max1) {index = i;boo = 1;break;}
  }
  if(!boo)
  {
    if(l[0]==max1 && l[n-1]!=max1) {index = 0;}
  }
  vector<ll> v,v1;
  for(int i=index+1;i<n;i++) v.pu(l[i]);
  for(int i=0;i<=index;i++) v.pu(l[i]);
  for(int i=0;i<n;i++) v1.pu(0);
  ll sum1 = 0;
  if(n>1 && v[n-2]==0) v[n-2] = max1;
  for(int i=n-1;i>=0;i--)
  {
    sum1+=v[i];
    v1[i] += sum1;
  }
  // for(int i=0;i<n;i++) cout<<v1[i]<<" ";cout<<endl;
  vector<ll>v2;
  // cout<<"index: "<<index<<endl;
  for(int i=0;i<n;i++) v2.pu(0);
  for(int i=0;i<n;i++) v2[(i+index+1)%n] = v1[i];
  for(int i=0;i<n;i++) cout<<v2[i]<<" ";cout<<endl;
  return 0;
}
