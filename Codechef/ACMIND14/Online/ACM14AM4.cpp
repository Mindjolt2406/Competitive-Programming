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
    int n,m;
    sc(n);sc(m);
    int**l = new int*[n];
    for(int i=0;i<n;i++) l[i] = new int[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) sc(l[i][j]);
    int**pref1 = new int*[n];
    for(int i=0;i<n;i++) pref1[i] = new int[m];

  }
  return 0;
}

