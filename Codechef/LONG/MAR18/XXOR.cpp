#include<iostream>
#include<string>
using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;
  int l[n];
  for(int i=0;i<n;i++)cin>>l[i];
  //Some precomputation
  int dp[n][31];
  for(int i=0;i<n;i++)
  {
    string s = bitset<31>(l[i]).to_string();
    for(int j=0;j<31;j++)
    {
      dp[i][j] = s[j]-48;
    }
  }
  for(int i=1;i<n;i++)
  {
    for(int j=0;j<31;j++)
    {
      dp[i][j]+=dp[i-1][j];
    }
  }
  while(q--)
  {
    int a,b;
    cin>>a>>b;
    a-=1;b-=1;
    string k = "";
    for(int j=0;j<31;j++)
    {
      int c;
      if(a==0) {c = dp[b][j];}
      else {c = dp[b][j]-dp[a-1][j];}
      if(c>=(b-a+2)/2)k+='0';
      else k+='1';
    }
    long x = stol(k, nullptr, 2);
    cout<<x<<endl;
  }
  return 0;
}
