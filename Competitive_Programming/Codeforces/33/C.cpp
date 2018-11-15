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
  int* pref = new int[n];
  int* suf = new int[n];
  pref[0] = l[0];
  suf[n-1] = l[n-1];
  for(int i=1;i<n;i++)
  {
    pref[i] =pref[i-1]+ l[i];
    suf[n-1-i] = suf[n-i]+l[n-1-i];
  }
  int max1 = -1*INF,max2 = -1*INF;
  int*dp1 = new int[n];
  int*dp2 = new int[n];
  dp1[0] = max(l[0]*(-1),l[0]);
  max1 = dp1[0];
  dp2[n-1] = max(l[n-1]*(-1),l[n-1]);
  max2 = dp2[n-1];
  int index1 = 0,index2 = n-1;
  for(int i=1;i<n;i++)
  {
    int max1a = max1+pref[i]-pref[index1];
    int boo = 0;
    if(max1a<pref[i]) {max1 = pref[i];index1 = i;boo = 1;}
    if(max1a<pref[i]*(-1)) {max1 = max(pref[i]*(-1),pref[i]);index1 = i;boo = 1;}
    if(boo)dp1[i] = max1;
    else dp1[i] = max1a;
  }
  for(int i=n-2;i>=0;i--)
  {
    int max2a = max2+suf[i]-suf[index2];
    int boo = 0;
    if(max2a<suf[i]) {max2 = suf[i];index2 = i;boo = 1;}
    if(max2a<suf[i]*(-1)) {max2 = max(suf[i],suf[i]*(-1));index2 = i;boo = 1;}
    if(boo) dp2[i] = max2;
    else dp2[i] = max2a;
  }
  int max3 = dp2[0];
  for(int i=0;i<n;i++)
  {
    if(i!=n-1) max3 = max(dp1[i]+dp2[i+1],max3);
    else max3 = max(max3,dp1[i]);
  }
  // for(int i=0;i<n;i++) cout<<dp1[i]<<" ";cout<<endl;
  // for(int i=0;i<n;i++) cout<<dp2[i]<<" ";cout<<endl;
  // for(int i=0;i<n;i++) cout<<pref[i]<<" ";cout<<endl;
  // for(int i=0;i<n;i++) cout<<suf[i]<<" ";cout<<endl;
  cout<<max3<<endl;
  return 0;
}
