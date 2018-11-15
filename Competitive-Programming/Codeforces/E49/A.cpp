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
  int t;
  sc(t);
  while(t--)
  {
    int n;
    sc(n);
    string s;
    scr(s);
    int boo = 1;
    for(int i=0;i<n/2;i++)
    {
      if((s[i]+1!=s[n-1-i]+1)&&(s[i]-1!=s[n-1-i]+1)&&(s[i]+1!=s[n-1-i]-1)&&(s[i]-1!=s[n-1-i]-1))
      {
        boo = 0;break;
      }
    }
    if(boo) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
  return 0;
}
