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
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

int main()
{
  __;
  int t;
  cin>>t;
  for(int h=1;h<=t;h++)
  {
    ll d,n;
    cin>>d>>n;
    ll k = pow(2,d);
    if(n==0) printf("Case %d: YES 0\n",h);
    else if(2*k-1<n) printf("Case %d: NO\n",h);
    else
    {
      vector<int> v(62);
      int i=0;
      while(n)
      {
        if(n&1) v[i] = 1;
        else v[i] = 0;
        n>>=1;
        i++; 
      }
      i=0;
      int prev3 = -1;
      while(k)
      {
        if(k&1) prev3 = i;
        k>>=1;
        i++; 
      }
      int prev = 0,boo = 0,prev2 = -1;;
      for(int i=0;i<62;i++)
      {
        if(v[i]==1 && prev2==-1) {prev2 = i;break;}
        // if(prev==0) prev = v[i];
        // else if(v[i]==1) {boo = 1;}
      }
      // t(prev3,prev2);
      int ans = prev3-prev2+1;
      printf("Case %d: YES %d\n",h,ans);
    }
  }
  return 0;
}

