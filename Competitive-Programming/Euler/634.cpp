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
  ll count = 0;
  for(int i=2;i<(int)pow(n,(1.0/3));i++)
  {
    ll a1 = n/(pow(i,3));
    a1 = (ll)a1;
    cout<<"i :"<<i<<" a1: "<<((int)(sqrt(a1)))<<endl;
    if(a1!=1)count+=((int)(sqrt(a1)-1));
    cout<<"count: "<<count<<endl;
  }
  cout<<count<<endl;
  return 0;
}
