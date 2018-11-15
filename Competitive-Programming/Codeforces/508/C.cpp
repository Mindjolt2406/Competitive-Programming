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
  vector<vector<int> > v;
  for(int i=0;i<n;i++)
  {
    vector<int> v1(4);
    sc(v1[0]);sc(v1[1]);sc(v1[2]);sc(v1[3]);
    v.pu(v1);
  }
  
  return 0;
}
