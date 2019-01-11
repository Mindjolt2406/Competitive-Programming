#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 3e18+1
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


ll f(ll n)
{
  int count = 0;
  while(n)
  {
    count+=n&1;
    if((n&1)==0) break;
    n>>=1;
  }
  // t(n,count);
  return pow(2,count);
}

ll min(ll x, ll y)
{
  if(x<y) return x;
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
    vector<ll> v(n);
    int odd = 0,even = 0;
    for(int i=0;i<v.size();i++) 
    {
      cin>>v[i];
      if(v[i]%2==1) odd++;
      else even++;
    }

    if(n%2==0) cout<<0<<endl;
    else
    {
      if(even!=0) cout<<1<<endl;
      else
      {
        ll min1 = INF;
        for(int i=0;i<v.size();i++)
        {
          ll a = f(v[i]);
          if(v[i]>a) min1 = min(min1,a);
        }
        if(min1==INF) cout<<-1<<endl; 
        else cout<<min1<<endl;
      }
    }
  }
  return 0;
}

