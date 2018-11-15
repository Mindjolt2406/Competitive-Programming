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
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll dp[10000001] = {0};

int bsearch1(vector<int> &v,int value)
{
  int beg = 0,end = (int)v.size()-1;
  int ans = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]>=value){end = mid-1;ans = mid;}
    else beg = mid+1;
  }
  return ans;
}

int bsearch2(vector<int> &v,int value)
{
  int beg = 0,end = (int)v.size()-1;
  int ans = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(v[mid]<=value){beg = mid+1;ans = mid;}
    else end = mid-1;
  }
  return ans;
}

ll recur(ll i)
{
  // t(i,dp[i]);
  if(i<=1000000 &&  dp[i]!=INF) return dp[i];
  // t(i,dp[i]);
  ll a = 0;
  if(i%2==0) a = recur(i/2)+1;
  else a = recur(3*i+1)+1;
  // t(i,dp[i]);
  // t(i);
  if(i<=1000000) dp[i] = a;
  return a;
}

int main()
{
  for(int i=0;i<1000001;i++) dp[i] = INF;
  dp[1] = 1;dp[2] = 2;dp[4] = 3; 
  for(int i=1;i<1000001;i++)
  {
    // t(i,dp[i]);
    if(dp[i]==INF) recur(i);
    // t(i,dp[i]);
  }
  t(dp[999999]);
  map<int,vector<int> > d;
  for(int i=1;i<1000001;i++)
  {
    d[dp[i]].pu(i);
  }
  int a,b;
  while(scanf("%d %d",&a,&b)!=EOF)
  {
    int c1 = a,d1 = b;
    pair<int,int> p = mp(min(a,b),max(a,b));
    a = p.fi; b = p.se;
    int max1 = -1;
    for(auto it: d)
    {
      int c = it.first;
      int a1 = bsearch1(it.second,a);
      int b1 = bsearch2(it.second,b);
      if(a1!=-1 && b1!=-1 && b1>=a1)
      {
        max1 = c;
      }
    }
    printf("%d %d %d\n",c1,d1,max1);
  }
  return 0;
}
