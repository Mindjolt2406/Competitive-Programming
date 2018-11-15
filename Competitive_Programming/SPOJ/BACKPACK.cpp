// Got oads of WAs cuz I initlaised the dp as dp[3210][60] instead of the other way around
// THis probome is a slight modification of the classical knapsack problem
// Here, you have a few attachemtns, manually find the max of all the attachments with the given conditions
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

int max1(int a,int b,int c, int d,int e)
{
  return max(a,max(b,max(c,max(d,e))));
}

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int vm,n;
    sc(vm);sc(n);
    vm/=10;
    map<int,vector< pair<int,int> > > d1;
    map<int,pair<int,int> > d2;
    map<int,pair<int,int> > :: iterator it;
    // d1 is for the attachments, and d2 is for the originals
    for(int i=0;i<n;i++)
    {
      int a,b,c;
      sc(a);sc(b);sc(c);
      a/=10;
      b*=a;
      if(c) d1[c].pu(mp(a,b));
      else d2[i+1] = mp(a,b);
    }
    int**dp = new int*[60];
    for(int i=0;i<60;i++) dp[i] = new int[3210];
    for(int i=0;i<60;i++) for(int j=0;j<3210;j++) dp[i][j] = 0;
    int k = d2.size();
    int i=0;
    for(it = d2.begin();it!=d2.end();it++)
    {
      pair<int,int> c =  it->second;
      int boo = 1;
      vector<pair<int,int> > v;
      if(d1.find(it->first)!=d1.end()) v = d1[it->first];
      else boo = 0;
      if(i==0)
      {
        dp[i][c.first] = c.second;
        for(int j=0;j<v.size();j++) if(v[j].first+c.first<=vm) dp[i][v[j].first+c.first] = v[j].second+c.second;
        if(v.size()==2 && v[0].first+v[1].first+c.first<=vm)
        {
          dp[i][v[0].first+v[1].first+c.first] = v[0].second+v[1].second+c.second;
        }
      }
      else
      {
        for(int j=1;j<=vm;j++)
        {
          int a=0,b=0,c1=0,d=0,e=0;
          a = dp[i-1][j];
          if(j>=c.first) b = dp[i-1][j-c.first]+c.second;
          if(boo && j>=c.first+v[0].first) c1 = c.second+v[0].second+dp[i-1][j-v[0].first-c.first];
          if(boo&& v.size()==2 && j>=c.first+v[1].first) d = c.second+v[1].second+dp[i-1][j-v[1].first-c.first];
          if(boo && v.size()==2 && j>=c.first+v[0].first+v[1].first) e = c.second+v[1].second+v[0].second+dp[i-1][j-v[0].first-v[1].first-c.first];
          dp[i][j] = max1(a,b,c1,d,e);
        }
      }
      i++;
    }
    int max1 = 0;
    for(int j=1;j<=vm;j++)
    {
      max1 = max(max1,dp[i-1][j]);
    }
    printf("%d\n",max1*10);
    // for(int i=0;i<k;i++) cout<<dp[i][0]<<" ";cout<<endl;
    k = i;
  }
  return 0;
}

/*
1
2000 7
400 4 0
500 5 0
200 3 1
400 5 2
700 4 0
800 2 1
900 5 5

*/
