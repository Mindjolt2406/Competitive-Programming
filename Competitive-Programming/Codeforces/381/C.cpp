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
  int*l = new int[n];
  int min1 = INF;
  for(int i=0;i<m;i++)
  {
    int a,b;
    sc(a);sc(b);
    min1 = min(min1,abs(a-b)+1);
  }
  int k = 0;
  for(int i=0;i<n;i++)
  { 
    l[i] = k;
    k++;
    k%=min1;
  }
  cout<<min1<<endl;
  for(int i=0;i<n;i++) cout<<l[i]<<" ";cout<<endl;
  return 0;
}

