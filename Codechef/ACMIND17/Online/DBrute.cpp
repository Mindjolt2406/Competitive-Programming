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
    int min1 = INF;
    for(int i=0;i<n;i++) sc(l[i]);
    for(int i=0;i<n;i++) {sc(m[i]); min1 = min(min1,m[i]);l[i]%=m[i];}
    int min2 = INF;
    for(int i=0;i<min1;i++)
    {
      int count = 0;
      for(int j=0;j<n;j++)
      {
        if(l[j]>i) count+=m[j]-l[j]+i;
        else count+=i-l[j];
      }
      min2 = min(min2,count);
    }
    cout<<min2<<endl;
  }
  return 0;
}

