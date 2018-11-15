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
  string s;
  scr(s);
  int n = s.size();
  int last2 = 0,last1 = 0;
  char last = '0';
  string k;
  for(int i=0;i<n;i++)
  {
    if(s[i]==last)
    {
      if(last1==1 && last2==2) continue;
      else if(last1==2) continue;
      else {k+=s[i];last1++;}
    }
    else
    {
      last = s[i];
      last2 = last1;
      last1 = 1;
      k+=s[i];
    }
  }
  cout<<k<<endl;
  return 0;
}
