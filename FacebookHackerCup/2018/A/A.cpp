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
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    int n,k;
    sc(n);sc(k);
    ll v1;
    scll(v1);
    // cout<<"v1: "<<v1<<endl;
    string* l = new string[n];
    for(int i=0;i<n;i++) scr(l[i]);
    ll c = ((k)*(v1-1))%n;
    // cout<<"c: "<<c<<endl;
    vector<ll> v;
    for(int i=0;i<k;i++) v.pu((c+i)%n);
    sort(v.begin(),v.end());
    printf("Case #%d: ",h);
    for(int i=0;i<v.size();i++) cout<<l[v[i]]<<" ";
    cout<<endl;
  }
  return 0;
}

/*
6
4 1 3
LikeSign
Arcade
SweetStop
SwagStore
4 4 100
FoxGazebo
MPK20Roof
WoodenSculpture
Biryani
4 3 1
LikeSign
Arcade
SweetStop
SwagStore
4 3 3
LikeSign
Arcade
SweetStop
SwagStore
4 3 10
LikeSign
Arcade
SweetStop
SwagStore
2 1 1000000000000
RainbowStairs
WallOfPhones

*/
