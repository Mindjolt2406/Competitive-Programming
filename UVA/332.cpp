#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%.*Lf",&n);

using namespace std;

ll gcd(ll a, ll b)
{
    // while(a%2==0 && b%2==0) {a/=2;b/=2;}
    // while(a%5==0 && b%5==0) {a/=5;b/=5;}
    // cout<<a<<" "<<b<<endl;
    // // Everything divides 0
    // if (a == 0 || b == 0)
    //    return 0;
    // if (a == b)
    //     return a;
    // if (a > b)
    //     return gcd(a%b, b);
    // return gcd(a, b-a);
    while(b)
    {
      // cout<<a<<" "<<b<<endl;
      ll c = a%b;
      a = b;
      b = c;
    }
    return a;
}
ld pow1(int a, int b)
{
  ld prod = 1;
  while(b)
  {
    prod*=10;
    b--;
  }
  return prod;
}

int main()
{
  int n;
  sc(n);
  int t = 1;
  while(n!=-1)
  {
    // ld k;
    // cin>>fixed>>setw(15)>>setprecision(15)>>k;
    // cout<<k<<endl;
    // stringstream temp;
    // temp << k;
    // string s = temp.str();
    // cout<<s<<endl;
    string s;
    cin>>s;
    ld k = stold(s);
    // if(k==0) {printf("Case %d: 0\n",t);t++;sc(n);continue;}
    // cout<<k<<" "<<s.size()-2-n<<endl;
    // cout<<pow(10,s.size()-2-n)*k<<endl;
    // cout<<pow(10,s.size()-2)*k<<" "<<(int)(pow(10,s.size()-2-n)*k)<<endl;
    // cout<<(pow1(10,s.size()-2-n)*k)<<" "<<(ll)(pow1(10,s.size()-2-n)*k)<<" "<<((ll)(pow1(10,s.size()-2)*k))<<" "<<(pow1(10,s.size()-2)*k)<<endl;
    // cout<<(pow1(10,s.size()-2))<<" "<<(pow1(10,s.size()-2)*k)<<" "<<(long long )(pow1(10,s.size()-2)*k)<<endl;
    ld try1 =   (pow1(10,s.size()-2)*k);
    try1 = round(try1);
    // cout<<"try1: "<<try1<<endl;
    ll c = (try1 - ((ll)(pow1(10,s.size()-2-n)*k)));
    ll d = (ll)(pow1(10,s.size()-2) - pow1(10,s.size()-2-n));
    // cout<<c<<" "<<d<<endl;
    ll e = gcd(max(c,d),min(c,d));
    // cout<<"e: "<<e<<endl;
    // cout<<"try12: "<<try1<<endl;
    if(e==0 || c==0 || d==0) {c = try1;d = pow1(10,s.size()-2);e = gcd(c,d);}
    c/=e;d/=e;
    // cout<<c<<" "<<d<<endl;
    // if(d==1) printf("Case %d: 1\n",t);
    if(c==0) printf("Case %d: %lld/%d\n",t,c,1);
    else printf("Case %d: %lld/%lld\n",t,c,d);
    t++;
    sc(n);
  }
  return 0;
}
