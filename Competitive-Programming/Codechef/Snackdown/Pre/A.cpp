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

using namespace std;

int main()
{
  int t;
  sc(t);
  while(t--)
  {
    int n,m;
    sc(n);sc(m);
    int c = max(n,m);
    int *l = new int[c];
    int *l2 = new int[c];
    ll sum1 = 0,sum2 = 0;
    for(int i=0;i<n;i++) {sc(l[i]);sum1+=l[i];}
    for(int i=0;i<m;i++) {sc(l2[i]);sum2+=l[i];}
    for(int i=n;i<c;i++) l[i] = 0;
    for(int i=m;i<c;i++) l2[i] = 0;
    if(sum1>sum2 || sum2>sum1) 
    {
      printf("Alice\n");
    }
    else
    {
      sort(l,l+n);
      reverse(l,l+n);
      sort(l2,l2+m);
      reverse(l2,l2+m);
      int boo = 0;
      for(int i=0;i<c;i++)
      {
        if(l[i]!=l2[i]) {boo  = 1;break;}
      }
      if(boo) printf("Alice\n");
      else printf("Bob\n");
    } 
  }
  return 0;
}

