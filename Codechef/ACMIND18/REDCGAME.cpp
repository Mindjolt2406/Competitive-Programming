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
    int n,k;
    sc(n);sc(k);
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    sort(l,l+n);
    vector<int> v;
    ll sum1 = 0,sum2=0;
    for(int i=0;i<n-1;i++) 
    {
      if(l[i]>k) {v.pu(l[i]-k);sum2+=k;}
      else sum2+=l[i];
    }
    for(int i=0;i<(int)v.size()-1;i++) sum1+=v[i];
    // cout<<"sum1: "<<sum1<<endl;
    int c=0;
    if(v.size()) 
    {
      if(sum1>=v[v.size()-1]) c = (sum1+v[v.size()-1])%2;
      else c = v[v.size()-1] - sum1;
      c = l[n-1]-c;
    }
    if(v.size())printf("%lld\n",sum2+c);
    else printf("%lld\n",sum2+l[n-1]);
  }
  return 0;
}

