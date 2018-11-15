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
  int n;
  sc(n);
  int*l = new int[n];
  int*r = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  for(int i=0;i<n;i++) sc(r[i]);
  vector<int> v;
  set<int> s;
  int max1 = -1;
  for(int i=0;i<n;i++)
  {
    if(l[i]>i || r[i]>n-1-i) {cout<<"NO"<<endl;return 0;}
    else {v.pu(n-l[i]-r[i]);s.insert(n-l[i]-r[i]);max1 = max(max1,l[i]+r[i]);}
  }
  // cout<<s.size()<<en dl;
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=i+1;j<n;j++)
  //   {
  //     if(l[i]+r[i]<l[j]+r[j] && r[i]<r[j]) {cout<<"NO"<<endl;return 0;}
  //     if(l[i]+r[i]<l[j]+r[j] && l[i]>l[j]) {cout<<"NO"<<endl;return 0;}
  //   }
  // }
  // map<int,int> dl,dr;
  // int maxl,maxr
  for(int i=0;i<n;i++)
  {
    // cout<<"i: "<<i<<endl;
    int count = 0;
    for(int j=i+1;j<n;j++)
    {
      if(l[j]+r[j]<l[i]+r[i]) count++;
    }
    if(count>r[i]) {cout<<"NO"<<endl;return 0;}
  }
  for(int i=n-1;i>=0;i--)
  { 
    int count = 0;
    for(int j=i-1;j>=0;j--)
    {
      if(l[j]+r[j]<l[i]+r[i]) count++;
    }
    if(count>l[i]) {cout<<"NO"<<endl;return 0;}
  }
  cout<<"YES"<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  return 0;
}

