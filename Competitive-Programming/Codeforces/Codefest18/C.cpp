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
  string s1,s2;
  scr(s1);scr(s2);
  int i=0;
  int count = 0;
  while(i<n)
  {
    if(i!=n-1)
    {
      if(s1[i]!=s2[i] && s1[i+1]!=s2[i+1] && s1[i]!=s1[i+1]) {count++;i+=2;continue;}
      else if(s1[i]!=s2[i]) {count++;i++;}
      else i++;
    }
    else
    {
      if(s1[i]!=s2[i]) {count++;}
      i++;
    }
  }
  cout<<count<<endl;
  return 0;
}
