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
  int n,m;
  sc(n);sc(m);
  string s1,s2;
  while(n)
  {
    s1+="1";
    n--;
  }
  // string s2;
  s2 = s2+"9";
  for(int i=0;i<s1.size()-1;i++)
  {
    s2 = "8"+s2;
  }
  cout<<s1<<endl;
  cout<<s2<<endl;
  return 0;
}
