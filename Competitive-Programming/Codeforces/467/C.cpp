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

int main()
{
  ld k,d,t;
  scld(k);scld(d);scld(t);
  if(d>=k)
  {
    // cout<<(((d)/(k+d))*(2*t))<<endl;
    ll c = ((2*t)/(k+d))*(k+d);
    ll count = 0;
    count+=c*d;
    if(count!=2*t)
    {
      if(count-2*t<=2*k) count+= (count-2*t)/2;
      else {count+=k;count+=(d-(count-2*t-k));}
    }
    cout<<count<<endl;
  }
  else
  {
    if((ll)k%(ll)d!=0)d = (k/d)*d + d;
    else d = k;
    cout<<"d: "<<d<<endl;
    ll c = ((2*t)/(k+d))*(k+d);
    cout<<"c: "<<c<<endl;
    ll count = 0;
    count+=c*d;
    if(count!=2*t)
    {
      if(count-2*t<=2*k) count+= (count-2*t)/2;
      else {count+=k;count+=(d-(count-2*t-k));}
    }
    cout<<count<<endl;
  }
  return 0;
}
