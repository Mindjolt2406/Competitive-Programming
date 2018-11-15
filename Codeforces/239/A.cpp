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
  vector<int>*adj = new vector<int>[n];
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int min1 = INF;
  for(int i=0;i<n;i++)
  {
    int count = 0;
    count+=15*l[i];
    for(int j=0;j<l[i];j++)
    {
      int a;
      sc(a);
      count+=5*a;
    }
    min1 = min(min1,count);
  }
  cout<<min1<<endl;
  return 0;
}
