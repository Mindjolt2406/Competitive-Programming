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

int check(string a,string b)
{
  int i=0,j=0;
  while(1)
  {
    cout<<"i: "<<i<<" j: "<<j<<" a[i]: "<<a[i]<<" b[j]: "<<b[j]<<endl;
    if(i>=a.size()) return 1;
    if(j>=b.size()) return 0;
    if(a[i]==b[j]) {i++;j++;continue;}
    if(i==0) {j++;continue;}
    i = 0;
  }
}
int main()
{
  string a,b;
  scr(a);scr(b);
  cout<<check(a,b)<<endl;
  return 0;
}
