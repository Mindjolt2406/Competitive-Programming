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
  for(int i=0;i<n;i++) sc(l[i]);
  int boo = -1;
  if(l[1]>l[0]) boo = 1;
  else if(l[1]<l[0]) boo = 0;
  int max1 = 2;
  int count = 2;
  for(int i=1;i<n-1;i++)
  {
    // cout<<"boo: "<<boo<<" l[i]: "<<l[i]<<" count: "<<count<<endl;
    if(boo==1 && l[i+1]<l[i])  {count++;boo^=1;}
    else if(boo==0 && l[i+1]>l[i]) {count++;boo^=1;}
    else if(l[i+1]==l[i]) {max1 = max(max1,count); count = 1;}
    else if(boo ==-1 && l[i+1]<l[i]) boo = 0;
    else if(boo == -1 && l[i+1]>l[i]) boo = 1;
    else {max1 = max(max1,count);count = 2;}
  }
  max1 = max(max1,count);
  cout<<max1<<endl;
  return 0;
}

