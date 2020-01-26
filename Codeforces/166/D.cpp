/*
Rathin Bhargava
IIIT Bangalore

*/
#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD1 (ll)100030001
#define MOD2 (ll)100050001
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

const int K1 = 147;
const int K2 = 153;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
    x = x % p;  // Update x if it is more than or
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int main()
{
  __;
  string s;
  cin>>s;
  string t;
  cin>>t;
  vector<int> check(26);
  for(int i=0;i<26;i++) 
  {
    if(t[i]=='0') check[i] = 1;
    else check[i] = 0;
  }
  int k;
  cin>>k;

  int n = s.size();
  int left = 0, right = 0;
  ll hash1 = s[right];
  ll hash2 = s[right];
  // map<ll,vector< pair<int,int> > > d;
  unordered_set<ll> d;

  int cnt = 0;
  while(right<n)
  {
    if(check[s[right]-'a']) cnt++;
    // t(left,right,cnt);
    if(cnt>k)
    {
      while(cnt>k)
      {
        // Increasing left
        ll a1 = power(K1,right-left,MOD1);
        ll a2 = power(K2,right-left,MOD2);
        a1*=s[left];
        a2*=s[left];
        hash1-=a1;
        hash2-=a2;
        hash1%=MOD1;
        hash2%=MOD2;
        hash1+=MOD1; hash1%=MOD1;
        hash2+=MOD2; hash2%=MOD2;
        cnt-=check[s[left]-'a'];
        left++;
      }
    }

    ll temp1 = hash1;
    ll temp2 = hash2;
    // All subarrays where i belongs to  [left,right] is a valid subarray
    for(int i=left;i<=right;i++)
    {
      // t(i,right,hash,temp);
      if(i==-1) continue;
      // d[temp].pu(mp(i,right));
      d.insert(temp1*1e9 + temp2);
      // t(temp1,temp2,i,left,right);
      ll a1 = power(K1,right-i,MOD1);
      ll a2 = power(K2,right-i,MOD2);
      a1*=s[i]; a1%=MOD1;
      a2*=s[i]; a2%=MOD2;
      temp1-=a1; temp2-=a2;
      temp1%=MOD1; temp1+=MOD1; temp1%=MOD1;
      temp2%=MOD2; temp2+=MOD2; temp2%=MOD2;
    }

    // t(d.size());
    right++; 
    if(right<n) 
    {
      hash1*=K1; hash2*=K2;
      hash1+=s[right]; hash2+=s[right];
      hash1%=MOD1; hash2%=MOD2;
    }
    // Increasing right
  }

  ll count = 0;

  cout<<d.size()<<endl;
  // t(d.size());
  // for(auto a : d) 
  // {
  //   vector<pair<int,int> > v = a.se;
  //   set<string> e;
  //   for(int i=0;i<v.size();i++) 
  //   {
  //     e.insert(s.substr(v[i].fi,v[i].se-v[i].fi+1));
  //     string s2 = s.substr(v[i].fi,v[i].se-v[i].fi+1);
  //     // t(v[i].fi,v[i].se,s2,a.fi);
  //   }
  //   // t(v.size(),e.size());
  //   count+=e.size();
  // }

  // cout<<count<<endl;
  // // t(d.size(),count);
  return 0;
}

