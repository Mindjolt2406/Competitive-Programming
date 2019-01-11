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
#define pr(v) { for(int i=0;i<v.size();i++) { v[i]==INF? cout<<"INF " : cout<<v[i]<<" "; } cout<<endl;}
#define t1(x)                cerr<<#x<<" : "<<x<<endl
#define t2(x, y)             cerr<<#x<<" : "<<x<<" "<<#y<<" : "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<" :" <<x<<" "<<#y<<" : "<<y<<" "<<#z<<" : "<<z<<endl
#define t4(a,b,c,d)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<endl
#define t5(a,b,c,d,e)          cerr<<#a<<" : "<<a<<" "<<#b<<" : "<<b<<" "<<#c<<" : "<<c<<" "<<#d<<" : "<<d<<" "<<#e<<" : "<<e<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,NAME,...) NAME
#define t(...) GET_MACRO(__VA_ARGS__,t5, t4, t3, t2, t1)(__VA_ARGS__)
#define _ cout<<"here"<<endl;


using namespace std;

map<int,int> d;

int bsearch(vector<int>&v,int value)
{
  int n = v.size();
  int beg = 1, end =n-1;
  int max1 = 0;
  while(beg<=end)
  {
    int mid = (beg+end)/2;
    if(value>=v[mid]) {beg = mid+1;max1 = mid;}
    else {end = mid-1;}
  }
  // t(value,max1);
  return max1;
}

vector<int> LIS(vector<int> &v) 
// Returns the dictionary where the key is a number at the value is the length of the LIS that number is a part of
{
  int n = v.size();
  vector<int> memo(n+1,INF);
  vector<int> dp(n);
  dp[0] = 1;
  // memo[1] = v[0];
  for(int i=0;i<n;i++)
  {
    int c = bsearch(memo, v[i]);
    c++;
    dp[i] = c;
    memo[c] = min(memo[c],v[i]);
    // pr(memo);
    // pr(dp);
  }
  // for(int i=0;i<memo.size();i++) cout<<memo[i]<<" ";cout<<endl;
  return dp;
}

int main()
{
  int n,T;
  sc(n);sc(T);
  vector<int> arr(n);
  for(int i=0;i<n;i++) sc(arr[i]);
  if(T<=2*n)
  { 
    vector<int> v;
    for(int i=0;i<T;i++)
    {
      for(int j=0;j<arr.size();j++) v.pu(arr[j]);
    }
    vector<int> dp = LIS(v);
    int max1 = -1;
    for(int i=0;i<dp.size();i++) max1 = max(max1, dp[i]);
    cout<<max1<<endl;
  }
  else
  {
    vector<int> v;
    for(int i=0;i<arr.size();i++)
    {
      for(int j=0;j<arr.size();j++)
      {
        v.pu(arr[j]);
      }
    }

    vector<int> a = LIS(v);
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++) v[i] = 500-v[i];
    vector<int> b = LIS(v);
    reverse(b.begin(),b.end());
    int max1 = -1;
    for(int i=0;i<n;i++)
    {
      int count = 0;
      for(int j=0;j<arr.size();j++) if(arr[i]==arr[j]) count++;

      for(int j=0;j<n;j++)
      {
        if(arr[j]<arr[i]) continue;
        max1 = max(max1, a[n*(n-1)+i] + (T-2*n)*count + b[j]);
      }
    }
    cout<<max1<<endl;
  }
  return 0;
}

