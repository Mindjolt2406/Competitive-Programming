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

int check(int n)
{
  while(n>1)
  {
    if(n%2==0) n/=2;
    else return 0;
  }
  return 1;
}

int main()
{
  int n;
  sc(n);
  int* l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int count = 0;
  for(int i=0;i<n;i++)
  {
    int boo = 0;
    for(int j=0;j<n;j++)
    {
      if(i!=j && check(l[i]+l[j])) {boo = 1;break;}
    }
    if(!boo) count++;
  }
  cout<<count<<endl;
  return 0;
}
