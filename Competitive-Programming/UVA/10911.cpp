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

ld min(ld x, ld y)
{
  if(x<y) {return x;}
  return y;
}

ld dist(vector<pair<ld,ld> > v,int i,int j)
{
  pair<ld,ld> p1 = v[i];
  pair<ld,ld> p2 = v[j];
  ld a = p1.first, b = p2.first, c = p1.second,d = p2.second;
  return sqrt(pow(a-b,2) + pow(c-d,2));
}

bool count(int i)
{
  int count = 0;
  while(i)
  {
    count+=(int) i&1;
    i >>=1;
  }
  // cout<<"count: "<<count<<endl;
  return count%2;
}

int main() 
{
  int n;
  sc(n);
  int counter = 1;
  while(n)
  {
    vector<pair<ld,ld> > v;
    vector<ld > dp;
    dp.assign((1<<2*n),INF);
    for(int i=0;i<2*n;i++)
    {
      ld a,b;
      string s;
      scr(s);
      scld(a);scld(b);
      v.pu(mp(a,b));
    }
    n*=2;
    dp[0] = 0;
    for(int i=0;i<(1<<n);i++)
    {
      // count the number of bits to check if they are even
      if(count(i)) continue;
      // for the ith and jth unset bits, get min and do
      for(int j=0;j<n;j++)
      {
        // If the jth bit is unset
        if((i&(1<<j))>>j == 0) 
        {
          for(int k=0;k<n;k++)
          {
            if((i&(1<<k))>>k == 0 && k!=j)
            {
              // set the jth and kth bits in i
              int mask = i|(1<<j);
              mask = mask|(1<<k);
              dp[mask] = min(dp[mask],dp[i]+dist(v,j,k));
            }
          }
        }
      }
    }
    printf("Case %d: %.2Lf\n",counter,dp[(1<<n)-1]);
    counter++;
    sc(n);
  }
  return 0;
}

/*
5
sohel 10 10
mahmud 20 10
sanny 5 5
prince 1 1
per 120 3
mf 6 6
kugel 50 60
joey 3 24
limon 6 9
manzoor 0 0
0

*/
