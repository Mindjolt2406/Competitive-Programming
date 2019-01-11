// This question was nice.
// I got the recurrence relation, but made a mistake by switching the two cases and that took some time to debug
// This took 1hr 50 mins
// The main idea was that once you fix a letter, the problem repeats with the next index
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
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

struct pair_hash {
  inline int operator () (const pair<string,string> &p) const {
    auto h1 = hash<string>{}(p.fi +p.se);
    return h1;
  }
};

int main()
{
  string s;
  int k,m;
  scr(s);
  int n = s.size();
  sc(k); sc(m);
  unordered_map<pair<string,string>, int, pair_hash> d;
  for(int i=0;i<m;i++)
  {
    string s1,s2;
    int a;
    cin>>s1>>s2;
    sc(a);
    d[mp(s1,s2)] = a;
  }
  
  for(int i=0;i<26;i++) 
  {
    for(int j=0;j<26;j++) 
    {
      string s1(1,i+'a');
      string s2(1,j+'a');
      if(d.find(mp(s1,s2))==d.end()) d[mp(s1,s2)] = 0;
    }
  }

  int***dp = new int**[n];
  for(int i=0;i<n;i++) 
  {
    dp[i] = new int*[k+1];
    for(int j=0;j<=k;j++) dp[i][j] = new int[26];
  }

  // Initialising the DP array
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<=k;j++)
    {
      for(int k1=0;k1<26;k1++) dp[i][j][k1] = -1*INF;
    }
  }

  
  dp[0][0][s[0]-'a'] = 0;

  if(k>0)for(int i=0;i<26;i++) dp[0][1][i] = 0;

  for(int i=1;i<n;i++)
  {
    for(int j=0;j<=k;j++)
    {
      // k1 is the current index
      for(int k1 =0;k1<26;k1++)
      {
        if(k1!=s[i]-'a' && j>0)
        {
          for(int k2=0;k2<26;k2++)
          {
            string s2(1,'a'+k2);
            string s1(1,'a'+k1);
            dp[i][j][k1] = max(dp[i-1][j-1][k2] + d[mp(s2,s1)],dp[i][j][k1]);
          }
        }
        else if(k1==s[i]-'a')
        {
          for(int k2=0;k2<26;k2++)
          {
            string s2(1,'a'+k2);
            string s1(1,'a'+k1);
            dp[i][j][k1] = max(dp[i-1][j][k2] + d[mp(s2,s1)],dp[i][j][k1]);
          }
        }
      }
    }
  }

  int max1 = -1*INF;
  for(int i=0;i<=k;i++) for(int j=0;j<26;j++) max1 = max(max1,dp[n-1][i][j]);
  cout<<max1<<endl;
  return 0;
}

