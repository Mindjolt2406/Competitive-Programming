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
  while(1){
  string a,b;
  scr(a);scr(b);
  int c = min(abs(a[0]-b[0]),min(a[0]-'a','z'-a[0])+min(b[0]-'a','z'-b[0])+1);
  cout<<c<<endl;}
  return 0;
}
