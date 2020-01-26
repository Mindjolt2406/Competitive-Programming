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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

ll dp[1001][1001] = {0};
//Initialise array elements with zero
ll nCr(int n, int r)
{
  if(n==r) return dp[n][r] = 1; //Base Case
  if(r==0) return dp[n][r] = 1; //Base Case
  if(r==1) return dp[n][r] = n;
  if(dp[n][r]) return dp[n][r]; // Using Subproblem Result
  return dp[n][r] = (nCr(n-1,r) + nCr(n-1,r-1))%MOD;
}

int main()
{
  int t;
  sc(t);
  // for(int i=0;i<1001;i++) for(int j=0;j<1001;j++) dp[i][j] = 0;
  while(t--)
  {
    int n;
    sc(n);
    int*l = new int[n];
    map<int,int> d;
    map<int,int> :: iterator it;
    ll sum1 = 0;
    ll count = 0;
    for(int i=0;i<n;i++) 
    {
      sc(l[i]);
      if(d.find(l[i])!=d.end()) d[l[i]]++;
      else d[l[i]] = 1;
    }
    vector<ll> vd,vl,vr;
    vector<ll> pref,prefalt;
    for(int i=0;i<n;i++) {pref.pu(nCr(n,i);prefalt.pu(nCr(n,i)));}
    for(int i=1;i<n;i++) 
    {
      pref[i]+=pref[i-1];
      pref[i]%=MOD;
    }
    for(int i=2;i<n;i+=2) 
    {
      prefalt[i]+=prefalt[i-2];
      pref[i]%=MOD;
    }
    if(pref.size()>=2)count = pref[1];
    for(int i=3;i<n;i+=2) 
    {
      prefalt[i]+=prefalt[i-2];
      prefalt[i]%=MOD;
      count+=prefalt[i];
      count%=MOD;
    }
    for(it=d.begin();it!=d.end();it++)
    {
      vd.pu(it->fi);
      vl.pu(sum1);
      vr.pu(n-it->se-sum1);
    }
    for(int i=0;i<vd.size();i++)
    {
      ll c = (vd[i]*(vd[i]-1))/2;
      c%=MOD;
      int a = vl[i],b = vr[i];
      ll count1 = 0;
      for(int j=0;j<=k-2;j++)
      {
        a = vl[i]+j, b = vr[i]+(i-2-j);
        int a1 = min(a,b);
        count1+=pref[a];
      }
      count+= (c*count1)%MOD;
    }
    cout<<count<<endl;
  }
  return 0;
}

