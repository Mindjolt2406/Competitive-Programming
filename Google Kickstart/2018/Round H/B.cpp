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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

ll getsum(vector<ll> &v, int j,int i)
{
  if(j==-1) return v[i];
  return v[i]-v[j];
}

ll max(ll x, ll y)
{
  return x>y ? x : y;
}

int main()
{
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int n;
    sc(n);
    string s;
    cin>>s;
    vector<ll> v;
    v.assign(n,0);
    v[0] = s[0]-'0';
    for(int i=1;i<n;i++) v[i] = (s[i]-'0')+v[i-1];
    int k = n-n/2;
    int j=-1;
    ll max1 = -1;
    // t(k);
    for(int i=k-1;i<n;i++)
    {
      max1 = max(getsum(v,j,i),max1);
      j++;
    }
    printf("Case #%d: %lld\n",h,max1);
  }
  return 0;
}

