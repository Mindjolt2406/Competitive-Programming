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
  string s;
  scr(s);
  stack<char> s1;
  int count1 = 0,count2 = 0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='(' && count1<k/2) {cout<<s[i];count1++;}
    else if(s[i]==')' && count2<k/2) {cout<<s[i];count2++;}
  }
  cout<<endl;
  return 0;
}
