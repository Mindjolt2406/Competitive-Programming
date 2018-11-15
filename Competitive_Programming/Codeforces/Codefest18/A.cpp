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
  int k = n;
  int count = 0;
  while(n)
  {
    count++;
    n/=2;
  }
  int count2 = 0;
  while(k%2==0)
  {
    k/=2;
    count2++;
  }
  if(count==count2) count--;
  cout<<count<<endl;
  return 0;
}
