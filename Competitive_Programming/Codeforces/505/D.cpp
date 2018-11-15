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

int gcd1(int a, int b)
{
    if (a == 0)
        return b;
    return gcd1(b % a, a);
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  for(int i=0;i<n;i++)
  {
    int boo = 0,count = 0;
    for(int j=0;j<n;j++)
    {
      if(i==j) continue;
      if(gcd1(min(l[i],l[j]),max(l[i],l[j]))==1) {boo = 1;}
      else {count++;}
      if(count>=2) {boo = 0;break;}
    }
    if(boo==1) {cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
  return 0;
}
