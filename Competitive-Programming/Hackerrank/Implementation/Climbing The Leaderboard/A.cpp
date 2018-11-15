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

int bsearch1(int*l,int n,int value)
{
  int beg = 0,end = n-1;
  int maxindex = -1;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(l[mid]>value) {maxindex = mid;beg = mid+1;}
    else if(l[mid]==value) {return mid;}
    else end = mid-1;
  }
  return maxindex;
}

int main()
{
  int n;
  sc(n);
  int*l = new int[n];
  set<int> s;
  int count = 0;
  for(int i=0;i<n;i++)
  {
    int a;sc(a);
    if(s.find(a)!=s.end()) {l[count] = a;count++;}
  }
  int m;sc(m);
  int*m1 = new int[m];
  for(int i=0;i<m;i++) sc(m1[i]);
  for(int i=0;i<m;i++)
  {
    cout<<bsearch1(l,n,m1[i])+1<<endl;
  }
  return 0;
}
