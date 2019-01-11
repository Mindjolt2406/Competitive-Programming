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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

pair<ll,ll> getdist(int i,ll z, vector<ll>&pref)
{
  ll a=0,b=0;
  int n = pref.size();
  if(i==0) 
  {
    b = pref[n-1]-(n*z);
  }
  else
  {
    a = z*i - pref[i-1];
    b = (pref[n-1] - pref[i-1]) - z*(n-i);
  }
  return mp(a,b);
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    swap(x,y);
    vector<ll> v(n),pref(n);
    ll max1 = -1;
    for(int i=0;i<n;i++) {cin>>v[i];max1 = max(max1,v[i]);} 
    sort(v.begin(),v.end());
    pref[0] =  v[0];
    for(int i=1;i<n;i++) pref[i]= pref[i-1] + v[i];

    // bsearch
    ll beg = 0,end = max1;
    ll min1 = INF;
    while(beg<=end)
    {
      ll mid = (beg+end)/2;
      vector<ll>::iterator it = upper_bound(v.begin(),v.end(),mid);
      int a = it - v.begin();
      pair<ll,ll> p = getdist(a,mid,pref);
      ll dist1 = p.fi,dist2 = p.se;
      ll profit = dist1*x - dist2*y;
      // t(dist1,dist2,mid,profit);
      if(profit>=0) 
      {
        min1 = profit;
        end = mid-1;
      } 
      else beg = mid+1;
    }
    cout<<min1<<endl;
  }
  return 0;
}

