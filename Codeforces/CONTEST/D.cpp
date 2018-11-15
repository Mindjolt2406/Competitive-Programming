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

ll max(ll x,ll y)
{
  if(x>y) return x;
  return y;
}

int main()
{
  int n;ll k;
  sc(n);scll(k);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  ll count = 0;
  for(int i=0;i<n-1;i++)
  {
    // cout<<l[i]<<" "<<l[i+1]<<endl;
    count+=l[i]/k;
    if(l[i]%k) {l[i+1] = max(0,l[i+1]-(k-l[i]%k));count++;}
    // cout<<count<<endl;
  }
  count+=l[n-1]/k;
  if(l[n-1]%k) count++;
  cout<<count<<endl;
  return 0;
}

