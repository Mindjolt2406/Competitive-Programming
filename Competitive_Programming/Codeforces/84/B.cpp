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
  for(int i=0;i<n/4;i++) s+="abcd";
  if(n%4==1) s+="a";
  else if(n%4==2) s+="ab";
  else if(n%4==3) s+="abc";
  cout<<s<<endl;
  return 0; 
}

