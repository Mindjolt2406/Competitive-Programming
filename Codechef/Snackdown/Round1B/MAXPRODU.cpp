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

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,k;
    sc(n);sc(k);
    if(((k+2)*(k+1))/2 -1<=n)
    {
      vector<ll> v;
      ll sum1 = 0;
      for(int i=0;i<k;i++) {v.pu(2+i);sum1+=2+i;}
      ll c = (n-sum1)/k;
      ll d = (n-sum1)%k;
      int i = (int)v.size()-1;
      while(d--)
      {
        v[i]++;
        i--;
      }
      for(int i=0;i<v.size();i++) v[i]+=c;
      sum1 = 1;
      for(int i=0;i<v.size();i++)
      {
        sum1*=((v[i]*v[i])%MOD - v[i]+MOD)%MOD;
        sum1+=MOD;
        sum1%=MOD;
      }
      
      cout<<sum1<<endl;
    }
    else if((k*(k+1))/2<=n)
    {
      cout<<0<<endl;
    }
    else cout<<-1<<endl;
  }
  return 0;
}