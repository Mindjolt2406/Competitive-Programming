#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define MOD 131071
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
  while(getline(cin,s))
  {
    while(s[s.size()-1]!='#')
    {
      string k;
      getline(cin,k);
      s+=k;
    }
    vector<int> v;
    int prod = 1;
    for(int i=0;i<10001;i++)
    {
      prod%=MOD;
      v.pu(prod);
      prod*=2;
    }
    s = s.substr(0,s.size()-1);
    int sum1 = 0;
    for(int i=s.size()-1;i>=0;i--)
    {
      if(s[i]=='1')
      {
        int c = s.size()-1-i;
        sum1+=v[c];
        sum1%=MOD;
      }
    }
    if(sum1==0)printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
