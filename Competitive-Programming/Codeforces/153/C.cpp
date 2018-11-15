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
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define GET_MACRO(_1,_2,_3,_4,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__, t4, t3, t2, t1)(__VA_ARGS__)


using namespace std;

ll bsearch1(int *l,int n,int start,int value)
{
  int beg = start+1,end = n-1;
  ll max1 = start+1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(l[start]+value>=l[mid]) {max1 = mid;beg = mid+1;}
    else end = mid-1;
  }
  return ((max1-start-1)*(max1-start))/2;
}

int main()
{
  int n,k;
  sc(n);sc(k);
  int*l = new int[n];
  for(int i=0;i<n;i++) sc(l[i]);
  ll count = 0;
  for(int i=0;i<n-2;i++)
  {
    count+=bsearch1(l,n,i,k);
  }
  cout<<count<<endl;
  return 0;
}













