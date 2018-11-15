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

ll max(ll x,ll y)
{
  if(x>y) return x;
  return y;
}

ll compute(vector<ll> v)
{
  if(v.size()==0) return 0;
  if(v.size()==1) return v[0];
  else if(v.size()==2) return max(v[0],v[1]);
  // cout<<v.size()<<endl;
  ll*dp = (ll*)calloc(v.size(),sizeof(ll));
  dp[0] = v[0];
  dp[1] = v[1];
  dp[2] = v[0]+v[2];
  // cout<<"here"<<endl;
  for(int i=3;i<v.size();i++)
  {
    dp[i] = max(dp[i-2],dp[i-3]) + v[i];
  }
  // for(int i=0;i<v.size();i++) cout<<dp[i]<<" ";cout<<endl;
  return max(dp[v.size()-1],dp[v.size()-2]);
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  ll* count1 = (ll*)calloc(100001,sizeof(ll));
  int counter = 0;
  for(int i=0;i<n;i++)
  {
    sc(l[i]);count1[l[i]]++;
  }
  // cout<<"here"<<endl;
  vector<ll> v;
  ll count = 0;
  for(int i=0;i<100001;i++)
  {
    if(count1[i]!=0) v.pu(count1[i]*i);
    else {count+=compute(v);v.clear();}
  }
  count+=compute(v);
  cout<<count<<endl;
  return 0;
}
