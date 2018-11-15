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
  int n,k;
  sc(n);sc(k);
  int* l = (int*)calloc(102,sizeof(int));
  for(int i=0;i<n;i++)
  {
    int a;
    sc(a);
    l[a] = 1;
  }
  int count = 0;
  for(int i=0;i<=k;i++)
  {
    if(i<k && l[i]!=1) count++;
    else if(l[k]&& i==k) count++; 
  }
  cout<<count<<endl;
  return 0;
}

