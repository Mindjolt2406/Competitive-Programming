// Will not ork
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
    int*l = new int[n];
    int*m = new int[n];
    for(int i=0;i<n;i++){sc(l[i]);m[i] = l[i];}
    sort(m,m+n);
    int i=0,j = 0,count = 0;
    while(i<n)
    {
      if(l[i]==m[j]) {j++;count++;}
      i++;
    }
    cout<<n-count<<endl;
  }
  return 0;
}
