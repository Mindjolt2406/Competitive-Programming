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
  for(int h=1;h<=t;h++)
  {
    int n;
    sc(n);
    int max1 = -1;
    for(int i=0;i<=n;i++)
    {
      int a;
      sc(a);
      if(i!=n && a== -1*(i+1)) max1 = i;
    }
    max1+=2;max1%=2;
    if((max1==1 && n%2==0) || (max1==0 && n%2==1)) printf("Case #%d: 0\n",h);
    else printf("Case #%d: 1\n0.0\n",h);
  }
  return 0;
}

/*
2
1
1
1
4
9
0
-6
2
-2

*/
