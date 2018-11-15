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
  string s;
  scr(s);
  int n = s.size();
  ll a,b;
  scll(a);scll(b);
  ll c = 0,d = 1;
  int i = n-1;
  vector<int> v1,v2;
  v1.assign(n,0);v2.assign(n,0);
  for(int i=0;i<n;i++)
  {
    c*=10;
    c%=a;
    c+=s[i]-'0';
    c%=a;
    v1[i] = c;
  }
  v2[n-1] = s[n-1]-'0';
  v2[n-1]%=b;
  for(int i=n-2;i>=0;i--)
  {
    d*=10;
    d%=b;
    v2[i] = (d*(s[i]-'0')+v2[i+1])%b;
  }
  int boo = 0;
  for(int i=0;i<n-1;i++)
  {
    // cout<<"i: "<<i<<" v1: "<<v1[i]<<" v2: "<<v2[i]<<endl;
    if(v1[i]==0 && v2[i+1]==0) 
    {
      string s1,s2;
      int j = 0;
      for(;j<=i||s[j]=='0';j++) s1+=s[j];
      for(;j<n;j++) s2+=s[j];
      if(s2=="") {cout<<"NO"<<endl;return 0;}
      cout<<"YES"<<endl;
      cout<<s1<<endl<<s2<<endl;
      boo = 1;break;
    }
  }
  if(!boo) cout<<"NO"<<endl;
  return 0;
}

