/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define ll long long int
#define ld long double
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cerr<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

using namespace std;
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <int> ostream& operator<<(ostream& os, const vector<int>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { os << v[i]; ;if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll min(ll x, ll y)
{
  if(x<y) return x;
  return y;
}

int solve(ll a, ll b, ll h, ll w, vector<ll> &v, vector<ll>&w)
{
  vector<pair<ll,ll> > x,y;
  int min1 = INF;
  for(int i=0;i<pow(2,20);i++)
  {
    ll cnt1 = 1, cnt2 = 1,cnt3 = 1, cnt4 = 1;
    for(int j=0;j<20;j++)
    {
      if((i>>j)&1) // the jth bit is set
      {
        cnt1 *= v[i];
        cnt1 = min(cnt1,INF);

        cnt2 *= w[i];
        cnt2 = min(cnt2,INF);
      }
      else
      {
        cnt3 *= v[i];
        cnt3 = min(cnt3,INF);

        cnt4 *= w[i];
        cnt4 = min(cnt4,INF);
      }
    }

    x.pu(mp(mp(cnt1,cnt3)),i);
    y.pu(mp(mp(cnt2,cnt4)),i);
  }

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  // get min c s.t h*c >=a . Then fix a value in x and binary search for the corresponding value in y
  // Do the same for h*d >= b. 
  // Since they've been stored as pairs, once you get a right fit, check the value of w*x2*y2.
  // If both are satified, increase the count by 1
  

  for(int i=0;i<x.size();i++)
  {
    ll c = a/h, d = b/w;
    if(a%h!=0) c++;
    if(b%w!=0) d++;

    int beg = 0, end = y.size()-1;
    while(beg<=end)
    {
      int mid = (beg+end) >> 1;
      if(x[i].fi.fi*y[mid].fi.fi >= c)
      {
        end = mid-1;
        int mask = x[i].se;
        ll cnt = 1;
        vector<ll> vec;
        for(int j=0;j<20;j++)
        {
          if(!((mask>>j)&1)) vec.pu(w[j]);
        }
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());

        int cnter = __builtin_popcount(mask);

        for(int j=0;j<vec.size();j++) 
        {
          d/=vec[i];
          cnter++;g
          if(d==1) break;
        }

        min1 = min(min1,cnter);
      }
      else beg = mid+1;
    }

    c = b/h, d = a/w;
    if(b%h!=0) c++;
    if(a%w!=0) d++;
  }

  if(cnt == 0) return -1;
  return cnt;
} 

int main()
{
  __;
  ll a,b,h,w,n;
  cin >> a >> b >> h >> w >> n;
  if((h>=a && w>=b) || (h>=b && w>=a)) { cout << 0 << endl; return 0;}
  vector<ll> v(n);
  for(int i=0;i<n;i++) cin >> v[i];
  sort(v.begin(),v.end());
  reverse(v.begin(),v.end());

  vector<ll> a(20,1),b(20,1);
  for(int i=0;i<min(n/2,20);i++) a[i] = v[i];
  for(int i=min(n/2,20);i<min(n,40);i++) b[i-min(n/2,20)] = v[i];


  return 0;
}

