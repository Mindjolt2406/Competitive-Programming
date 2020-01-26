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

template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<" "<<a.second<<")";}


ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  __;
  int n,q;
  cin>>n>>q;
  vector<ll> v(n);
  vector<ll> c(n);
  for(int i=0;i<n;i++) cin>>v[i];
  for(int i=0;i<n;i++) cin>>c[i];

  while(q--)
  {
    ll a,b;
    cin>>a>>b;
    vector<ll> dp(1e5+1);
    pair<ll,ll> max1 = mp(0,0),max2 = mp(0,0);
    set<pair<ll,ll> > s;
    s.insert(max1);

    for(int i=0;i<n;i++)
    {
      int col = c[i];
      ll val = v[i];

      ll val1 = 0, val2 = 0;

      if(s.size()==1) 
      {
        max1 = max2 = *s.rbegin();
      }
      else
      {
        max1 = *s.rbegin();
        max2 = *s.begin(); // Only 2 elements in this set
      }
      // Add behind max1
      if(max1.se==col) 
      {
        val1 = max1.fi + a*v[i];       
      }
      else
      {
        val1 = max1.fi + b*v[i];
      }

      // Add behind max2
      if(max2.se== col)
      {
        val2 = max2.fi + a*v[i];
      }
      else
      {
        val2 = max2.fi + b*v[i];
      }

      if(dp[c[i]]!=0) dp[c[i]] = max(dp[c[i]],dp[c[i]]+ v[i]*a);
      dp[c[i]] = max(max(dp[c[i]],val1),val2);
      s.insert(mp(dp[c[i]],c[i]));
      
      set<pair<ll,ll> > temp;
      set<int> t;
      for(auto it = s.rbegin();it!=s.rend();it++)
      {
        int k = t.size();
        t.insert(it->se);
        if(k!=t.size()) temp.insert(*it);
        if(t.size()==2) break; 
      }

      s = temp;
    }


    ll ans = 0;
    for(int i=0;i<1e5+1;i++) ans = max(ans,dp[i]);
    cout<<ans<<endl;
  }
  return 0;
}

