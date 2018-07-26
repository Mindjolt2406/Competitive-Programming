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
#define sc(n) scanf("%d",&n)
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
    int vm,n;
    sc(vm);sc(n);
    vm/=10;
    map<int,vector<int,int> > d1,d2;
    map<int,vector<int,int> > :: iterator it;
    // d1 is for the attachments, and d2 is for the originals
    for(int i=0;<n;i++)
    {
      int a,b,c;
      sc(a);sc(b);sc(c);
      a/=10;
      b*=a;
      if(c) d1[c] = mp(a,b);
      else d2[c] = mp(a,b);
    }
    int**dp = new int[3200];
    for(int i=0;i<3200;i++) dp[i] = new int[60];
    for(int i=0;i<3200;i++) for(int j=0;j<60;j++) dp[i][j] = 0;
    k = d2.size();
    int i=0;
    for(it = d2.begin();it!=d2.end();it++)
    {
      vector<int> v1 = it->second;
      vector<int> v2 = d1[it->first];
      if(i==0)
      {
        dp[i][d1[c].first] = d1[c].second;
        dp[i][it->second.first] = it->second.second;
        dp[i][d1[it->first].first] = d1[it->first].second;
      }
      i++;
    }
  }
  return 0;
}
