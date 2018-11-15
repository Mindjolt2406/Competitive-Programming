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
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

ll max1 = -1*INF;

int check(ll o,ll o1,ll d,ll sum1)
{
  // cout<<o<<" "<<o1<<" "<<d<<" "<<sum1<<endl;
  if(sum1<=d && o1<=o) return 1;
  return 0;
}

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    max1 = -1*INF;
    ll n,o,d;
    scll(n);scll(o);scll(d);
    vector<ll> v;
    ll x1,x2,a,b,c,m,l;
    scll(x1);scll(x2);scll(a);scll(b);scll(c);scll(m);scll(l);
    v.pu(x1);v.pu(x2);
    for(int i=2;i<n;i++) v.pu(((a*v[i-1])%m+(b*v[i-2])%m + c)%m);
    for(int i=0;i<v.size();i++) v[i]+=l;
    // for(int i=0;i<n;i++){ll a;scll(a);v.pu(a);}
    int left = 0,right = 0;
    ll sum1 = v[0],o1 = 0;
    if(v[0]%2) o1 = 1;
    // for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
    while(right<n && left<=right)
    {
      // cout<<"here"<<endl;
      while(right<n && check(o,o1,d,sum1))
      {
        // cout<<"left: "<<left<<" right: "<<right<<" o1: "<<o1<<" sum1: "<<sum1<<endl;
        max1 = max(max1,sum1);
        right++;
        if(v[right]%2) o1++;
        ll k = sum1;
        sum1+=v[right];
        // while(sum1<=d && left<right)
        // {
        //   if(v[left]%2) o1--;
        //   sum1-=v[left];
        //   left++;
        // }
        // if(k>sum1 && sum1<=0) break;
      }
      if(v[left]%2) o1--;
      sum1-=v[left];
      left++;
    }
    while(right==n && left<n)
    {
      if(check(o,o1,d,sum1)) {max1 = max(max1,sum1);}
      if(v[left]%2) o1--;
      sum1-=v[left];
      left++;
    }
    if(max1!=-1*INF) printf("Case #%d: %lld\n",h,max1);
    else printf("Case #%d: IMPOSSIBLE\n",h);
  }
  return 0;
}

/*
1
6 1 -100
1 1 1 1 0 100 0

*/
