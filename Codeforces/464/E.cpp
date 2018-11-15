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
  vector<int> v;
  int left = 0,right = -1;
  ld mean = 0;
  ld sum1 = 0;
  for(int i=0;i<n;i++)
  {
    int a;
    sc(a);
    if(a==1)
    {
      int b;
      sc(b);
      v.pu(b);
      right++;
      mean = (mean*(right)+v[right])/(right+1);
    }
    else
    {
      while(left<=right && v[left]<=mean)
      {
        sum1+=v[left];
        left++;
      }
      // cout<<"left: "<<left<<" right: "<<right<<" sum1: "<<sum1<<endl;
      cout<<setprecision(10);
      if(left>right) cout<<v[right] - (sum1)/(left)<<endl;
      else cout<<v[right] - (sum1+v[right])/(left+1)<<endl;
    }
  }
  return 0;
}
