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
#define t1(x)                cerr<<#x<<": "<<x<<endl
#define t2(x, y)             cerr<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define t3(x, y, z)          cerr<<#x<<":" <<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<endl

using namespace std;

int str_to_bin(string s)
{
  int prod = 1,count = 0;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='1') count+=prod;
    prod*=2;
  }
  return count;
}

int main()
{
  string s;
  scr(s);
  string k;
  int boo = 0;
  for(int i=0;i<s.size();i++)
  {
    if(boo) {k+='1';continue;}
    if(s[i]=='0'|| s[i]=='1') k+=s[i];
    else {boo = 1;k+='1';}
  }
  cout<<str_to_bin(k)<<endl;
  return 0;
}

