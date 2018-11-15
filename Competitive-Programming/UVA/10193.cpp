#include<bits/stdc++.h>
#define mt make_tuple
#define mp make_pair
#define pu push_back
#define INF 1000000001
#define ll long long int
#define ld long double
#define vi vector<int>
#define vll vector<long long int>
#define sc(n) scanf("%d",&n);
#define scll(n) scanf("%lld",&n);
#define scld(n) scanf("%Lf",&n);
#define scr(s) {char temp[1000000];scanf("%s",temp);s = temp;}
// 10:28
using namespace std;

int convert(string s)
{
  int count = 0;
  int prod = 1;
  for(int i=s.size()-1;i>=0;i--)
  {
    if(s[i]=='1') count+=prod;
    prod*=2;
  }
  return count;
}

int gcd(int a,int b)
{
  while(b)
  {
    int c = a%b;
    a = b;
    b = c;
  }
  return a;
}

int main()
{
  int t;
  sc(t);
  for(int h=1;h<=t;h++)
  {
    string s1,s2;
    scr(s1);scr(s2);
    int count1 = convert(s1),count2 = convert(s2);
    int c = gcd(max(count1,count2),min(count1,count2));
    // cout<<count1<<" "<<count2<<" "<<c<<endl;
    if(c>1) printf("Pair #%d: All you need is love!\n",h);
    else printf("Pair #%d: Love is not all you need!\n",h);
  }
  return 0;
}
