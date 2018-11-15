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
#define fi first
#define se second
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}

using namespace std;

int main()
{
  int n;
  sc(n);
  vector<pair<int,int> > v;
  map<int,int> d;
  for(int i=0;i<n;i++)
  {
    int a;
    sc(a);
    v.pu(mp(i,a));
    d[a] =i;
  }
  sort(v.begin(),v.end());
  int top = -1;
  for(int i=0;i<n;i++)
  {
    int b;
    sc(b);
    cout<<max(0,d[b]-top)<<" ";
    if(d[b]>=top) top = d[b];
  }
  cout<<endl;
  return 0;
}

