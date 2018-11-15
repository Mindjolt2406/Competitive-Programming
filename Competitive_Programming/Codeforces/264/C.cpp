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

ll l[2001][2001]= {0};
ll pref1[2001][2001] = {0};
ll pref2[2001][2001] = {0};

int poss(int i,int j,int n,int m)
{
  if(i>=0 && j>=0 && i<n &&  j< m) return 1;
  return 0;
}

int main()
{
  int n;
  sc(n);
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) scll(l[i][j]);
  for(int i=0;i<n;i++)
  {
    pref1[i][0] = l[i][0];
    pref1[0][i] = l[0][i];
    pref2[0][i] = l[0][i];
    pref2[i][n-1] = l[i][n-1];
  }
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<n;j++)
    {
      pref1[i][j]+=pref1[i-1][j-1]+l[i][j];
    }
  }
  for(int i=1;i<n;i++)
  {
    for(int j=n-2;j>=0;j--)
    {
      pref2[i][j] += pref2[i-1][j+1]+l[i][j];
    }
  }
  pair<int,int> p1,p2;
  ll max1 = -1,max2 = -1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      ll c1 = 0,c2 = 0;
      int k = min(abs(n-1-i),abs(n-1-j));
      c1 = pref1[i+k][j+k];
      k = min(n-1-i,j);
      c2 = pref2[i+k][j-k];
      // cout<<"i: "<<i<<" j: "<<j<<" c1: "<<c1<<" c2: "<<c2<<" l[i][j]: "<<l[i][j]<<" sum: "<<c1+c2-l[i][j]<<endl;
      if((i+j)%2==1)
      {
        if(c1+c2-l[i][j]>max1)
        {
          max1 = c1+c2-l[i][j];
          p1 = mp(i+1,j+1);
        }
      }
      else
      {
        if(c1+c2-l[i][j]>max2)
        {
          max2 = c1+c2-l[i][j];
          p2 = mp(i+1,j+1);
        }
      }
    }
  }
  // cout<<endl;
  // for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cout<<pref1[i][j]<<" ";cout<<endl;} 
  // cout<<endl;
  // for(int i=0;i<n;i++) {for(int j=0;j<n;j++) cout<<pref2[i][j]<<" ";cout<<endl;}
  cout<<max1+max2<<endl;
  cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second<<endl;
  return 0;
}

