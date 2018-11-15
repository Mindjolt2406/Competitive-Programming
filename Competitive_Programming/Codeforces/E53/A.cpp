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
  string s;
  scr(s);
  for(int i=0;i<n-1;i++)
  {
    if(s[i]!=s[i+1]){cout<<"YES"<<endl;cout<<s[i]<<s[i+1]<<endl;return 0;}
  }
  cout<<"NO"<<endl;

  return 0;
}

