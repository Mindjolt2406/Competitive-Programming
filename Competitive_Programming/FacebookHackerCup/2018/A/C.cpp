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

void rollinghash(int size, string s,ll *m)
{
  int n = s.size();
  ll hash =0;
  ll k = 27,prod = 1;
  for(int i=0;i<size;i++)
  {
    hash*=k;
    hash+=(s[i]);hash%=MOD;
    if(i<size-1)prod*=k;prod%=MOD;
  }
  for(int i=0;i<n-size+1;i++)
  {
    m[i] = hash;
    hash-=s[i]*prod;
    hash = ((hash%MOD)+MOD)%MOD;
    hash*=k;
    if(i<n-size)hash+=s[i+size];
    hash%=MOD;
  }
}

int check(string s,int size,int a,int b)
{
  int boo = 1;
  for(int i=0;i<size;i++)
  {
    if(s[i+a]!=s[i+b]) boo = 0;
  }
  return boo;
}

int main()
{
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    string s;
    scr(s);
    int n = s.size();
    int boo2 = 0;
    for(int i=1;i<(n+1)/2;i++)
    {
      ll* l = (ll*)calloc(n-i+1,sizeof(ll));
      rollinghash(i,s,l);
      int boo1 = 0;
      for(int j=0;j<n-i;j++)
      {
        if(l[j]==l[j+i])
        {
          if(check(s,i,j,j+i)) {boo1 = 1;break;}
        }
      }
      if(boo1 == 1) {boo2 = 1;break;}
    }
    if(boo2 == 1)
    {
      // Impossible
      printf("Case #%d: Impossible\n",h);
    }
    else
    {
      int l[26] = {0};
      for(int i=0;i<26;i++) l[i] = -1;
      int a=-1,b=-1;
      for(int i=0;i<s.size();i++)
      {
        if(l[s[i]-65]!=-1) {a = l[s[i]-65];b = i;break;}
        l[s[i]-65] = i;
      }
      string k;
      if(a!=-1 && b!=-1)
      {
        n = s.size();
        // cout<<a<<" "<<b<<endl;
        if(a>0) k+=s.substr(0,a);
        k += s.substr(a,b-a) + s.substr(a,b-a) + s.substr(b,n-1-b+1);
        cout<<"Case #"<<h<<": "<<k<<endl;
      }
      else printf("Case #%d: Impossible\n",h);;
      // A legit false positive}
    }
  }
  return 0;
}
