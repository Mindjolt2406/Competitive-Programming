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
  int*low = new int[n];
  int*high = new int[n];
  int*close = new int[n];
  for(int i=0;i<n;i++) sc(low[i]);
  for(int i=0;i<n;i++) sc(high[i]);
  for(int i=0;i<n;i++) sc(close[i]);
  int up=0,down=0;
  for(int i=1;i<n;i++)
  {
    if(low[i]>close[i-1]) up++;
    if(high[i]<close[i-1]) down++;
  }
  cout<<up<<" "<<down<<endl;
  return 0;
}
