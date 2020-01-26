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
    vector<ld> p(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++) cin>>p[i];

    // vector<vector<ld> >  dp(n,vector<ld>(2));
    ld count = 0;

    int shift = 0;
    while(shift<=30)
    {
      // t(shift);
      vector<int> w(n);
      for(int i=0;i<n;i++) 
      {
        w[i] = v[i]>>shift;
        w[i]&=1;
      }

      vector<vector<ld> >  dp(n,vector<ld>(2));
      dp[0][0] = 1-p[0];
      dp[0][1] = p[0];

      if(!w[0]) 
      {
        dp[0][1] = 0;
        dp[0][0] = 1;
      }

      for(int i=1;i<n;i++)
      {
        if(w[i])
        {
          dp[i][1] = dp[i-1][1]*(1-p[i]) + dp[i-1][0]*p[i];
          dp[i][0] = 1-dp[i][1];
          // dp[i][0] = dp[i-1][1]*p[i] + (1-p[i]); // Wrong for some reason
          // 1 - dp[i-1][1] + dp[i-1][1]*p[i] - p[i]*dp[i-1][0];
          //  = 1 - (1-p[i])
        }
        else
        {
          dp[i][0] = dp[i-1][0];
          dp[i][1] = dp[i-1][1];
        }
        // t(shift,i,dp[i][0],dp[i][1]);
      }

      ld a = pow(2,shift);
      count+=(dp[n-1][1])*a;

      shift++;
      // for(int i=0;i<n;i++) t(i,dp[i][0],dp[i][1]);
    }

    cout<<setprecision(12);
    cout<<count<<endl;
  }
  return 0;
}

/*
2
3
5 6 2
1.0 0.0 0.5
4
2 2 2 2
0.5 0.5 0.5 0.5

1
3
5 6 2
1.0 0.0 0.5

*/