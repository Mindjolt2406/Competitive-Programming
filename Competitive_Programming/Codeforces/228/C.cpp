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
#define t1(x)                cerr<<#x<<": "<<x<<endl
#define t2(x, y)             cerr<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<":" <<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<endl

using namespace std;

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  int*m = (int*)calloc(n,sizeof(int));
  // for(int i=0;i<n;i++) m[i] = -1;
  for(int i=0;i<n;i++) sc(l[i]);
  sort(l,l+n);
  reverse(l,l+n);
  int count = 0;
  for(int i=0;i<n;i++)
  {
    if(m[i]==0) {count++;m[i] = 1;}
    else continue;
    int counter = -1;
    for(int j=n-1;j>i;j--)
    {
      if(counter==l[i]-1) break;
      if(m[j]==0)
      {
        if(l[j]>counter) {m[j] = 1;counter++;}
      }
      if(counter==l[i]-1) break;
    } 
  }
  cout<<count<<endl;
  return 0; 
}

