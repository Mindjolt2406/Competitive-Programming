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

ll count1(ll *l)
{
  ll sum1 = 0;
  for(int i=0;i<14;i++) if(l[i]%2==0)sum1+=l[i];
  return sum1;
}

ll max(ll x, ll y)
{
  if(x>y) return x;
  return y;
}
int main()
{
  ll*l = new ll[14];
  for(int i=0;i<=13;i++) scll(l[i]);
  // for(int i=13;i>=7;i--) sc(l[i]);
  ll max1 = -1;
  for(int i=0;i<14;i++)
  {
    if(l[i]==0) continue;
    ll*m = (ll*)calloc(14,sizeof(ll));
    int k = i;
    m[i] = 0;
    int boo = 0;
    while(boo<2)
    {
      if(k==i) boo++;
      if(boo==2) break;
      if(k!=i)m[k]+=l[k];
      m[k] += l[i]/14;
      if(k>i)
      {
        // if(k==i) cout<<"i: "<<i<<" l[i]: "<<l[i]%14<<" k-i: "<<k-i<<" m[k]: "<<m[k]<<endl;
        if(l[i]%14>=k-i) m[k]++;
        // if(k==i) cout<<"m[k]: "<<m[k]<<endl;
      }
      else if(k<i)
      {
        if(l[i]%14>14-i-1+k) m[k]++;
      }
      k++;
      k%=14;
    }
    // cout<<i<<": ";
    // for(int i=0;i<14;i++) cout<<m[i]<<" ";cout<<endl;
    max1 = max(max1,count1(m));
    // cout<<count1(m)<<endl;
  }
  cout<<max1<<endl;
  return 0;
}

/*
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
*/
