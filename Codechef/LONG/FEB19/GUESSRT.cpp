#include<bits/stdc++.h>
#define mt make_tuple
// #define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 1000000007
#define mp(x,y) {((x)*power((y),MOD-2,MOD))%MOD}
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
#define t3(x, y, z)          cerr<<#x<<" : " <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define t6(a,b,c,d,e,f)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<" "<<#f<<" : "<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t6,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;
#define __ {ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}


using namespace std;

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

void multiply(ll **l,ll **m,ll **arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                arr[i][j]+=(l[i][k]*m[k][j])%MOD;
                arr[i][j]%=MOD;
            }
        }
    }
}

void zero(ll **l, int n)
{
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) l[i][j] = 0;
}

void copy(ll **arr,ll **m,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            m[i][j] = arr[i][j];
        }
    }
    zero(arr,n);
}


void pow(ll **l,int n,ll y)
{
    y--; // Idk y it's needed 
    // m stores l^(2^k)) 
    ll **m = new ll*[n];
    for(int i=0;i<n;i++) m[i] = new ll [n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) m[i][j] = l[i][j];
    ll **arr = new ll *[n];
    for(int i=0;i<n;i++) arr[i] = new ll[n];
    zero(arr,n);
    while(y)
    {
        if(y&1)
        {
            multiply(l,m,arr,n);
            copy(arr,l,n);
        }

        multiply(m,m,arr,n);
        copy(arr,m,n);
        y>>=1;
    }
}

int main()
{
  __;
  int t;
  cin>>t;
  while(t--)
  {
    ll **l = new ll*[3];
    for(int i=0;i<3;i++) l[i] = new ll[3];
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) l[i][j] = 0;
    int n,k,m;
    cin>>n>>k>>m;
    // mp(a,b) is just finding ab-1 
    // The 3x3 matrix is 
    // [0, a1, 1]
    // [1, 0, 0]
    // [0, 0, 1]

    // The recurrence is f(i) = f(i-2)*a1 + c
    // If you multiply it with the transpose of [f(i-1), f(i-2), c] where c = 1/n you get f(i)
    // So, we need l^(m-2), cuz the other 2 we get by multiplying the column vector
    // For all practical purposes, k1 = n. (Initially I thought n>k)
    int k1 = n%k;
    ll a = mp(1,k1);
    ll z;
    ll a1 = mp(k1-1,k1),b1 = mp(1,1), c1 = mp(1,k),d1 = mp(1,n+k),e1 = mp(1,n);
    ll a2 = mp(n-1,n);
    l[0][1] = a1;
    l[0][2] = 1;
    l[1][0] = 1;
    l[2][2] = 1;

    // A bunch of varialbes
    ll f2,f1;
    f1 = e1; // Base case for 1
    ll temp1 = mp(n-1,n);
    ll temp2 = mp(1,n);
    ll temp3 = (temp1*d1)%MOD;
    z = (temp2+temp3)%MOD;
    f2 = z; // Base case for 2
    if(m==1) {z = e1;}
    else if(m==2) {z = f2;}
    else 
    {
      pow(l,3,m-2);
      z = ((l[0][0]*f2)%MOD + (l[0][1]*f1)%MOD + (l[0][2]*a)%MOD)%MOD;
    }
    ll ans = z; 
    cout<<ans<<endl;
  }

  return 0;
}

/*
1 
2 5 

*/
