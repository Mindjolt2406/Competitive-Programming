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
  int*l = (int*)calloc(26,sizeof(int));
  for(int i=0;i<s.size();i++) l[s[i]-'a']++;
  string k;
  for(int i=0;i<26;i++)
  {
    while(l[i]) {k+=i+'a';l[i]--;}
  }
  cout<<k<<endl;
  return 0;
}

