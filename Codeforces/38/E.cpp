// Was stuck for sooo long just cuz (i-j)*v[i].fi was int*int. So, even if it were being typecsted to long long, a garbage value
// was given
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1e18+1
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
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll getsum(vector<ll> &w, int i,int j) // Gets sum from (i,j]
{
  return w[j]-w[i];
}

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int main()
{
  int n;
  sc(n);
  vector<pair<ll,ll> > v;
  vector<ll> w;
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    v.pu(mp(a,b));
  }
  // v.pu(mp(1e9+1,0));
  sort(v.begin(),v.end());
  for(int i=0;i<v.size();i++) w.pu(v[i].fi);
  for(int i=1;i<v.size();i++) w[i]+=w[i-1];
  // for(int i=0;i<w.size();i++) cout<<w[i]<<" ";cout<<endl;
  ll **dp = new ll*[n];
  for(int i=0;i<n;i++) dp[i] = new ll[2];
  for(int i=1;i<n;i++) {dp[i][0] = dp[i][1] = INF;}
  dp[0][1] = v[0].se;
  for(int i=1;i<v.size();i++)
  {
    for(int j=0;j<i;j++)
    {
      ll a = getsum(w,j,i);
      ll b = (i-j)*v[j].fi;
      ll c = a-b+v[i].se+dp[j][1]-(v[i].fi-v[j].fi);
      // t(a,b,i,j,c);
      dp[i][1] = min(dp[i][1],a-b+v[i].se+dp[j][1]-(v[i].fi-v[j].fi));
      dp[i][0] = min(dp[i][0],a-b+dp[j][1]);
    }
  }
  cout<<min(dp[n-1][0],dp[n-1][1])<<endl;

  // for(int i=0;i<n;i++) t(i,dp[i][0],dp[i][1],v[i].fi,v[i].se);
  return 0;
}

