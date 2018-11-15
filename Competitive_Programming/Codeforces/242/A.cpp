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
  string s;
  scr(s);
  int count1 = 0,count2 = 0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='X') count1++;
    else count2++;
  }
  int k = n/2;
  int c = max(count1,count2)-n/2;
  if(max(count1,count2)==count1)
  {
    for(int i=0;i<n && c>0;i++)
    {
      if(s[i]=='X') {s[i] = 'x';c--;}
    }
  }
  else{
    for(int i=0;i<n && c>0;i++)
    {
      if(s[i]=='x') {s[i] = 'X';c--;}
    }
  }
  cout<<max(count1,count2)-n/2<<endl;
  cout<<s<<endl;
  return 0;
}
