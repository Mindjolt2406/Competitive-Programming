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

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<ll> dp(1023,0);

    for(int i=0;i<n;i++)
    {
      int a = v[i];
      string t = to_string(v[i]);
      int counter[10] = {0};
      for(int j=0;j<t.size();j++) counter[t[j]-'0'] = 1;
      // Calculate the mask values
      int mask = 0,prod = 1;
      for(int j=0;j<10;j++)
      { 
        if(counter[j]) mask+=prod;
        prod+=prod;
      }
      dp[mask] = max(dp[mask],a);
      // t(a,mask,dp[mask]);
    }

    for(int i=0;i<1024;i++)
    {
      for(int j=0;j<1024;j++)
      {
        if((i|j) == i) // If j is a subset of i
        {
          // Complement of j, since j is a subset of i
          int j2 = i-j; 
          // t(i,j,j2,dp[i],dp[j],dp[j2]);
          if(j2>=0) dp[i] = max(dp[i],dp[j]+dp[j2]);
        }
      }
    }

    cout<<dp[1023]<<endl;
    dp.clear();
  }
  return 0;
}

/*
1
4
3 5 7 2

1
3
10 101 111

*/
