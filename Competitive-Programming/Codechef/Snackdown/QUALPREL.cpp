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
  while(t--)
  {
    int n,k;
    sc(n);sc(k);
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    sort(l,l+n);
    reverse(l,l+n);
    int c = l[k-1];
    int count = 0;
    // for(int i=0;i<n;i++) cout<<l[i]<<" ";cout<<endl;
    for(int i=0;i<n;i++) if(l[i]==c && i>k-1) count++;
    cout<<k+count<<endl;
  }
  return 0;
}

