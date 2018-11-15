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
  k--;
  string s;
  scr(s);
  if(k>=n/2) {k = n-1-k;}
  int boo1 = 0,boo2 = 0,last1 = -1,last2 = n/2;
  for(int i=0;i<k;i++)
  {
    if(s[i]!=s[n-1-i]) {boo1 = 1;last1 = i-1;break;}
  }
  for(int i=n/2;i>=k+1;i--)
  {
    if(s[i]!=s[n-1-i]) {boo2 = 1;break;}
    else last2 = i;
  }
  // for(int i=k+1;i<=n/2;i++)
  // {
  //   if(s[i] != s[n-1-i]) {boo2 = 1;}
  //   else(last2==i;)
  // }
  int count1 = INF,count2 = INF,count = 0;
  if(boo1) count1 = 2*(k-last1-1);
  if(boo2) count2 =(last2-k-1)*2;
  // cout<<"count1: "<<count1<<" count2: "<<count2<<endl;
  if(boo1||boo2)count+=min(count1,count2);
  if(count2==INF && count1!=INF) count-=count1/2;
  else if(count1==INF && count2!=INF) count-=count2/2;
  if(boo1&&boo2)count+=max(count1,count2)/2;
  // cout<<"count: "<<count<<endl;
  for(int i=0;i<n/2;i++)
  {
    int c = min(abs(s[i]-s[n-1-i]),min(s[i]-'a','z'-s[i])+min(s[n-1-i]-'a','z'-s[n-1-i])+1);
    count+=c;
  }
  cout<<count<<endl;
  return 0;
}

/*
4 3
smox

*/
