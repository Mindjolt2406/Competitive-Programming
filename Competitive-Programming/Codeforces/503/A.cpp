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
  int n,h,a,b,k;
  sc(n);sc(h);sc(a);sc(b);sc(k);
  for(int i=0;i<k;i++)
  {
    int a1,a2,b1,b2;
    sc(a2);sc(a1);sc(b2);sc(b1);
    int c = abs(a2-b2);
    // cout<<"c: "<<c<<endl;
    int ans = 0;
    if(a1<=b && a1>=a) ans = c+abs(b1-a1);
    else if(b1<=b && b1>=a) ans = c+abs(b1-a1);
    else if(b2==a2) ans = abs(a1-b1);
    else if(a1<a) ans = a-a1 + c + abs(b1-a);
    else if(a1>b) ans = a1-b + c + abs(b1-b);
    cout<<ans<<endl;
  }
  return 0;
}
