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
  stack<pair<char,int> > s1;
  int*dp = (int*)calloc(s.size(),sizeof(int));
  int i=0;
  for(;i<n;i++)
  {
    if(s1.empty()) {s1.push(mp(s[i],i));dp[0] = i;}
    else
    {
      if(s[i]=='(') {dp[s1.top().second] = i-s1.top().second-1;s1.push(mp(s[i],i));}
      else if(s[i]==')' && s1.top().first==s[i]) {dp[s1.top().second] = i-s1.top().second-1;s1.push(mp(s[i],i));}
      else if(s[i]==')')
      {
        pair<char,int> p = s1.top();
        s1.pop();
        dp[p.second] = 0;
      }
    }
  }
  if(s1.empty()) printf("%d 1\n",n);
  else
  {
    if(s1.top().second!=n-1) dp[s1.top().second] = n-1-s1.top().second;
    int max1 = -1;
    for(int i=0;i<n;i++) max1 = max(max1,dp[i]);
    if(max1==0) printf("0 1\n");
    else
    {
      int count = 0;
      for(int i=0;i<n;i++) if(dp[i]==max1) count++;
      printf("%d %d\n",max1,count);
    }
  }
  // for(int i=0;i<n;i++) cout<<dp[i]<<" ";cout<<endl;
  return 0;
}
