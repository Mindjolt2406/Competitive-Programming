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
  int x,y,z,t1,t2,t3;
  cin>>x>>y>>z>>t1>>t2>>t3;
  int a = (abs(z-x) + abs(y-x))*t2 + 3*t3;
  int b = abs(y-x)*t1;
  // cout<<a<<" "<<b<<endl;
  if(a<=b) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}

