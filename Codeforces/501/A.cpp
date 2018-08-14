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
  int n,m;
  sc(n);sc(m);
  int*l = (int*)calloc(101,sizeof(int));
  for(int i=0;i<n;i++)
  {
    int a,b;
    sc(a);sc(b);
    l[a]++;l[b+1]--;
  }
  int sum1 = 0,count = 0;
  vector<int> v;
  for(int i=1;i<=m;i++)
  {
    sum1+=l[i];
    if(sum1==0) v.pu(i);
  }
  cout<<v.size()<<endl;
  for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;
  return 0;
}
