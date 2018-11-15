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
    int n;
    sc(n);
    int*l = new int[n];
    for(int i=0;i<n;i++) sc(l[i]);
    int count = 0;
    for(int i=0;i<n-1;i++)
    {
      if(l[i+1]<l[i]) count++;
    }
    if(n>=2 && l[0]<l[n-1]) count++;
    if(count>=2) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  return 0;
}

