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
  int c = -2;
  for(int i=0;i<n;i++) if(s[i]=='^') {c=  i; break;}
  int k = c;
  ll count1 = 0,count2 = 0,counter1 = 0,counter2 = 0;
  while(k>=0)
  {
    if(s[k]!=61&& s[k]!='^')
    {
      count1+=(s[k]-'0')*counter1;
    }
    counter1++;
    k--;
  }
  while(c<n)
  {
    if(s[c]!=61&& s[c]!='^')
    {
      count2+=(s[c]-'0')*counter2;
    }
    counter2++;
    c++;
  }
  if(count1==count2) cout<<"balance"<<endl;
  else if(count1>count2) cout<<"left"<<endl;
  else cout<<"right"<<endl; 
  return 0;
}

