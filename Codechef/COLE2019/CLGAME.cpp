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
#define vi vector<int>
#define vll vector<long long int>
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
    int n,k;
    cin>>n>>k;
    vector<int> v(n), w(k);
    for(int i=0;i<n;i++) cin>>v[i];
    reverse(v.begin(),v.end());

    int max1 = -1, index = -1;
    for(int i=0;i<v.size();i++) max1 = max(max1, v[i]);
    for(int i=0;i<v.size();i++) if(v[i]==max1) {index = i;break;}
    
    for(int i=0;i<k;i++) cin>>w[i];
    
    vector<bool> dp(n);
    for(int i=0;i<n;i++) dp[i] = false;
    dp[index] = true;
    for(int i=index+1;i<v.size();i++)
    {
      bool boo = 1;
      for(int j=0;j<w.size();j++)
      {
        if(i>=w[j]) 
        {
          // if(i-w[j]<index) dp[i] = true;
          boo&=dp[i-w[j]];
        }
      }
      // t(boo,i);
      if(!boo) dp[i] = 1;
    }
    if(dp[n-1]) cout<<"Chef"<<endl;
    else cout<<"Garry"<<endl;
  }
  return 0;
}

