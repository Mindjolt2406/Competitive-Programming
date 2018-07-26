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

void getMax(int*l, int n)
{
  int c = 0;
  int* m = new int[n];
  int* orig = new int[n];
  int max1 = -1*INF;
  for(int i=0;i<n;i++) {m[n-1-i] = l[i];orig[i] = l[i];}
  for(int i=1;i<n;i++)
  {
    if(l[i]<l[i-1]+l[i])
    {
      l[i]+=l[i-1];
    }
    if(m[i]<m[i-1]+m[i]) m[i]+=m[i-1];
  }
  for(int i=0;i<n;i++)
  {
    l[i] = m[n-1-i]+l[i]-orig[i];
  }
}

int main()
{
  int n,m;
  sc(n);sc(m);
  int**l = new int*[n];
  for(int i=0;i<m;i++) l[i] = new int[m];
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) {sc(l[i][j]);}
  for(int i=0;i<n;i++)getMax(l[i],m);
  for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<l[i][j]<<" ";cout<<endl;}
  for(int i=n-2;i>=0;i--)
  {
    // getMax(l[i],m);
    for(int j=0;j<m;j++) l[i][j]+=l[i+1][j];
  }
  int max1 = -1*INF;
  for(int j=0;j<m;j++) max1 = max(max1,l[0][j]);
  cout<<max1<<endl;
  return 0;
}
