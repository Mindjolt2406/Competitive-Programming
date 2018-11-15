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

int check(int i,int j,int*m)
{
  if(i>0) return m[j]-m[i-1];
  return m[j];
}

int main()
{
  int n,k;
  sc(n);sc(k);
  int* l = new int[n];
  int* m = new int[n];
  for(int i=0;i<n;i++)
  {
    sc(l[i]);
    if(i>0)m[i] = m[i-1]+l[i];
    else m[0] = l[0];
  }
  int left = 0,right = 0;
  ll count = 0;
  while(left<=right)
  {
    // cout<<check(left,right,m)<<endl;
    while(right<n && check(left,right,m)<k*(right-left+1))
    {
      // cout<<"eft: "<<left<<" right: "<<right<<endl;
      right++;
    }
    // cout<<right<<endl;
    count+=(right-left-1);
    left++;
  }
  cout<<count<<endl;
  return 0;
}
