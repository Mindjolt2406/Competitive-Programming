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

using namespace std;

ll gcd(ll a, ll b) 
{ 
  if (a == 0) 
    return b; 
  return gcd(b % a, a); 
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    ll p,q,b;
    scll(p);scll(q);scll(b);
    if(p==0) {cout<<"Finite"<<endl;continue;}
    ll g = gcd(p,q);
    // cout<<"p: "<<p<<"q: "<<q<<" g: "<<g<<endl;
    p/=g;q/=g;
    int boo = 1;
    ll a = -1;
    while(b>1)
    {
      g = gcd(b,q);
      while(q%g==0 && g!=1 && q!=1) {q/=g;}
      b = g;
      if(q==1) break;
      else if(g==1 || a==b)
      {
        cout<<"Infinite"<<endl;
        boo  = 0;
        break;
      }
      a = b;
    }
    if(!boo) continue;
    cout<<"Finite"<<endl;
  }
  return 0;
}

