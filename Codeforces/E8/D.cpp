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
template<class A, class B> ostream& operator<<(ostream& out, const pair<A, B> &a){ return out<<"("<<a.first<<", "<<a.second<<")";}
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; for (int i = 0; i < v.size(); ++i) { if(v[i]!=INF) os << v[i]; else os << "INF";if (i != v.size() - 1) os << ", "; } os << "]\n"; return os; } 

ll dp1[2010][2][2010] = {0};
ll dp2[2010][2][2010] = {0};

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
  int m,d;
  cin>>m>>d;
  string a,b;
  cin>>a>>b;
  
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  vector<int> w(2000);
  for(int i=0;i<2000;i++) w[i] = power(i,10,m);

  // bool tight1 = false, tight2 = false;
  
  for(int i=0;i<10;i++) if(i!=d) dp1[0][0][i%m] = ++dp2[0][0][i%m];
  for(int i=0;i<=a[0]-'0';i++) if(i!=d) dp1[0][1][i%m]++;
  for(int i=0;i<=b[0]-'0';i++) if(i!=d) dp2[0][1][i%m]++;

  

  for(int i=1;i<max((int)a.size(),(int)b.size());i++)
  {
    for(int j=0;j<m;j++)
    {
      for(int k=0;k<=9;k++)
      {
        if(i%2==0 && k!=d) continue;
        if(i%2==1 && k==d) continue;

        int c = (j-(w[i]*k)%m+m)%m;

        if(i<a.size() && k==a[i]-'0')
        {
          dp1[i][1][j] += dp1[i-1][1][c] + dp1[i][0][j];
          dp1[i][1][j]%=MOD;
        }

        if(i<b.size() && k==b[i]-'0')
        {
          dp2[i][1][j] += dp2[i-1][1][c] + dp2[i][0][j];
          dp2[i][1][j]%=MOD;
        }

        dp1[i][0][j]  += dp1[i-1][0][c];
        if(dp1[i][0][j]>=MOD) dp1[i][0][j]-=MOD;

        dp2[i][0][j]  += dp2[i-1][0][c];
        if(dp2[i][0][j]>=MOD) dp2[i][0][j]-=MOD;

      }
    }
  }

  for(int i=0;i<a.size();i++)
  {
    for(int j=0;j<m;j++) 
    {
      t(i,j,dp1[i][0][j],dp1[i][1][j]);
    }
  }

  cout<<"\n";

  for(int i=0;i<a.size();i++)
  {
    for(int j=0;j<m;j++) 
    {
      t(i,j,dp2[i][0][j],dp2[i][1][j]);
    }
  }

  return 0;
}

