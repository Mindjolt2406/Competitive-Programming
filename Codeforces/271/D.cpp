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
  int t,k;
  sc(t);sc(k);
  ll*l = new ll[100010];
  l[0] = 1;
  for(int i=1;i<k;i++) l[i] = 1;
  for(int i=k;i<100005;i++) l[i] = (l[i-k]+l[i-1])%MOD;
  l[0] = 0;
  for(int i=1;i<100005;i++) {l[i]+=l[i-1];l[i]%=MOD;}
  for(int h=0;h<t;h++)
  {
    int a,b;
    sc(a);sc(b);
    cout<<(l[b]-l[a-1]+MOD)%MOD<<endl;
  }
  return 0;
}
