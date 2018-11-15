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
  ll n;
  scll(n);
  if(n%2==0)
  {
    if(n==2) {cout<<-1<<endl; return 0;}
    ll m = n/2;
    cout<<m*m-1<<" "<<m*m+1<<endl;
  }
  else 
  {
    if(n==1) {cout<<-1<<endl;return 0;}
    ll c = n*n;
    c = (c-1)/2;
    cout<<c<<" "<<(c+1)<<endl;
    // else if(n==1 || n==2) cout<<-1<<endl;
  }
  return 0;
}

