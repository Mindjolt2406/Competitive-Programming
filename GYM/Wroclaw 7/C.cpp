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
#define sc(n) scanf("%d",&n)
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int n;
  while(sc(n)!=EOF)
  {
    int**l = new int*[n];
    long long int k = n;
    for(long long int i=0;i<n;i++) l[i] = new int[n];
    long long int beg = 0,mid = 0,end = 0;
    vector<int> ans;
    for(long long int i=0;i<n;i++) {for(long long int j=0;j<n;j++) sc(l[i][j]);sort(l[i],l[i]+n);}
    // for(long long inti=0;i<n;i++) {for(long long intj=0;j<n;j++) cout<<l[i][j]<<" ";cout<<endl;}
    for(long long int i=0;i<n;i++)
    {
      for(long long int j=1;j<n;j++)
      {
        l[i][j]-=l[i][0];
      }
    }
    // for(long long inti=0;i<n;i++) {for(long long intj=0;j<n;j++) cout<<l[i][j]<<" ";cout<<endl;}
    vector<int> v;
    long long int sum1 = 0;
    for(long long int i=0;i<n;i++) sum1+=l[i][0];
    for(long long int i=0;i<n;i++) 
    {
      for(long long int j=1;j<n;j++)
      {
        v.pu(l[i][j]);
      }
    }
    sort(v.begin(),v.end());
    // for(long long inti=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
    // vector<int> ans;
    ans.pu(sum1);
    for(long long int i=0;i<k-1;i++) ans.pu(sum1+v[i]);
    for(long long int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
  }
  return 0;
}
