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

void make(vector<ll> &v,int n)
{
  ll p1,p2,a1,b1,c1,m1;
  scll(p1);scll(p2);scll(a1);scll(b1);scll(c1);scll(m1);
  v.pu(p1);v.pu(p2);
  for(int i=2;i<n;i++) v.pu(((a1*v[i-1])%m1 + (b1*v[i-2])%m1 + c1)%m1 + 1);
}

int main()
{
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int n;sc(n);int k;sc(k);
    vector<ll> height,pos,x,y;
    make(pos,n);
    make(height,n);
    make(x,k);
    make(y,k);
    // for(int i=0;i<n;i++) cout<<height[i]<<" ";cout<<endl;
    // for(int i=0;i<n;i++) cout<<pos[i]<<" ";cout<<endl;
    // for(int i=0;i<k;i++) cout<<x[i]<<" ";cout<<endl;
    // for(int i=0;i<k;i++) cout<<y[i]<<" ";cout<<endl;
    ll count = 0;
    for(int i=0;i<k;i++)
    {
      ll x1 = x[i],y1 = y[i];
      int boo = 0;
      for(int j=0;j<n;j++)
      {
        if(pos[j]>x1)
        {
          if(height[j]-y1>=pos[j]-x1 && height[j]>=y1) {boo = 1;break;}
        }
        else if(pos[j]==x1)
        {
          if(height[j]>=y1) {boo = 1;break;}
        }
        else
        {
          if(height[j]-y1>=x1-pos[j] && height[j]>=y1) {boo = 1;break;}
        }
      }
      if(boo) count++;
    }
    printf("Case #%d: %lld\n",h,count);
  }
  return 0;
}
