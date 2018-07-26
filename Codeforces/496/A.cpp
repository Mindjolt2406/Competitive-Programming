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
  int n;
  sc(n);
  int* l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  int i=0;
  vector<int> v;
  while(i<n)
  {
    int max1 = 0;
    while(i<n && l[i]>max1)
    {
      max1 = l[i];
      i++;
    }
    v.pu(max1);
  }
  cout<<v.size()<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  return 0;
}
