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
  int n,w,h;
  sc(n);sc(w);sc(h);
  vector<pair<int,int> > v;
  map<pair<int,int>,int > d;
  v.pu(mp(w,h));
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    if(a<=w || b<=h) continue;
    v.pu(mp(a,b));
    d[mp(a,b)] = i;
  }
  n = v.size();
  if(n==1) {cout<<0<<endl;return 0;}
  sort(v.begin(),v.end());
  int*dp = (int*)calloc(n,sizeof(int));
  int*back = new int[n+1];
  for(int i=0;i<n;i++) back[i] = -1;
  dp[0] = 0;
  // cout<<"c: "<<c<<endl;
  for(int i=1;i<n;i++)
  {
    int max1 = -1,index = -1;
    dp[i] = 0;
    // if(v[i].first>w && v[i].second>h) {dp[i] = 1;max1 = 1;back[i] = -1;boo = 1;}
    for(int j=0;j<i;j++)
    {
      if(dp[j]==-1) continue;
      if(v[j].first<v[i].first && v[j].second<v[i].second) if(dp[j]>max1) {max1 = dp[j];index = j;}
    }
    if(max1!=-1) dp[i] = max1+1;
    else dp[i] = -1;
    back[i] = index;
  }
  int max1 = 0,index = -1;
  for(int i=0;i<n;i++) if(dp[i]>max1){max1 = dp[i];index = i;}
  // cout<<"index: "<<index<<endl;
  printf("%d\n",max1);
  int i=index;
  vector<int> v1;
  while(i>=1 && dp[i]>=0)
  {
    // cout<<v[i].first<<" "<<v[i].second<<endl;
    v1.pu(d[v[i]]);
    // cout<<"i: "<<i<<" back: "<<back[i]<<endl;
    i = back[i];
  }
  reverse(v1.begin(),v1.end());
  for(int i=0;i<v1.size();i++) printf("%d ",v1[i]+1);
  printf("\n");
  // for(int i=0;i<n;i++) cout<<dp[i]<<" ";cout<<endl;
  // for(int i=0;i<n;i++) cout<<back[i]<<" ";cout<<endl;
  return 0;
}
