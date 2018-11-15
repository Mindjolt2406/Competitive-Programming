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
  int a,b,c;
  sc(a);sc(b);sc(c);
  vector<int> v = {a,b,c};
  sort(v.begin(),v.end());
  cout<<max(0,v[2]-v[1]-v[0]+1)<<endl;
  return 0;
}

