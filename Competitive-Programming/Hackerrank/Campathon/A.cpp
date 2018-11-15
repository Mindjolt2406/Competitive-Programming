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
  vector<string> v;
  for(int i=0;i<n;i++)
  {
    string s;
    scr(s);
    v.pu(s);
  }
  string k;
  for(int i=0;i<n;i++)
  {
    k+=v[i];
  }
  for(int i=n-1;i>=0;i--) k+=v[i];
  cout<<k<<endl;
  return 0;
}
