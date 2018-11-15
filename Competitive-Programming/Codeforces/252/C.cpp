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
  int n,m,k;
  sc(n);sc(m);sc(k);
  int total = 0;
  cout<<n*m-2*k+2<<" ";
  while(total<n*m-2*k+2)
  {
    int a = total/m;
    int b = total-(a)*m;
    if(a%2==1) b = m-1-b;
    printf("%d %d ",a+1,b+1);
    // cout<<a+1<<" "<<b+1<<" ";
    total++;
  }
  printf("\n");
  int boo = 0;
  while(total<n*m)
  {
    if(boo ==0) {printf("2 ");}
    int a = total/m;
    int b = total-(a)*m;
    if(a%2==1) b = m-1-b;
    printf("%d %d ",a+1,b+1);
    if(boo==1) printf("\n");
    boo++;
    boo%=2;
    total++;
  }
  return 0;
}

/*
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
*/
